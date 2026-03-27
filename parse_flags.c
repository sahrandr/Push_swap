/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:00:00 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:43:33 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_forced_strategy(char *name, t_strategy *strat)
{
	if (!ft_strcmp(name, "simple"))
		*strat = STRAT_SIMPLE;
	else if (!ft_strcmp(name, "medium"))
		*strat = STRAT_MEDIUM;
	else if (!ft_strcmp(name, "complex"))
		*strat = STRAT_COMPLEX;
	else if (!ft_strcmp(name, "adaptive"))
		*strat = STRAT_ADAPTIVE;
	else
		return (1);
	return (0);
}

static int	set_flag(char *arg, t_strategy *strat, int *mode)
{
	if (!ft_strcmp(arg, "--simple"))
		*strat = STRAT_SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		*strat = STRAT_MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		*strat = STRAT_COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		*strat = STRAT_ADAPTIVE;
	else if (!ft_strcmp(arg, "--bench"))
		*mode |= MODE_BENCH;
	else if (!ft_strcmp(arg, "--count-only"))
		*mode |= MODE_COUNT_ONLY;
	else
		return (1);
	return (0);
}

static int	handle_option(char **argv, int *i, t_strategy *s, int *m)
{
	if (!ft_strcmp(argv[*i], "--force"))
	{
		if (!argv[*i + 1] || set_forced_strategy(argv[*i + 1], s))
			return (1);
		(*i)++;
	}
	else if (set_flag(argv[*i], s, m))
		return (1);
	return (0);
}

int	parse_flags(int argc, char **argv, t_strategy *strat, int *mode)
{
	int	i;
	int	dst;

	i = 1;
	dst = 1;
	*strat = STRAT_ADAPTIVE;
	*mode = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (handle_option(argv, &i, strat, mode))
				return (write(2, "Error\n", 6), 0);
		}
		else
			argv[dst++] = argv[i];
		i++;
	}
	argv[dst] = NULL;
	return (dst);
}
