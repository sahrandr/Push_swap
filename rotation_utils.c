/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:52:40 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:10:53 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a, t_stats *stats)
{
	rotation(a);
	if (stats->print_ops)
		write(1, "ra\n", 3);
	stats->count_ra++;
	stats->total++;
}

void	rb(t_stack **b, t_stats *stats)
{
	rotation(b);
	if (stats->print_ops)
		write(1, "rb\n", 3);
	stats->count_rb++;
	stats->total++;
}

void	rr(t_stack **a, t_stack **b, t_stats *stats)
{
	rotation(a);
	rotation(b);
	if (stats->print_ops)
		write(1, "rr\n", 3);
	stats->count_rr++;
	stats->total++;
}
