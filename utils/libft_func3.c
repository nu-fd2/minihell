/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:22:32 by skully            #+#    #+#             */
/*   Updated: 2025/09/21 17:09:16 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	word_count(const char *s)
{
	int i;
	int quote;
	int words;

	i = 0;
	quote = 0;
	words = 0;
	while(s[i])
	{
		quote = ft_checker(s[i], quote);
		while(s[i] && isspace(s[i]) && quote == 0)
			i++;
		if((!is_space(s[i]) || quote != 0) && (s[i] != '"' && s[i] != '\''))
			words++;
		while(s[i] && (!is_space(s[i]) || quote != 0))
			i++;
	}
	return(words + 2);
}

char *copy_word_h(int start, int i, char *word, const char *s)
{
	int j;
	int len;

	j = 0;
	len = i - start;
	word = ft_calloc(len + 1, 1);
	if (!word)
		return (NULL);
	while(j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	return (word[len] = '\0', word);
}

char	*copy_word(const char *s, int *i)
{
	int		start;
	bool	in_quote;
	char	quote;
	char	*word;

	start = *i;
	in_quote = false;
	quote = 0;
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
			break ;
		(*i)++;
	}
	return(copy_word_h(start, *i, word, s));
}

char	**my_split(const char *s)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(char *), (word_count(s) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i])
			result[j++] = copy_word(s, &i);
	}
	if (s[0] == '\0')
	{
		result[j] = ft_strdup(s);
		j++;
	}
	result[j] = NULL;
	return (result);
}
