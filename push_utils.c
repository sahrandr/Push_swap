/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:16:48 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:10:53 by mny-aro-         ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b, t_stats *stats)
{
	push(b, a);
	if (stats->print_ops)
		write(1, "pa\n", 3);
	stats->count_pa++;
	stats->total++;
}

void	pb(t_stack **a, t_stack **b, t_stats *stats)
{
	push(a, b);
	if (stats->print_ops)
		write(1, "pb\n", 3);
	stats->count_pb++;
	stats->total++;
}
