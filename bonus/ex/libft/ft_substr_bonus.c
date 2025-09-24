/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:23:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 15:48:26 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

char	*ft_ssubstr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = ft_calloc(sizeof(char), 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, s, 1);
		return (str);
	}
	else
	{
		if (len < ft_strlen(&s[start]))
			n = len;
		else
			n = ft_strlen(&s[start]);
	}
	str = ft_calloc(sizeof(char), n + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, n + 1);
	return (str);
}
