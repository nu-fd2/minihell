/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:47:16 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/14 23:25:34 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool is_space(char c)
{
	return(c == ' ' || (c >= 9 && c <= 13));
}

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return(0);
	while (s[i])
		i++;
	return (i);
}

char	*my_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	str = malloc(my_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*my_strdup(const char *s1)
{
	char	*str;
	int		i;

	if(!s1)
		return NULL;
	str = malloc(my_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char *my_realloc(char *ptr, const char *new)
{
    free(ptr);
    return(my_strdup(new));
}
