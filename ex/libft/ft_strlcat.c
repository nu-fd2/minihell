/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:44 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/15 16:12:15 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!dst && !n)
		return (ft_strlen(src));
	k = ft_strlen((const char *)dst);
	if (n < ft_strlen(dst))
		return (ft_strlen(src) + n);
	while (dst[i] && i + 1 < n)
		i++;
	while (src[j] && i + j + 1 < n)
	{
		dst[i + j] = src[j];
		j++;
		dst[i + j] = '\0';
	}
	return (k + ft_strlen(src));
}
