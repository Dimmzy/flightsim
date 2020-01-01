//
// Created by dima on 16/12/2019.
//

#include "lexer.h"
#include <iostream>
#include "algorithm"

vector<string> lexer::lex(const string file) {
  vector<string> vectorString;
  std::ifstream in_file{file, ios::in};

  if (in_file.is_open()) {
    lexingTokens(vectorString, in_file);
    in_file.close();
  } else {
    throw "an error occured while opening ""fly.txt"" file";
  }

  for(const string str:vectorString) {
    cout << str <<endl;
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
  string line, temp;

  while (!in_file.eof()) {
    int countBrackets = 0;
    std::size_t pos;
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
            temp = "";
          }
          countBrackets++;
          vectorString.push_back("(");
          ++it;
          // the countBrackets will control the number of brackets so we will match each open bracket to its
          // suitable closing bracket
          while (countBrackets != 0) {
            if (*it == '(') {
              countBrackets++;
            }
            if (*it == ')') {
              countBrackets--;
            }
            if (countBrackets != 0) {
              temp += *it;
              ++it;
            }
          }
          vectorString.push_back(temp);
          vectorString.push_back(")");
          temp = "";
          continue;
        case '=':
          if (temp != "") {
            vectorString.push_back(temp);
            temp = "";
          }
          vectorString.push_back("=");

          //the following 4 lines take the all the string from the '=' character to the end of the line
          ++it; //skip the space
          pos = line.find("="); //find the index of the character '=' in the line
          temp = line.substr(pos + 1, line.length() - 1); //take the all string from '=' character to the end of
          // the line
          vectorString.push_back(temp);
          temp = "";
          it = line.end() - 1; //the loop will יקדם the pointer almost to the end lf the line because the loop will תקדם
          // to the end of the line
          continue;
        case ' ':
          if (temp != "") {
            vectorString.push_back(temp);
          }

          if(temp == "while" or temp == "if") {
            temp = "";
            ++it; //skip the space character
            while(*it != '{') {
              temp += *it;
              ++it;
            }
            vectorString.push_back(temp); //in temp we have the condition
            vectorString.push_back("{");
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
        default:;
      }
      temp += *it; //neither of the above conditions happened
    }

  }
  postLexing(vectorString);
}

/**
 * the function erases spaces and '"'- characters from the tokens
 * @param vectorOfTokens the input text divided into tokens
 */
  void lexer::postLexing(std::vector<std::string> &vectorOfTokens) {
    //iterate the vector of tokens and erase unwanted '"' and spaces
    for (unsigned i = 0; i < vectorOfTokens.size(); i++) {

      if (vectorOfTokens[i][0] != '"') { //if the token is a literal sentence we dont want to erase the spaces
        vectorOfTokens[i].erase(std::remove(vectorOfTokens[i].begin(), vectorOfTokens[i].end(), ' '),
                                vectorOfTokens[i].end());
      }
      vectorOfTokens[i].erase(std::remove(vectorOfTokens[i].begin(), vectorOfTokens[i].end(), '"'),
                               vectorOfTokens[i].end());
    }
  }


