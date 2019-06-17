#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b) {
  if (*a != *b)
    return 0;

  printf("Equal!\n");
  return 1;
}

int bar() { printf("Not equal!\n"); }

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: ./hide-if num num2;\n");
    return -1;    
  }

  int a = (int)strtol(argv[1], NULL, 10), b = (int)strtol(argv[2], NULL, 10);
  foo(&a, &b) || bar();

  return 0;

}