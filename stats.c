/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:03:15 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/21 16:30:38 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stats	*stats_store(void)
{
	static t_stats	stats;

	return (&stats);
}

t_stats	get_stats(void)
{
	return (*stats_store());
}

static void	increment_op_count(t_stats *stats, int op_type)
{
	if (op_type == SA)
		stats->count_sa++;
	else if (op_type == SB)
		stats->count_sb++;
	else if (op_type == SS)
		stats->count_ss++;
	else if (op_type == PA)
		stats->count_pa++;
	else if (op_type == PB)
		stats->count_pb++;
	else if (op_type == RA)
		stats->count_ra++;
	else if (op_type == RB)
		stats->count_rb++;
	else if (op_type == RR)
		stats->count_rr++;
	else if (op_type == RRA)
		stats->count_rra++;
	else if (op_type == RRB)
		stats->count_rrb++;
	else if (op_type == RRR)
		stats->count_rrr++;
}

void	increment_stats(int op_type)
{
	t_stats	*stats;

	stats = stats_store();
	stats->total++;
	increment_op_count(stats, op_type);
}
