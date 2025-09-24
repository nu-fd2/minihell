/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:07:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 15:49:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	ln;
	char	*s2;

	ln = ft_strlen(s1);
	if (n < ln)
		ln = n;
	s2 = ft_calloc(sizeof(char), ln + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, ln + 1);
	return (s2);
}
