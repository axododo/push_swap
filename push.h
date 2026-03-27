#ifndef PUSH_H
  #define PUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
  int rank;
  int value;
  struct s_node *next;
} t_node;

typedef struct s_stack {
  int size;
  t_node *first;
} t_stack;

void indeex(t_stack *stack);
int main(int ac, char const *av[]);
long ft_atoi(const char *nptr, int *error);
int hdup(char **nums);
int verif(char **nums);
t_node *new_node(int value);
void add_back(t_stack *stack, t_node *node);
void pars(char **nums, t_stack *stack);

void push(t_stack *src, t_stack *dst);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void rotate(t_stack *stack);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void swap(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void rev_rot(t_stack *stack);
void rra(t_stack *a) ;
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

void sort_three(t_stack *a);
#endif
