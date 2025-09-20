/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:24:05 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 13:45:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	lst_assign_2(t_short **new, t_short **lst)
{
	t_short	*ptr;
	t_short	*prev;

	prev = NULL;
	ptr = *lst;
	while (ptr->next)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	ptr->prev = prev;
	ptr->next = (*new);
	(*lst)->tail = ptr;
}

void	ft_lstadd_back_2(t_short **lst, t_blah blah)
{
	t_short	*new;

	new = my_calloc(sizeof(t_short), 1);
	if (new == NULL)
		return ;
	new->red_size = blah.size;
	new->args = blah.args2;
	new->reds = blah.reds2;
	new->ambiguous = blah.ambiguous;
	new->expanded = blah.expanded;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_assign_2(&new, lst);
}

t_short	*ft_lstlast_2(t_short *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstfree_2(t_short *lst)
{
	int		i;
	int		j;
	t_short	*tmp;

	while (lst)
	{
		i = 0;
		j = 0;
		tmp = lst;
		while (lst->args && lst->args[i])
			free(lst->args[i++]);
		while (lst->reds && j < lst->red_size)
			free(lst->reds[j++]);
		if (lst->args)
			free(lst->args);
		if (lst->reds)
			free(lst->reds);
		lst->args = NULL;
		lst->reds = NULL;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}
