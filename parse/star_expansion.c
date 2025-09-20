/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:41:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 14:15:34 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool	wildcard_match(char *pattern, char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (true);
	if (*pattern == '\0')
		return (false);
	if (*pattern == '*')
		return (wildcard_match(pattern + 1, str) || (*str != '\0'
				&& wildcard_match(pattern, str + 1)));
	if (*str == '\0')
		return (false);
	if (*pattern == *str)
		return (wildcard_match(pattern + 1, str + 1));
	return (false);
}

void	add_and_assign_token(t_input **iter, struct dirent *read, t_input **add)
{
	t_input	*last;
	t_input	*tmp;
	char	*tmp_str;

	tmp = (*iter)->next;
	tmp_str = my_strdup((*iter)->value);
	(*iter)->next = NULL;
	(*iter) = striper((*iter));
	(*iter)->next = tmp;
	if (wildcard_match((*iter)->value, read->d_name))
	{
		ft_lstadd_back(add, my_strdup(read->d_name));
		last = ft_lstlast(*add);
		last->type = (*iter)->type;
		last->star = true;
	}
	free((*iter)->value);
	(*iter)->value = tmp_str;
}

void	read_and_create(t_input **iter, int q_flag, int s_flag, t_input **list)
{
	DIR				*dir;
	struct dirent	*read;
	t_input			*add;

	(void)q_flag;
	add = NULL;
	dir = opendir(".");
	read = readdir(dir);
	while (read)
	{
		if (read->d_name[0] == '.' || (s_flag && read->d_type != DT_DIR))
		{
			read = readdir(dir);
			continue ;
		}
		add_and_assign_token(iter, read, &add);
		read = readdir(dir);
	}
	if (add)
		ft_replace(add, iter, list);
	closedir(dir);
}

void	create_and_replace(t_input **iter, t_input **list)
{
	int	i;
	int	quote_flag;
	int	star_flag;
	int	slash_flag;

	i = 0;
	quote_flag = 0;
	star_flag = 0;
	slash_flag = 0;
	if ((*iter)->value[i] == '.')
		return ;
	if ((*iter)->type == TOKEN_HEREDOC)
		return ((void)((*iter) = (*iter)->next));
	while ((*iter)->value[i])
	{
		quote_flag = ft_checker((*iter)->value[i], quote_flag);
		if ((*iter)->value[i] == '*' && quote_flag == 0)
			star_flag = 1;
		else if ((*iter)->value[i] == '/' && (*iter)->value[i + 1] == '\0')
			slash_flag = 1;
		i++;
	}
	if (star_flag == 1)
		read_and_create(iter, quote_flag, slash_flag, list);
}

t_input	*star_expansion(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp->value)
	{
		create_and_replace(&tmp, &list);
		tmp = tmp->next;
	}
	return (list);
}
