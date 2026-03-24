/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:59:32 by sahrandr          #+#    #+#             */
/*   Updated: 2026/02/07 14:42:24 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	if ((char )c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		len--;
		if (s[len] == (char )c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
