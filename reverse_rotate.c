/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:51 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:10:53 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*up;
	t_stack	*before_the_end;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	up = *stack;
	before_the_end = NULL;
	while (up->next)
	{
		before_the_end = up;
		up = up->next;
	}
	before_the_end->next = NULL;
	up->next = *stack;
	*stack = up;
}

void	rra(t_stack **a, t_stats *stats)
{
	reverse_rotate(a);
	if (stats->print_ops)
		write(1, "rra\n", 4);
	stats->count_rra++;
	stats->total++;
}

void	rrb(t_stack **b, t_stats *stats)
{
	reverse_rotate(b);
	if (stats->print_ops)
		write(1, "rrb\n", 4);
	stats->count_rrb++;
	stats->total++;
}

void	rrr(t_stack **a, t_stack **b, t_stats *stats)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (stats->print_ops)
		write(1, "rrr\n", 4);
	stats->count_rrr++;
	stats->total++;
}
