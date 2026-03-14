/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:29:59 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/07 20:29:59 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min_pos;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	size = stack_size(*stack_a);
	while (*stack_a)
	{
		min_pos = find_min_position(*stack_a);
		bring_to_top(stack_a, min_pos, size);
		pb(stack_a, stack_b);
		size--;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
