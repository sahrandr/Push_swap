/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:00:21 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/22 11:25:01 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_bits(t_stack **stack_a, t_stack **stack_b, int bit,
		t_counter *counter)
{
	int	size;
	int	i;

	size = stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if (get_bit((*stack_a)->index, bit) == 0)
			pb(stack_a, stack_b, counter);
		else
			ra(stack_a, counter);
		i++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, counter);
	}
}
