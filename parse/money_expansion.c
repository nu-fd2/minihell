/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:50:07 by skully            #+#    #+#             */
/*   Updated: 2025/09/23 15:32:11 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*handle_tmp2(t_data *data, t_input *list, t_flags *check)
{
	char	*tmp;
	char	*tmp3;

	tmp = my_substr(list->value, check->start, (check->end) - check->start);
	check->start = check->end;
	if (tmp[0] == '?')
		return (free(tmp), ft_itoa(data->exm));
	else
		tmp3 = gky_env(data, tmp);
	return (free(tmp), ft_strdup(tmp3));
}

void	expand_and_append(t_input *list, t_flags *check, t_data *data)
{
	char	*tmp2;

	check->string = my_strnjoin(check->string, list->value + check->start,
			(check->end - 1) - check->start);
	check->end++;
	check->start = check->end;
	if (!my_isalpha(list->value[check->end]) && list->value[check->end] != '_')
	{
		if (list->value[check->end] != '?')
			return (check->start++, (void)(check->end++));
	}
	while (my_isalnum(list->value[check->end])
		|| list->value[check->end] == '_')
		check->end++;
	if (list->value[check->end] == '?')
		check->end++;
	tmp2 = handle_tmp2(data, list, check);
	if (tmp2 == NULL)
		return ;
	check->string = my_strnjoin(check->string, tmp2, my_strlen(tmp2));
	return (free(tmp2));
}

void	node_check(t_input *list, t_flags *check, t_data *data)
{
	if (list->value[check->end] == '"' && check->quotes != 1)
	{
		if (check->quotes == 2)
			check->quotes = 0;
		else
			check->quotes = 2;
	}
	else if (list->value[check->end] == '\'' && check->quotes != 2)
	{
		if (check->quotes == 1)
			check->quotes = 0;
		else
			check->quotes = 1;
	}
	if (list->value[check->end] == '$' && check->quotes != 1)
		expand_and_append(list, check, data);
	else
		check->end++;
	if (list->value[check->end] == '\0')
		check->string = my_strnjoin(check->string, list->value + check->start,
				(check->end - 1) - check->start);
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
	free_split(tmp);
	split_and_add_h(list, iter, lst_tmp);
	return ((*iter) = lst_tmp, *list);
}

t_input	*money_expansion(t_input *list, t_data *data)
{
	t_input	*iter;

	iter = list;
	while (iter->next)
	{
		if (iter->type == TOKEN_HEREDOC)
		{
			iter = iter->next->next;
			continue ;
		}
		node_mod(iter, data);
		ft_remove_spaces(iter->value);
		list = split_and_add(&list, &iter);
		iter = iter->next;
	}
	return (list);
}
