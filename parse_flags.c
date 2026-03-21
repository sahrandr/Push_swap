/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:20:00 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/21 16:29:21 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_flag(char *arg, t_strategy *strat, int *bench)
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
		*bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_strategy *strat, int *bench)
{
	int	i;
	int	dst;

	i = 1;
	dst = 1;
	*strat = STRAT_ADAPTIVE;
	*bench = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!set_flag(argv[i], strat, bench))
				return (write(2, "Error\n", 6), -1);
		}
		else
			argv[dst++] = argv[i];
		i++;
	}
	argv[dst] = NULL;
	return (dst);
}
