
#include "../push.h"


void sort_three(t_stack *a) {
  int top;
  int mid;

  top = a->first->rank;
  mid = a->first->next->rank;

  if (top == 0 && mid == 1)
    return;
  else if (top == 0 && mid == 2)
  {
    sa(a);
    rra(a);
  }
  else if (top == 1 && mid == 0)
    sa(a);
  else if (top == 1 && mid == 2)
    rra(a);
  else if (top == 2 && mid == 0)
    ra(a);
  else if (top == 2 && mid == 1) {
    sa(a);
    rra(a);
  }
}
