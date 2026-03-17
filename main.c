
#include "push.h"


void index(t_stack *stack) {
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


int main(int ac, char const *av[]) {
  t_stack stack;
  stack.first = NULL;
  stack.size = 0;
  if (ac == 1) {
    return 0;
  }

  pars(av + 1, &stack);
  return 0;
}
