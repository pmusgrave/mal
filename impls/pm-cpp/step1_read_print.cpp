#include <string.h>

#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <locale>
#include <regex>
#include <string>

#include "printer.hpp"
#include "reader.hpp"
#include "types.hpp"

std::string read_list(Reader::Reader& reader);
std::string read_form(Reader::Reader& reader);
std::string read_atom(Reader::Reader& reader);
std::vector<std::string> tokenize(std::string buf);
Reader::Reader read_str(std::string buffer);
Reader::Reader READ(std::string input);
Reader::Reader EVAL(Reader::Reader input);
std::string PRINT(std::string input);
std::string rep(std::string input);

std::string read_list(Reader::Reader& reader) {
  std::string token = reader.next();
  std::vector<MalType::MalType> list;
  std::string form;
  while (!token.compare(")") && !token.compare("\0")) {
    //    list.push_back(read_form(reader));
    form = read_form(reader);
    token = reader.next();
  }
  return form;
}

std::string read_form(Reader::Reader& reader) {
  std::string token = reader.peek();
  switch(token.at(0)) {
  case '(':
    return read_list(reader);
    break;
  default:
    return read_atom(reader);
    break;
  }
}

std::string read_atom(Reader::Reader& reader) {
  std::string token = reader.next();
  switch (MalType::MalType::classify(token)) {
  case MalType::MalType::SYMBOL:
    return token;
    break;
  case MalType::MalType::NUMBER:
    //return std::stod(token);
    return token;
    break;
  case MalType::MalType::LIST:
    return token;
    break;
  }
}

/******************************************************************************/
// source: https://stackoverflow.com/questions/216823
// trim from start (in place)
static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}
/******************************************************************************/

std::vector<std::string> tokenize(std::string buf) {
  std::vector<std::string> tokens;
  tokens.reserve(100);
  const std::regex token_pattern(R"([\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"?|;.*|[^\s\[\]{}('"`,;)]*))");
  std::string current_token;
  auto tokens_begin = std::sregex_iterator(buf.begin(), buf.end(), token_pattern);
  auto tokens_end = std::sregex_iterator();
  for (std::sregex_iterator i = tokens_begin; i != tokens_end; ++i) {
    std::smatch match = *i;
    std::string match_str = match.str();
    std::string s(match_str);
    trim(s);
    std::cout << "trimmed: " << s << std::endl;
    tokens.push_back(s);
  }
  return tokens;
}

Reader::Reader read_str(std::string buffer) {
  std::vector<std::string> tokens = tokenize(buffer);
  Reader::Reader reader(tokens);
  read_form(reader);
  return reader;
}

Reader::Reader READ(std::string input) {
  Reader::Reader r = read_str(input);
  return r;
}

Reader::Reader EVAL(Reader::Reader input) {
  return input;
}

std::string PRINT(Reader::Reader input) {
  return input.peek();
}

std::string rep(std::string input) {
  Reader::Reader r = READ(input);
  r = EVAL(r);
  std::string output = PRINT(r);
  return output;
}

int main(void) {
  std::string input;
  std::string result;
  std::cout << "user> ";
  while (getline(std::cin, input)) {
    result = rep(input);
    std::cout << result << std::endl;
    std::cout << "user> ";
  }
  return 0;
}
