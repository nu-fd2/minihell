/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:22:32 by skully            #+#    #+#             */
/*   Updated: 2025/09/18 16:56:10 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

void ft_clear_empty(t_input *list)
{
	t_input *lst_tmp;

	lst_tmp = list;
    while(lst_tmp)
    {
		if(lst_tmp->type != TOKEN_FILE && lst_tmp->type != TOKEN_EOF && lst_tmp->value == NULL)
		{
			printf("before 1\n");
			remove_middle_node(&list, &lst_tmp);
			printf("after 2\n");
		}
		else
		{
			printf("before 3\n");
			lst_tmp = lst_tmp->next;
			printf("after 4\n");
		}
    }
	lst_print(list);
}
