
#include <stack>
#include <queue>
#include <regex>
#include "Interpreter.h"
#include "Value.h"
#include "UMinus.h"
#include "UPlus.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "ExpressionVariable.h"

Expression *Interpreter::interpret(const string &str) {
  stack<Expression *> expStack;
  // Regex matching corresponding correct syntax
  regex number("[0-9]+[.]*[0-9]*");
  regex binaryOp("[+*/-]");
  regex unaryOp("[@#]");
  regex variable("(_[0-9a-zA-Z_]*?)|([a-zA-Z]+[0-9a-zA-Z_]*)");
  // Perform infix to postfix conversion
  queue<string> postfix = ShuntingYard(str);
  while (!postfix.empty()) {
    // While postfix queue isn't empty, check the current token and create an expression out of it
    string curr = postfix.front();
    if (regex_match(curr, number))
      expStack.push(new Value(stod(curr)));

    if (regex_match(curr, variable)) {
      auto it = this->varMap.find(curr);
      // IF we don't find the variable in our assigned vars list throw an exception
      if (it == this->varMap.end())
        throw "Variable isn't defined";
      double val = stod(this->varMap.find(curr)->second);
      expStack.push(new ExpressionVariable(curr, val));
    }

    if (regex_match(curr, unaryOp)) {
      Expression *op = expStack.top();
      expStack.pop();
      // We assigned @ as Unary Minus
      if (curr == "@")
        expStack.push(new UMinus(op));
        // # is Unary Plus
      else
        expStack.push(new UPlus(op));
    }

    if (regex_match(curr, binaryOp)) {
      Expression *op1 = expStack.top();
      expStack.pop();
      Expression *op2 = expStack.top();
      expStack.pop();
      if (curr == "-")
        expStack.push(new Minus(op1, op2));
      else if (curr == "+")
        expStack.push(new Plus(op1, op2));
      else if (curr == "*")
        expStack.push(new Mul(op1, op2));
      else if (curr == "/")
        expStack.push(new Div(op1, op2));
    }
    postfix.pop();
  }
  return expStack.top();
}

void Interpreter::setVariables(const string &vars) {
  vector<string> variableTokens = tokenize(vars, ';');
  regex variable("(_[0-9a-zA-Z_]*?)|([a-zA-Z]+[0-9a-zA-Z_]*)");
  regex value("[0-9]+[.]*[0-9]*");
  // Map variables and their double values to the varMap variable.
  for (auto &variableToken : variableTokens) {
    vector<string> tokenized = tokenize(variableToken, '=');
    for (auto &var : this->varMap) {
      if (var.first == tokenized[0]) {
        var.second = tokenized[1];
        continue;
      }
    }
    if (!regex_match(tokenized[0], variable))
      throw ("Invalid Variable Format");
    if (!regex_match(tokenized[1], value))
      throw ("Invalid Variable Value Specified");
    this->varMap.insert(pair<string, string>(tokenized[0], tokenized[1]));
  }
}

queue<string> Interpreter::ShuntingYard(string str) {
  // Handles unary operators and converts them into @ for Unary minus and # for Unary plus
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == '-' || str[i] == '+') {
      if (i == 0 || str[i - 1] == '/' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '+' ||
          str[i - 1] == '(') {
        switch (str[i]) {
          case ('-'):str[i] = '@';
            break;
          case ('+'):str[i] = '#';
            break;
        }
      }
    }
  }
  // We use a stack and a queue to handle infix to postfix conversion
  queue<string> postfix;
  stack<string> s;
  // Variable recognizing regex
  regex var("(_[0-9a-zA-Z]*?)|([a-zA-Z]+[0-9]*)");
  size_t i(0);
  while (i < str.length()) {
    string tempStr(1, str[i]);
    // If number or variable, iterate through the whole expression and push into the stack
    if (isdigit(str[i]) || regex_match(tempStr, var)) {
      string tempNum;
      while ((isdigit(str[i]) || str[i] == '.' || regex_match(tempStr, var)) && i < str.length()) {
        tempNum.push_back(str[i]);
        i++;
        tempStr = str[i];
      }
      postfix.push(tempNum);
      // If it's an operator, we handle the queue and stack according to precedence.
    } else if (isOperator(tempStr)) {
      if (tempStr == "@" || tempStr == "#") {
        while (!s.empty() && precedence(s.top()) > precedence(tempStr)) {
          postfix.push(s.top());
          s.pop();
        }
      }
      while (!s.empty() && precedence(s.top()) >= precedence(tempStr)) {
        postfix.push(s.top());
        s.pop();
      }
      s.push(tempStr);
      i++;
      // Left bracket is simple push to stack
    } else if (tempStr == "(") {
      s.push(tempStr);
      i++;
      // Pop and push to queue until we hit the left bracket
    } else if (tempStr == ")") {
      while (!s.empty() && s.top() != "(") {
        postfix.push(s.top());
        s.pop();
      }
      s.pop();
      i++;
    }
  }
  while (!s.empty()) {
    postfix.push(s.top());
    s.pop();
  }
  return postfix;
}

// Precedence list for the operators, unaries are always highest priority.
int Interpreter::precedence(const string &s) {
  if (s == "@" || s == "#")
    return 3;
  if (s == "*" || s == "/")
    return 2;
  if (s == "+" || s == "-")
    return 1;
  else
    return 0;
}

// Check if the string is an operator
bool Interpreter::isOperator(const string &s) {
  return (s == "+" || s == "-" || s == "*" || s == "/" || s == "@" || s == "#");
}

// Tokenizes a string by the given delimiter using stringstream
vector<string> Interpreter::tokenize(const string &str, const char delimiter) {
  vector<string> tokens;
  string currentToken;
  istringstream tokenStream(str);
  while (getline(tokenStream, currentToken, delimiter))
    tokens.push_back(currentToken);
  return tokens;
}


