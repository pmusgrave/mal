#include "reader.hpp"

#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace Reader {

Reader::Reader(std::vector<std::string> tokens) {
  this->position = 0;
  this->tokens = tokens;
}

Reader::~Reader() {}

std::string Reader::next() {
  if (this->position >= this->tokens.size())
    return "\0";  //
  return this->tokens[position++];
}

std::string Reader::peek() {
  if (this->position >= this->tokens.size())
    return "\0";  //

  /////////////////////////////////////////////////////////////////////////
  // std::vector<std::string>::iterator itr;                             //
  // for (itr = this->tokens.begin(); itr < this->tokens.end(); itr++) { //
  //   std::cout << *itr << std::endl;                                   //
  // }                                                                   //
  /////////////////////////////////////////////////////////////////////////

  return this->tokens[position];
}

}  // namespace Reader
