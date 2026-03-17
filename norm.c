#include "push.h"

void index(t_stack *stack) {
  int i = 0;
  int j = 0;
  t_node *tmp;
  t_node *node = stack->first;
  while (node != NULL) {
    node->rank = 0;
    tmp = stack->first
    while (tmp != NULL) {
      if(tmp->value < node->value)
        node->rank++;
      tmp = tmp->next
    }
    node = node->next
  }
}
