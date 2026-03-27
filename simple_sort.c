/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:29:59 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:35:00 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	int	size;
	int	max_pos;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	size = stack_size(*stack_a);
	while (*stack_a)
	{
		max_pos = find_max_position(*stack_a);
		bring_to_top(stack_a, max_pos, size, stats);
		pb(stack_a, stack_b, stats);
		size--;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, stats);
		ra(stack_a, stats);
	}
}
