/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:47:37 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 15:47:09 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

char	*ft_sstrjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), i);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, i);
	ft_strlcat(str, (char *)s2, i);
	return (str);
}
