/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:22:32 by skully            #+#    #+#             */
/*   Updated: 2025/09/15 00:23:39 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// int quote_int(char c, int quotes)
// {
//     if(c == '"' && quotes != 1)
//     {
//         if(quotes == 2)
//             quotes = 0;
//         else
//             quotes = 2;
//     }
//     else if(c == '\'' && quotes != 2)
//     {
//         if(quotes == 1)
//             quotes = 0;
//         else
//             quotes = 1;
//     }
// 	return quotes;
// }

// static size_t count_word(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;
// 	int quotes;

// 	i = 0;
// 	quotes = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		quotes = quote_int(s[i], quotes);
// 		if (quotes == 0 && s[i] != c)
// 		{
// 			while (s[i] != c && s[i])
// 			{
// 				quotes = quote_int(s[i], quotes);
// 				i++;
// 			}
// 			count++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count);
// }

// static void free_mem(char **answer, size_t count)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < count)
// 		free(answer[i++]);
// 	free(answer);
// }

// static int size_word(char const *s, char c)
// {
// 	int i;
// 	int quotes;

// 	i = 0;
// 	quotes = 0;
// 	while (s[i] != c && s[i])
// 	{
// 		quotes = quote_int(s[i], quotes);
// 		if (quotes == 0 && s[i] != c)
// 			i++;
// 		else
// 			break;
// 	}
// 	return (i);
// }

// static char **insert_word(char **answer, size_t count, char const *s, char c)
// {
// 	size_t i;
// 	size_t index;
// 	int quotes;

// 	i = 0;
// 	index = 0;
// 	quotes = 0;
// 	while (index < count)
// 	{
// 		quotes = quote_int(s[i], quotes);
// 		while (quotes == 0 && s[i] == c && s[i])
// 		{
// 			i++;
// 			if (s[i])
// 				quotes = quote_int(s[i], quotes);
// 		}
// 		if (!s[i])
// 			return (answer);
// 		if (quotes == 0)
// 		{
// 			answer[index] = my_substr(s, i, size_word(s + i, c));
// 			if (answer[index] == NULL)
// 			{
// 				free_mem(answer, index);
// 				return (NULL);
// 			}
// 			i += size_word(s + i, c);
// 			index++;
// 		}
// 		else
// 		{
// 			while (s[i] && quotes != 0)
// 			{
// 				i++;
// 				quotes = quote_int(s[i], quotes);
// 			}
// 		}
// 	}
// 	return (answer);
// }

// char	**my_split(char const *s, char c)
// {
// 	char	**answer;
// 	size_t	count;

// 	if (!s)
// 		return (NULL);
// 	count = count_word(s, c);
// 	answer = malloc(sizeof(char *) * (count + 1));
// 	if (answer == NULL)
// 		return (NULL);
// 	answer[count] = NULL;
// 	return (insert_word(answer, count, s, c));
// }
static int	word_count(const char *s)
{
	int i = 0, count = 2;
	bool in_word = false, in_quote = false;
	char quote = 0;

	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '"') && (!in_quote || s[i] == quote))
		{
			if (!in_quote)
				quote = s[i], in_quote = true;
			else
				in_quote = false;
		}
		if (!in_quote && s[i] != ' ' && !in_word)
			in_word = true, count++;
		if (!in_quote && s[i] == ' ' && in_word)
			in_word = false;
		i++;
	}
	return (count);
}

char	*copy_word(const char *s, int *i)
{
	int start = *i;
	int len = 0;
	bool in_quote = false;
	char quote = 0;

	while (s[*i])
	{
		if ((s[*i] == '\'' || s[*i] == '"') && (!in_quote || s[*i] == quote))
		{
			if (!in_quote)
				quote = s[*i], in_quote = true;
			else
				in_quote = false;
		}
		else if (!in_quote && s[*i] == ' ')
			break;
		(*i)++;
	}
	len = *i - start;
	char *word = ft_calloc(len + 1, 1);
	if (!word)
		return (NULL);
	for (int j = 0; j < len; j++)
		word[j] = s[start + j];
	return (word[len] = '\0', word);
}

char	**my_split(const char *s)
{
	char **result;
	int i = 0, j = 0;

	result = ft_calloc(sizeof(char *), (word_count(s) + 1));
	printf("word_count : %d\n", word_count(s));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			result[j++] = copy_word(s, &i);
	}
	if(s[0] == '\0')
	{
		result[j] = ft_strdup(s);
		j++;
	}
	result[j] = NULL;
	return (result);
}
