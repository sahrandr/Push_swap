/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:53:15 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/27 15:02:51 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		do_instruction(char *line, t_stack **a, t_stack **b);
int		checker_fill_stack(t_stack **stack_a, char **args, int must_free);
char	*read_instruction(void);

#endif