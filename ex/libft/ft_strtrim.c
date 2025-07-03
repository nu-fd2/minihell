/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:28:39 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/12 19:33:12 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f;
	size_t	l;

	f = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1 == NULL)
		return (ft_calloc(sizeof(char), 1));
	l = ft_strlen(s1);
	if (set == NULL || !l)
		return (ft_strdup(s1));
	l--;
	while (s1[f] && ft_strchr(set, s1[f]))
		f++;
	while (l > f && ft_strrchr(set, s1[l]))
		l--;
	return (ft_substr(s1, f, l - f + 1));
}
