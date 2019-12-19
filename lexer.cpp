//
// Created by dima on 16/12/2019.
//

#include "lexer.h"
#include <iostream>
vector<string> lexer::lex(string file) {
  vector<string> vectorString;
  bool flagForQuatationMark = false;
  std::ifstream in_file{file, ios::in};
  char ch;

  if (in_file.is_open()) {
    string line, temp;
    while (!in_file.eof()) {
      if(temp != "") {
        vectorString.push_back(temp);
      }
      std::getline(in_file, line);
      temp = "";
      for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
          ch = *it;
          switch (*it) {

            case '(':vectorString.push_back(temp);
              temp = "";
              continue;
            case ')':vectorString.push_back(temp);
              temp = "";
              continue;
            case ' ':vectorString.push_back(temp);
              temp = "";
              continue;
            case ',':vectorString.push_back(temp);
              temp = "";
              continue;
            case '{':vectorString.push_back("{");
              temp = "";
              continue;
            case '}':vectorString.push_back(temp);
              vectorString.push_back("}");
              temp = "";
              continue;
            case '"':
              temp += *it;
              ++it;
              while(*it != '"') {
                temp += *it;
                ++it;
              }
                default:;
          }

        temp += *it;
      }
    }
  } else {
    throw "an error occured while opening ""fly.txt"" file";
  }

  for(string str:vectorString) {
    cout << str + ", ";
  }
  return vectorString;
}
