/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:03:15 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 15:04:13 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stats g_stats = {0};

t_stats get_stats(void)
{
	return (g_stats);
}

void	increment_stats(int op_type)
{
    g_stats.total++;
    if (op_type == SA) g_stats.count_sa++;
    else if (op_type == SB) g_stats.count_sb++;
    else if (op_type == SS) g_stats.count_ss++;
    else if (op_type == PA) g_stats.count_pa++;
    else if (op_type == PB) g_stats.count_pb++;
    else if (op_type == RA) g_stats.count_ra++;
    else if (op_type == RB) g_stats.count_rb++;
    else if (op_type == RR) g_stats.count_rr++;
    else if (op_type == RRA) g_stats.count_rra++;
    else if (op_type == RRB) g_stats.count_rrb++;
    else if (op_type == RRR) g_stats.count_rrr++;
}