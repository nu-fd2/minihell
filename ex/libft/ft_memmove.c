/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:07:53 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/14 20:00:11 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = dst;
	s = (unsigned char *)src;
	if (d == s)
		return (dst);
	if (s < d)
		while (len-- > 0)
			*(d + len) = *(s + len);
	else
	{
		while (len > i)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dst);
}
