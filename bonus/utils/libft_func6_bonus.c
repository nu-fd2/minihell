/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func6_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:22:51 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/24 18:22:52 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

int	my_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	my_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	my_isalnum(int c)
{
	return ((my_isalpha(c)) || (my_isdigit(c)));
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	int		j;
	size_t	i;
	char	*str;
	size_t	size;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	size = my_strlen(s);
	if (start > size)
		return (my_strdup(""));
	if (len > size - start)
		len = size - start;
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] && i < (start + len))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
