#include "push.h"

int	is_empty(t_stack *stack)
{
	if (stack->first == NULL)
		return (1);
	return (0);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*tmp;

	tmp = stack->first;
	max = stack->first->rank;
	while (tmp)
	{
		if (tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	return (max);
}

void	re_push(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (!is_empty(b))
	{
		max = find_max(b);
		pos = find_pos(b, max);
		if (pos == -1)
			return ;
		if (pos <= b->size / 2)
		{
			while (b->first->rank != max)
				rb(b);
		}
		else
		{
			while (b->first->rank != max)
				rrb(b);
		}
		pa(a, b);
	}
}

void	k_sort(t_stack *a, t_stack *b)
{
	int	threshold;
	int	delta;
	int	i;
	int	size;

	size = a->size;
	delta = size / 15 + 10;
	threshold = 0;
	while (!is_empty(a))
	{
		i = 0;
		while (i < size)
		{
			if (is_empty(a))
				break ;
			if (a->first->rank <= threshold + delta)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		threshold += delta;
	}
	re_push(a, b);
}
