/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:16:48 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:02 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b, t_counter *counter)
{
	push(b, a);
	write(1, "pa\n", 3);
	if (counter)
	{
		counter->total++;
		counter->pa++;
	}
}

void	pb(t_stack **a, t_stack **b, t_counter *counter)
{
	push(a, b);
	write(1, "pb\n", 3);
	if (counter)
	{
		counter->total++;
		counter->pb++;
	}
}