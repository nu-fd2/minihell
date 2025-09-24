/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func4_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:22:42 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/24 18:22:42 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

void	node_mod(t_input *list, t_data *data)
{
	t_flags	check;

	check.string = NULL;
	check.expand = NULL;
	check.start = 0;
	check.end = 0;
	check.d_end = 0;
	check.d_start = 0;
	check.quotes = 0;
	while (list->value[check.end])
		node_check(list, &check, data);
	free(list->value);
	list->value = check.string;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	split_and_add_h(t_input **list, t_input **iter, t_input *lst_tmp)
{
	if ((*iter) != *list)
	{
		(*iter)->prev->next = lst_tmp;
		lst_tmp->prev = (*iter)->prev;
	}
	else
		*list = lst_tmp;
	lst_tmp = ft_lstlast(lst_tmp);
	lst_tmp->next = (*iter)->next;
	(*iter)->next = NULL;
	ft_lstfree(*iter);
	*iter = NULL;
}

int	ft_checker(char c, int quote_flag)
{
	if (c == '"' && quote_flag != 1)
	{
		if (quote_flag == 2)
			quote_flag = 0;
		else
			quote_flag = 2;
	}
	else if (c == '\'' && quote_flag != 2)
	{
		if (quote_flag == 1)
			quote_flag = 0;
		else
			quote_flag = 1;
	}
	return (quote_flag);
}

void	ft_lstfree(t_input *lst)
{
	t_input	*tmp;

	while (lst)
	{
		free(lst->value);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}
