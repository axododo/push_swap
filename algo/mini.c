#include "push.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->first->rank;
	mid = a->first->next->rank;
	bot = a->first->next->next->rank;
	if (top < mid && mid < bot)
		return ;
	else if (top < bot && bot < mid)
	{
		rra(a);
		sa(a);
	}
	else if (mid < top && top < bot)
		sa(a);
	else if (bot < top && top < mid)
		rra(a);
	else if (mid < bot && bot < top)
		ra(a);
	else if (bot < mid && mid < top)
	{
		sa(a);
		rra(a);
	}
}

int	push_min(t_stack *a, t_stack *b, int rank)
{
	int	i;

	i = 0;
	while (a->first->rank != rank)
	{
		i = find_pos(a, rank);
		if (i > a->size / 2)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	return (0);
}

int	find_pos(t_stack *a, int rank)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a->first;
	while (tmp != NULL)
	{
		if (tmp->rank == rank)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min(a, b, 0);
	push_min(a, b, 1);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
