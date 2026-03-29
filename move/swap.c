/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilber <mguilber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:05:16 by mguilber          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:57 by mguilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	swap(t_stack *stack)
{
	int	tmpr;
	int	tmpv;

	if (stack->size < 2)
		return ;
	tmpr = stack->first->rank;
	tmpv = stack->first->value;
	stack->first->rank = stack->first->next->rank;
	stack->first->value = stack->first->next->value;
	stack->first->next->rank = tmpr;
	stack->first->next->value = tmpv;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
