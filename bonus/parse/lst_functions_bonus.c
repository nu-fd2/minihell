/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:21:28 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/24 18:21:28 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

bool	ft_nb_words(char *tmp)
{
	int	i;
	int	quote;
	int	words;

	i = 0;
	quote = 0;
	words = 0;
	while (tmp[i])
	{
		quote = ft_checker(tmp[i], quote);
		while (tmp[i] && ft_is_space(tmp[i]) && quote == 0)
			i++;
		if (tmp[i] && (!ft_is_space(tmp[i]) || quote != 0) && (tmp[i] != '"'
				&& tmp[i] != '\''))
			words++;
		while (tmp[i] && (!ft_is_space(tmp[i]) || quote != 0))
			i++;
	}
	if (words != 1)
		return (true);
	return (false);
}

void	ft_remove_spaces(char *tmp)
{
	int	i;
	int	j;
	int	quote;

	i = 0;
	j = 0;
	quote = 0;
	if (!tmp || ft_nb_words(tmp))
		return ;
	while (tmp[i])
	{
		quote = ft_checker(tmp[i], quote);
		if (!ft_is_space(tmp[i]) || quote != 0)
		{
			tmp[j] = tmp[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
}

void	lst_assign(t_input **new, t_input **lst)
{
	t_input	*ptr;
	t_input	*prev;

	prev = NULL;
	ptr = *lst;
	while (ptr->next)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	ptr->prev = prev;
	if (ptr->prev)
		(*new)->index = ptr->prev->index + 1;
	ptr->next = (*new);
	(*lst)->tail = ptr;
}

void	ft_lstadd_back(t_input **lst, char *content)
{
	t_input	*new;

	new = my_calloc(sizeof(t_input), 1);
	if (new == NULL)
		return ;
	new->value = content;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_assign(&new, lst);
}

t_input	*ft_lstlast(t_input *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
