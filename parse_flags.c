/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:00:00 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/04/05 09:13:09 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_strategy(t_strategy *strat, int *mode, t_strategy strategy)
{
	if (*mode & MODE_STRAT_SET)
		return (1);
	*strat = strategy;
	*mode |= MODE_STRAT_SET;
	return (0);
}

static int	set_flag(char *arg, t_strategy *strat, int *mode)
{
	if (!ft_strcmp(arg, "--simple"))
		return (apply_strategy(strat, mode, STRAT_SIMPLE));
	else if (!ft_strcmp(arg, "--medium"))
		return (apply_strategy(strat, mode, STRAT_MEDIUM));
	else if (!ft_strcmp(arg, "--complex"))
		return (apply_strategy(strat, mode, STRAT_COMPLEX));
	else if (!ft_strcmp(arg, "--adaptive"))
		return (apply_strategy(strat, mode, STRAT_ADAPTIVE));
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
	if (set_flag(argv[*i], s, m))
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
	*mode &= (MODE_BENCH | MODE_STRAT_SET | MODE_COUNT_ONLY);
	argv[dst] = NULL;
	return (dst);
}
