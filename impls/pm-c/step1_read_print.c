#include <stdio.h>

char* read(char* input) {
  return input;
}

char* eval(char* input) {
  return input;
}

char* print(char* input) {
  return input;
}

char* rep(char* input) {
  char* buffer = read(input);
  buffer = eval(buffer);
  buffer = print(buffer);
  return buffer;
}

int main(void) {
  char* line = NULL;
  size_t size;
  printf("user> ");
  while(getline (&line, &size, stdin) != -1) {
    char* result = rep(line);
    printf("%s", result);
    printf("user> ");
  }
  return 0;
}
