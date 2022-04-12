#ifndef CODAGE
#define CODAGE
#include "tree.h"

char codage(char t);

Tree* create_table(char* t,int l);
void sort_int(int *t, int l);
void sort_node(Node **n,int l,int k);

int* init_code(Tree* t);

void print_code(int*d,char c);

void print_codage(char*s,int l);



#endif