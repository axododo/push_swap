#include "push.h"

void	indeex(t_stack *stack)
{
	t_node	*tmp;
	t_node	*node;

	node = stack->first;
	while (node != NULL)
	{
		node->rank = 0;
		tmp = stack->first;
		while (tmp != NULL)
		{
			if (tmp->value < node->value)
				node->rank++;
			tmp = tmp->next;
		}
		node = node->next;
	}
}

static int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp && tmp->next)
	{
		if (tmp->rank > tmp->next->rank)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char const *av[])
{
	t_stack	a;
	t_stack	b;
	char	**nums;

	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (write(2, "Error\n", 6), 1);
	a = (t_stack){0, 0};
	b = (t_stack){0, 0};
	nums = split_nums(ac, (char **)av);
	pars(nums, &a, &b, ac);
	indeex(&a);
	if (a.size > 1 && !is_sorted(&a))
	{
		if (a.size <= 3)
			sort_three(&a);
		else if (a.size <= 5)
			sort_five(&a, &b);
		else
			k_sort(&a, &b);
	}
	if (ac == 2)
		free_tab(nums);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
