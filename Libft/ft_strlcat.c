/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 08:24:41 by sahrandr          #+#    #+#             */
/*   Updated: 2026/02/07 15:07:44 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	b;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (size <= a)
		return (b + size);
	while (src[i] != '\0' && i < size - a - 1)
	{
		dst[a + i] = src[i];
		i = i + 1;
	}
	dst[a + i] = '\0';
	return (a + b);
}
