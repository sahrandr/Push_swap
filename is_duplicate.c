/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:03:42 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:21:50 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack_a, int num)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		if (temp->value == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}
