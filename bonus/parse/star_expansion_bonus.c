/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_expansion_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:41:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/23 15:33:48 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

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

void	read_and_create(t_input **iter, t_star_h flags, t_input **list)
{
	DIR				*dir;
	struct dirent	*read;
	t_input			*add;

	add = NULL;
	dir = opendir(".");
	read = readdir(dir);
	while (read)
	{
		if (((!flags.hidden) && (read->d_name[0] == '.')) || (flags.slash_flag
				&& read->d_type != DT_DIR))
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
	t_star_h	flags;

	flags.i = 0;
	flags.quote_flag = 0;
	flags.star_flag = 0;
	flags.slash_flag = 0;
	flags.hidden = 0;
	if ((*iter)->value[flags.i] == '.')
		flags.hidden = 1;
	if ((*iter)->type == TOKEN_HEREDOC)
		return ((void)((*iter) = (*iter)->next));
	while ((*iter)->value[flags.i])
	{
		flags.quote_flag = ft_checker((*iter)->value[flags.i],
				flags.quote_flag);
		if ((*iter)->value[flags.i] == '*' && flags.quote_flag == 0)
			flags.star_flag = 1;
		else if ((*iter)->value[flags.i] == '/'
			&& (*iter)->value[flags.i + 1] == '\0')
			flags.slash_flag = 1;
		flags.i++;
	}
	if (flags.star_flag == 1)
		read_and_create(iter, flags, list);
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
