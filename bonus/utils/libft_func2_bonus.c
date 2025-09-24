/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:59:49 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 14:27:39 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

void	*my_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*my_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = NULL;
		return (ptr);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	my_memset(ptr, '\0', size * count);
	return (ptr);
}

int	my_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
	{
		if (!s1)
			return ((unsigned char)s2[0]);
		else
			return ((unsigned char)s1[0]);
	}
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		i++;
	}
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

char	*my_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s1 && !s2)
		return (my_strdup(""));
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = malloc((my_strlen(s1) + my_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = (char)s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = (char)s2[i++];
	str[j] = '\0';
	return (free(s1), free(s2), str);
}

char	*my_strnjoin(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!s1 && !s2)
		return (my_strdup(""));
	str = malloc((my_strlen(s1) + my_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = (char)s1[i++];
	i = 0;
	while (s2 && n >= 0 && s2[i] && i <= n)
		str[j++] = (char)s2[i++];
	str[j] = '\0';
	return (free(s1), str);
}
