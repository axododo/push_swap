
#include "push.h"


void indeex(t_stack *stack) {
  t_node *tmp;
  t_node *node = stack->first;
  while (node != NULL) {
    node->rank = 0;
    tmp = stack->first;
    while (tmp != NULL) {
      if(tmp->value < node->value)
        node->rank++;
      tmp = tmp->next;
    }
    node = node->next;
  }
}


t_stack *init_stack() {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->first = NULL;
    stack->size = 0;
    return stack;
}


void print_stack(t_stack *stack) {
    t_node *curr = stack->first;
    printf("[");
    while (curr) {
        printf("%d", curr->value);
        if (curr->next) printf(" ");
        curr = curr->next;
    }
    printf("]\n");
}

int main(int ac, char const *av[]) {
  t_stack stack;
  stack.first = NULL;
  stack.size = 0;
  if (ac == 1)
    return 0;
  pars((char **)av + 1, &stack);
  print_stack(&stack);
  sort_three(&stack);
  print_stack(&stack);
  return 0;
}
