/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:48:29 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/09 10:49:51 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(int index, int chunk_min, int chunk_max)
{
    if (index >= chunk_min && index <= chunk_max)
		return (1);
	return (0);
}