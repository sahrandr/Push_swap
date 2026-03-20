/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:51:53 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 16:52:26 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strat;
	char		**args;
	int			info[2];

	a = NULL;
	b = NULL;
	info[0] = parse_flags(argc, argv, &strat, &info[1]);
	if (info[0] == 1)
		return (0);
	if (info[0] == 2)
		args = ft_split_mod(argv[1], ' ');
	else
		args = argv + 1;
	if (!args || fill_stack(&a, args, (info[0] == 2)))
		return (1);
	sort_and_bench(&a, &b, strat, info[1]);
	if (info[0] == 2)
		free_split(args);
	return (free_stack(&a), free_stack(&b), 0);
}
