/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_type_without_medium.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 10:38:42 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:25:21 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_counter *counter)
{
	float	disorder;

	if (!*a || !(*a)->next)
		return ;
	disorder = calculate_disorder(*a);
	if (disorder == 0)
		return ;
	if (disorder < 0.2)
		simple_sort(a, b, counter);
	else if (disorder < 0.5)
		medium_sort(a, b, counter);
	else
		complex_sort(a, b, counter);
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	int	bits;
	int	current_bit;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bits = count_bits(stack_size(*stack_a));
	current_bit = 0;
	while (current_bit < bits)
	{
		process_bits(stack_a, stack_b, current_bit, counter);
		current_bit++;
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	int	size;
	int	max_pos;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	size = stack_size(*stack_a);
	while (*stack_a)
	{
		max_pos = find_max_position(*stack_a);
		bring_to_top(stack_a, max_pos, size, counter);
		pb(stack_a, stack_b, counter);
		size--;
	}
	while (*stack_b)
		pa(stack_a, stack_b, counter);
}
