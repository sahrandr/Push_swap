/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:01:51 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/08 14:11:59 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)//un peux comme une carte d'intenditer
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;//c'est le nbr
	new_node->index = -1;//son index par defaut
	new_node->next = NULL;//nbr en dessous
	new_node->prev = NULL;//nbr au dessus
	return (new_node);
}
