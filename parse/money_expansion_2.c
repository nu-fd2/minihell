/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money_expansion_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:46:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/15 19:58:47 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_split_helper(char **tmp, t_input *lst_tmp, t_input **list,
		t_input **iter)
{
	free_split(tmp);
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
}

t_input	*split_and_add(t_input **list, t_input **iter)
{
	char	**tmp;
	t_input	*lst_tmp;
	t_input	*lst_tmp2;
	int		i;

	i = 0;
	lst_tmp = NULL;
	tmp = my_split((*iter)->value);
	if (tmp && !tmp[0])
		return (free((*iter)->value), (*iter)->value = NULL, *list);
	if (!tmp || tmp[1] == NULL)
		return (free_split(tmp), *list);
	while (tmp[i])
	{
		ft_lstadd_back(&lst_tmp, my_strdup(tmp[i]));
		lst_tmp2 = ft_lstlast(lst_tmp);
		lst_tmp2->type = (*iter)->type;
		i++;
	}
	ft_split_helper(tmp, lst_tmp, list, iter);
	return ((*iter) = lst_tmp, *list);
}

t_input	*money_expansion(t_input *list, t_data *data)
{
	t_input	*iter;

	iter = list;
	while (iter->value)
	{
		if (iter->type == TOKEN_HEREDOC)
		{
			iter = iter->next->next;
			continue ;
		}
		node_mod(iter, data);
		list = split_and_add(&list, &iter);
		iter = iter->next;
	}
	return (list);
}
