/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:16:19 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:28:08 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_stats *stats)
{
	swap(a);
	if (stats->print_ops)
		write(1, "sa\n", 3);
	stats->count_sa++;
	stats->total++;
}

void	sb(t_stack **b, t_stats *stats)
{
	swap(b);
	if (stats->print_ops)
		write(1, "sb\n", 3);
	stats->count_sb++;
	stats->total++;
}

void	ss(t_stack **a, t_stack **b, t_stats *stats)
{
	swap(a);
	swap(b);
	if (stats->print_ops)
		write(1, "ss\n", 3);
	stats->count_ss++;
	stats->total++;
}
