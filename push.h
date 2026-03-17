#ifndef PUSH_H
  #define PUSH_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node {
  int rank;
  int value;
  struct s_node *next;
} t_node;

typedef struct s_stack {
  int size;
  t_node *first;
} t_stack;

#endif
