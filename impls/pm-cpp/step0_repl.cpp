#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

std::string READ(std::string input) {
  return input;
}

std::string EVAL(std::string input) {
  return input;
}

std::string PRINT(std::string input) {
  return input;
}

std::string rep(std::string input) {
  std::string buffer;
  buffer = READ(input);
  buffer = EVAL(input);
  buffer = PRINT(input);
  return buffer;
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
