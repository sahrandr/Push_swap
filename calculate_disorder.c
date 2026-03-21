/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_disorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:48:26 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/21 15:02:44 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	int		size;
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (!stack_a || !stack_a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	size = stack_size(stack_a);
	ptr1 = stack_a;
	while (ptr1 && ptr1->next)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			total_pairs++;
			if (ptr1->value > ptr2->value)
				mistakes++;
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return ((float)mistakes / total_pairs);
}
