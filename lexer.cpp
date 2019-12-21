//
// Created by dima on 16/12/2019.
//

#include "lexer.h"
#include <iostream>

vector<string> lexer::lex(string file) {
  vector<string> vectorString;
  std::ifstream in_file{file, ios::in};

  if (in_file.is_open()) {
    lexingTokens(vectorString, in_file);
    in_file.close();
  } else {
    throw "an error occured while opening ""fly.txt"" file";
  }

  for(string str:vectorString) {
    cout << str + ",";
  }

  return vectorString;
}

/**
 * The function accepts a vector of strings and a file and lexing the accepted file into tokens by looping and treats
 * each token as required
 * @param vectorString a vector that contains the file divided to tokens
 * @param in_file the accepted file we need to lex and parse
 */
void lexer::lexingTokens(vector<string>& vectorString, std::ifstream& in_file) {
  string line, temp = "";
  while (!in_file.eof()) {

    if (temp != "") { //put the token in the vector if it is at the end of the line
      vectorString.push_back(temp);
    }
    std::getline(in_file, line);
    temp = "";
    //iterate each line in the file
    for (std::string::iterator it = line.begin(); it != line.end(); ++it) {

      switch (*it) {
        case '(':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("(");
          temp = "";
          continue;
        case ')':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back(")");
          temp = "";
          continue;
        case ' ':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          temp = "";
          continue;
        case ',':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          temp = "";
          continue;
        case '{':vectorString.push_back("{");
          temp = "";
          continue;
        case '}':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("}");
          temp = "";
          continue;
        case '\t':temp = "";
          continue;
        case '"':
          //temp += *it;
          ++it;
          while (*it != '"') {
            temp += *it;
            ++it;
          }
          continue;
        case '/':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("/");
          temp = "";
          continue;
        case '+':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("+");
          temp = "";
          continue;
        case '-':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("-");
          temp = "";
          continue;
        case '*':
          if (temp != "") {
            vectorString.push_back(temp);
          }
          vectorString.push_back("*");
          temp = "";
          continue;

        default:;
      }
      temp += *it; //neither of the above conditions happened
    }
  }
}

