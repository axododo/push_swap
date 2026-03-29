#include "push.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->size < 2)
		return ;
	tmp = stack->first;
	last = stack->first;
	stack->first = stack->first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
