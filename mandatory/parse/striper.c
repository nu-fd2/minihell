/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:35:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/23 20:16:22 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_calculate_size(char *str)
{
	int	i;
	int	size;
	int	quote_flag;

	i = 0;
	size = 0;
	quote_flag = 0;
	while (str[i])
	{
		quote_flag = ft_checker(str[i], quote_flag);
		if ((str[i] == '"' && quote_flag != 1) || (str[i] == '\''
				&& quote_flag != 2))
		{
			i++;
			continue ;
		}
		size++;
		i++;
	}
	return (size + 1);
}

char	*tmp_assignment(char *list, int size)
{
	char	*tmp;
	int		quote_flag;

	int (i), (j);
	i = 0;
	j = 0;
	tmp = NULL;
	quote_flag = 0;
	tmp = my_calloc(size, 1);
	if (tmp == NULL)
		return (NULL);
	while (list[i])
	{
		quote_flag = ft_checker(list[i], quote_flag);
		if ((list[i] == '"' && quote_flag != 1) || (list[i] == '\''
				&& quote_flag != 2))
		{
			i++;
			continue ;
		}
		tmp[j++] = list[i++];
	}
	if (j > 0)
		return (tmp[j] = '\0', tmp);
	return (free(tmp), tmp = NULL, tmp);
}

void	remove_middle_node(t_input **list, t_input **list_tmp)
{
	t_input	*tmp;

	if ((*list_tmp)->prev)
	{
		(*list_tmp)->prev->next = (*list_tmp)->next;
		if ((*list_tmp)->next)
			(*list_tmp)->next->prev = (*list_tmp)->prev;
		tmp = (*list_tmp)->next;
		(*list_tmp)->next = NULL;
		ft_lstfree((*list_tmp));
		(*list_tmp) = tmp;
	}
	else
	{
		(*list_tmp) = (*list_tmp)->next;
		if (((*list)->next))
			(*list)->next->prev = NULL;
		tmp = (*list)->next;
		(*list)->next = NULL;
		ft_lstfree((*list));
		(*list) = tmp;
	}
}

int	remove_or_ignore(char *tmp, t_input **list_tmp)
{
	if ((*list_tmp)->star == true)
		return ((*list_tmp) = (*list_tmp)->next, free(tmp), 0);
	return (1);
}

t_input	*striper(t_input *list)
{
	char	*tmp;
	int		size;
	t_input	*list_tmp;

	tmp = NULL;
	list_tmp = list;
	while (list_tmp && list_tmp->value)
	{
		size = ft_calculate_size(list_tmp->value);
		if (size == 0 || ((list_tmp->type == TOKEN_HEREDOC)))
		{
			list_tmp = list_tmp->next->next;
			continue ;
		}
		tmp = tmp_assignment(list_tmp->value, size + 1);
		if (remove_or_ignore(tmp, &list_tmp) == 0)
			continue ;
		free(list_tmp->value);
		list_tmp->value = tmp;
		list_tmp = list_tmp->next;
	}
	return (list);
}
