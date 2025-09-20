/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:52:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 14:26:09 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool	check_limit(char *line, t_quotes *check)
{
	if (line[(check->i)] == '"' && (check->quotes) != 1)
	{
		if (check->quotes == 2)
			check->quotes = 0;
		else
			check->quotes = 2;
	}
	else if (line[check->i] == '\'' && (check->quotes) != 2)
	{
		if (check->quotes == 1)
			check->quotes = 0;
		else
			check->quotes = 1;
	}
	check_additionals(line, check);
	if ((check->quotes != 0))
		return (false);
	if (line[check->i] == '<' || line[check->i] == '>')
		return (true);
	else if (line[check->i] == '|' || is_space(line[check->i]))
		return (true);
	return (false);
}

void	edge_check(char *line, t_quotes check, t_input **list)
{
	if (!line[check.i])
	{
		ft_lstadd_back(list, NULL);
		ft_lstlast(*list)->type = TOKEN_EOF;
	}
	(*list)->quotes = check.quotes;
}

int	handle_word(t_input **list, char *line)
{
	t_quotes	check;
	t_input		*tmp;

	check.expand = false;
	check.remove = 0;
	check.quotes = 0;
	check.i = 0;
	while (line[check.i])
	{
		if (check_limit(line, &check))
			break ;
		check.i++;
	}
	if (check.i > 0)
	{
		ft_lstadd_back(list, my_strndup(line, check.i));
		tmp = ft_lstlast(*list);
		tmp->category = TOKEN_WORD;
		tmp->expand = check.expand;
		tmp->strip = check.remove;
	}
	edge_check(line, check, list);
	return (check.i);
}

void	assign_tokens(t_input **list, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i = skip_spaces(line, i);
		i += handle_pipe(list, line + i);
		i += handle_red(list, line + i);
		i += handle_app(list, line + i);
		i += handle_word(list, line + i);
	}
}

t_input	*tokenize(char *line)
{
	t_input	*list;
	int		i;
	t_input	*tmp;

	list = NULL;
	assign_tokens(&list, line);
	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	return (list);
}
