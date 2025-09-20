/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:07:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/20 16:09:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	ln;
	char	*s2;

	ln = 1;
	if (s1)
		ln += ft_strlen(s1);
	s2 = ft_calloc(sizeof(char), ln);
	if (!s2)
		return (NULL);
	if (ln != 1)
		ft_strlcpy(s2, s1, ln);
	return (s2);
}
