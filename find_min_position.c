/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:50:20 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/09 10:36:18 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *stack)
{
    int	min_value;
    int	min_pos;
    int	current_pos;

    if (!stack)           /* Protection : stack vide */
        return (-1); 
    current_pos = 0;
    min_pos = 0;
    min_value = stack->value;
    while (stack)         /* ← CORRIGÉ : stack, pas stack->next */
    {
        if (stack->value < min_value)   /* ← CORRIGÉ : <, pas > */
        {
            min_value = stack->value;
            min_pos = current_pos;      /* ← CORRIGÉ : =, pas += */
        }
        current_pos++;
        stack = stack->next;            /* ← AJOUTÉ : avancer ! */
    }
    return (min_pos);
}
