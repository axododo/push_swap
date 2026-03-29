#include "push.h"

 int	hdup(char **nums)
{
	int		j;
	int		k;
	int		error;

	j = 0;
	error = 0;
	while (nums[j])
	{
		k = j + 1;
		while (nums[k])
		{
			if (ft_atoi(nums[j], &error) == ft_atoi(nums[k], &error))
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

 int	verif(char **nums)
{
	int		i;
	int		x;

  if (!nums || !nums[0])
    return (1);
	i = 0;
	x = 0;
	while (nums[x])
	{
    if (nums[x][0] == '\0' || ((nums[x][i] == '+' || nums[x][i] == '-') &&nums[x][1] == '\0'))
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
		i = 0;
		x++;
	}
	return (0);
}

static void	error_exit(char **nums, t_stack *stack, int ac)
{
	write(2, "Error\n", 6);
	if (ac == 2)
		free_tab(nums);
	free_stack(stack);
	exit(1);
}

t_node		*new_node(int value)
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

void		add_back(t_stack *stack, t_node *node)
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

void		pars(char **nums, t_stack *stack, int ac)
{
	int		j;
	int		error;
	t_node	*node;

	error = 0;
	if (verif(nums) || hdup(nums))
		error_exit(nums, stack, ac);
	j = 0;
	while (nums[j])
	{
		node = new_node(ft_atoi(nums[j], &error));
		if (!node || error == 1)
			error_exit(nums, stack, ac);
		add_back(stack, node);
		j++;
	}
}
