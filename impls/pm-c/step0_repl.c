#include <stdio.h>
#include "step0_repl.h"

int main(void) {
  char* line = NULL;
  size_t size;
  printf("user> ");
  while(getline (&line, &size, stdin) != -1) {
    char* result = rep(line);
    printf("%s\n", result);
    printf("user> ");
  }
  return 0;
}

char* rep(char* input) {
  char* buffer = read(input);
  buffer = eval(buffer);
  buffer = print(buffer);
  return buffer;
}

char* read(char* input) {
  return input;
}

char* eval(char* input) {
  return input;
}

char* print(char* input) {
  return input;
}
