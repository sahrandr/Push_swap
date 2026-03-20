/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:28:37 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 15:30:15 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
    int	top;
    int	mid;
    int	bot;

    top = (*a)->value;
    mid = (*a)->next->value;
    bot = (*a)->next->next->value;
    if (top > mid && mid < bot && top < bot)
        sa(a);
    else if (top > mid && mid > bot)
    {
        sa(a);
        rra(a);
    }
    else if (top > mid && mid < bot && top > bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot)
    {
        sa(a);
        ra(a);
    }
    else if (top < mid && mid > bot && top > bot)
        rra(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
    int	size;
    int	pushed;

    size = stack_size(*a);
    pushed = 0;
    while (pushed < size - 3)
    {
        if ((*a)->index < size - 3)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
    }
    sort_3(a);
    while (stack_size(*b) > 0)
        pa(a, b);
}