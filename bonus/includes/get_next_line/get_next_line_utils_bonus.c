/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:03:41 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/09 22:05:47 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ftg_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	if (size == 0 || count == 0)
		return (ptr);
	else
	{
		while (i < (count * size))
			((unsigned char *)ptr)[i++] = (unsigned char)0;
	}
	return (ptr);
}

char	*ftg_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
	{
		if (s1)
			return (ftg_strdup(s1));
		if (s2)
			return (ftg_strdup(s2));
		return (NULL);
	}
	i = ftg_strlen(s1);
	j = ftg_strlen(s2);
	k = ftg_strlen(s1) + ftg_strlen(s2) + 1;
	str = ftg_calloc(sizeof(char), k);
	if (!str)
		return (NULL);
	ftg_strlcpy(str, s1, i + 1);
	ftg_strlcpy(str + i, s2, j + 1);
	return (str);
}

size_t	ftg_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ftg_strlen(src));
	while (src[i] && i + 1 < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
		dst[i] = '\0';
	return (ftg_strlen(src));
}

size_t	ftg_strlen(const char *who)
{
	size_t	ask;

	ask = 0;
	while (who[ask])
		ask++;
	return (ask);
}

char	*ftg_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}
