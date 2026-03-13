/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:03:42 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/04 10:00:49 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack_a, int num)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)//tant que c'est pas fini
	{
		if (temp->value == num)
			return (1);// c'est vrai
		temp = temp->next;
	}
	return (0);//non
}
