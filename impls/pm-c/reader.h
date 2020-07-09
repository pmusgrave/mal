#ifndef READER_H
#define READER_H

#define MAX_TOKEN_LEN 255
#define MAX_N_TOKENS 65536

typdef struct {
  int position;
  char tokens[MAX_N_TOKENS][MAX_TOKEN_LEN];
} reader_t;

char* next(reader_t*);
char* peek(reader_t*);
void read_str(char*);
char** tokenize(char*);
void read_form(reader_t*);
void read_list(reader_t*);
void read_atom(reader_t*);

#endif
