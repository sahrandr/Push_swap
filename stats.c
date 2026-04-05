/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:03:15 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/30 15:31:24 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stats(t_stats *stats)
{
	stats->total = 0;
	stats->count_sa = 0;
	stats->count_sb = 0;
	stats->count_ss = 0;
	stats->count_pa = 0;
	stats->count_pb = 0;
	stats->count_ra = 0;
	stats->count_rb = 0;
	stats->count_rr = 0;
	stats->count_rra = 0;
	stats->count_rrb = 0;
	stats->count_rrr = 0;
	stats->print_ops = 1;
	stats->mode = 0;
	stats->actual_strat = STRAT_ADAPTIVE;
}
