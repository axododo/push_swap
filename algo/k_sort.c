/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilber <mguilber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:06:08 by mguilber          #+#    #+#             */
/*   Updated: 2026/03/29 16:15:11 by mguilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

int	is_empty(t_stack *stack)
{
	if (stack->first == NULL)
		return (1);
	return (0);
}

static	int	bytes_count(int i, int bytes_size)
{
	while (i > 1)
	{
		i /= 2;
		bytes_size++;
	}
	return (bytes_size);
}

static	void	rady(t_stack *a, t_stack *b, int bytes_size, int j)
{
	int	i;

	i = b->size;
	while (i && j <= bytes_size && !is_sorted(a))
	{
		if (((b->first->rank >> j) & 1) == 0)
			rb(b);
		else
			pa(a, b);
		i--;
	}
	if (is_empty(a))
		while (b->size != 0)
			pa(a, b);
}

void	radx(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	bytes_size;

	bytes_size = 0;
	i = a->size;
	bytes_size = bytes_count(i, bytes_size);
	j = -1;
	while (j <= bytes_size)
	{
		j++;
		i = a->size;
		while (i && !is_sorted(a))
		{
			if (((a->first->rank >> j) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i--;
		}
		rady(a, b, bytes_size, j + 1);
	}
	while (b->size != 0)
		pa(a, b);
}
