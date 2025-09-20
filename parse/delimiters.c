/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 13:38:55 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	handle_par(t_input **list, char *line)
{
	t_input	*tmp;

	if (line[0] == '(')
	{
		ft_lstadd_back(list, my_strdup("("));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_O_PAR;
		tmp->category = TOKEN_DELIMITER;
		return (1);
	}
	else if (line[0] == ')')
	{
		ft_lstadd_back(list, my_strdup(")"));
		tmp = ft_lstlast(*list);
		tmp->type = TOKEN_C_PAR;
		tmp->category = TOKEN_DELIMITER;
		return (1);
	}
	return (0);
}

int	handle_word_quotes(t_input **list, char *line, bool s_quote, int i)
{
	while (line[i])
	{
		if (s_quote && line[i] == '\'')
			break ;
		else if (!s_quote && line[i] == '"')
			break ;
		i++;
	}
	if (!line[i])
	{
		ft_lstadd_back(list, NULL);
		ft_lstlast(*list)->type = TOKEN_EOF;
		return (i);
	}
	i++;
	ft_lstadd_back(list, my_strndup(line, i));
	ft_lstlast(*list)->category = TOKEN_WORD;
	return (i);
}

void	handle_helper(t_input **list, char *line, int *i, bool *check)
{
	if (line[(*i)] == '\'')
	{
		(*i)++;
		(*check) = true;
		(*i) = handle_word_quotes(list, line, true, *i);
	}
	if (line[(*i)] == '"')
	{
		(*i)++;
		(*check) = true;
		(*i) = handle_word_quotes(list, line, false, *i);
	}
}

int	handle_quotes(t_input **list, char *line)
{
	int		i;
	bool	check;

	i = 0;
	check = false;
	while (line[i] && !is_space(line[i]))
		handle_helper(list, line, &i, &check);
	if (check == true)
	{
		ft_lstadd_back(list, my_strndup(line, i));
		ft_lstlast(*list)->category = TOKEN_WORD;
	}
	return (i);
}
