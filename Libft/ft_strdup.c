/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:54:34 by sahrandr          #+#    #+#             */
/*   Updated: 2026/02/07 15:00:58 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	dest = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len ++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (i <= len)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
