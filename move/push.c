/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguilber <mguilber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:05:07 by mguilber          #+#    #+#             */
/*   Updated: 2026/03/29 16:14:45 by mguilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	tmp = src->first;
	src->first = src->first->next;
	tmp->next = dst->first;
	dst->first = tmp;
	dst->size++;
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
