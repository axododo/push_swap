#include "../push.h"


void rev_rot(t_stack *stack) {
  t_node *tmp;
  t_node *last;
  if(stack->size < 2)
    return;
  last = stack->first;
  while (last->next->next != NULL) {
    last = last->next;
  }
  tmp = last->next;
  last->next = NULL;
  tmp->next = stack->first;
  stack->first = tmp;
}

void rra(t_stack *a) {
    rev_rot(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b) {
    rev_rot(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b) {
    rev_rot(a);
    rev_rot(b);
    write(1, "rrr\n", 4);
}
