/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/27 11:38:06 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_error(t_stack **stack_a, char **args, int must_free)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (must_free)
		free_split(args);
	return (1);
}

int	fill_stack(t_stack **stack_a, char **args, int must_free)
{
	int		i;
	int		num;
	int		error;
	t_stack	*new_node;

	i = 0;
	while (args[i] != NULL)
	{
		error = (ft_isdi(args[i]) == 0);
		if (!error)
			num = ft_atoi(args[i], &error);
		if (!error && is_duplicate(*stack_a, num) == 1)
			error = 1;
		if (error)
			return (fill_error(stack_a, args, must_free));
		new_node = create_node(num);
		if (!new_node)
			return (fill_error(stack_a, args, must_free));
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (0);
}

static void	print_operations(t_stats stats)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(stats.count_sa, 2);
	ft_putstr_fd(", sb: ", 2);
	ft_putnbr_fd(stats.count_sb, 2);
	ft_putstr_fd(", ss: ", 2);
	ft_putnbr_fd(stats.count_ss, 2);
	ft_putstr_fd(", pa: ", 2);
	ft_putnbr_fd(stats.count_pa, 2);
	ft_putstr_fd(", pb: ", 2);
	ft_putnbr_fd(stats.count_pb, 2);
	ft_putstr_fd("\n[bench] ", 2);
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(stats.count_ra, 2);
	ft_putstr_fd(", rb: ", 2);
	ft_putnbr_fd(stats.count_rb, 2);
	ft_putstr_fd(", rr: ", 2);
	ft_putnbr_fd(stats.count_rr, 2);
	ft_putstr_fd(", rra: ", 2);
	ft_putnbr_fd(stats.count_rra, 2);
	ft_putstr_fd(", rrb: ", 2);
	ft_putnbr_fd(stats.count_rrb, 2);
	ft_putstr_fd(", rrr: ", 2);
	ft_putnbr_fd(stats.count_rrr, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_benchmark(t_stats stats, float disorder, t_strategy strat)
{
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strat == STRAT_ADAPTIVE)
	{
		if (stats.actual_strat == STRAT_SIMPLE)
			ft_putstr_fd("adaptive / O(n^2)\n", 2);
		else if (stats.actual_strat == STRAT_MEDIUM)
			ft_putstr_fd("adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("adaptive / O(n log n)\n", 2);
	}
	else if (strat == STRAT_SIMPLE)
		ft_putstr_fd("simple (O(n^2))\n", 2);
	else if (strat == STRAT_MEDIUM)
		ft_putstr_fd("medium O(n√n)\n", 2);
	else
		ft_putstr_fd("complex (O(n log n))\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(stats.total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	print_operations(stats);
}

void	sort_and_bench(t_stack **a, t_stack **b, t_strategy strat, int mode)
{
	float	disorder;
	t_stats	stats;

	init_stats(&stats);
	if (mode & MODE_COUNT_ONLY)
		stats.print_ops = 0;
	disorder = calculate_disorder(*a);
	if (stack_size(*a) > 1)
	{
		assign_index(*a);
		dispatch_sort(a, b, strat, &stats);
	}
	if (mode & MODE_BENCH)
		print_benchmark(stats, disorder, strat);
	if (mode & MODE_COUNT_ONLY)
	{
		ft_putnbr_fd(stats.total, 1);
		ft_putstr_fd("\n", 1);
	}
}
