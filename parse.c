#include "push.h"

int	hdup(char **nums)
{
	int		j;
	int		k;
	int		error;
	long	val_j;
	long	val_k;

	j = 0;
	while (nums[j])
	{
		error = 0;
		val_j = ft_atoi(nums[j], &error);
		if (error)
			return (1);
		k = j + 1;
		while (nums[k])
		{
			error = 0;
			val_k = ft_atoi(nums[k], &error);
			if (error)
				return (1);
			if (val_j == val_k)
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

int	verif(char **nums)
{
	int	i;
	int	x;

	if (!nums || !nums[0])
		return (1);
	x = 0;
	while (nums[x])
	{
		i = 0;
		if (nums[x][0] == '\0' || ((nums[x][i] == '+' || nums[x][i] == '-')
				&& nums[x][1] == '\0'))
			return (1);
		while (nums[x][i])
		{
			if (i == 0 && (nums[x][i] == '+' || nums[x][i] == '-'))
				i++;
			else if (nums[x][i] < '0' || nums[x][i] > '9')
				return (1);
			else
				i++;
		}
		x++;
	}
	return (0);
}

static void	error_exit(char **nums, t_stack *a, t_stack *b, int ac)
{
	write(2, "Error\n", 6);
	if (ac == 2)
		free_tab(nums);
	free_stack(a);
	free_stack(b);
	exit(1);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (stack->first == NULL)
	{
		stack->first = node;
		stack->size++;
		return ;
	}
	tmp = stack->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	stack->size++;
}

void	pars(char **nums, t_stack *a, t_stack *b, int ac)
{
	int		j;
	int		error;
	t_node	*node;

	error = 0;
	if (verif(nums) || hdup(nums))
		error_exit(nums, a, b, ac);
	j = 0;
	while (nums[j])
	{
		error = 0;
		node = new_node(ft_atoi(nums[j], &error));
		if (!node || error == 1)
			error_exit(nums, a, b, ac);
		add_back(a, node);
		j++;
	}
}
