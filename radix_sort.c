/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 12:58:57 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/14 14:30:03 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int max_bits;
	int i;
	int j;
	int size;

	size = stack_size(*stack_a);
	max_bits = count_bits(size);

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_size(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}