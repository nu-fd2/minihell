/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:09:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 14:23:59 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	alpha_sort(t_input *iter)
{
	t_input	*iter2;
	char	*tmp;
	bool	swapped;

	if (!iter)
		return ;
	swapped = 1;
	while (swapped == 1)
	{
		swapped = false;
		iter2 = iter;
		while (iter2)
		{
			if (iter2->next && my_strcmp(iter->value, iter2->next->value) > 0)
			{
				tmp = iter2->value;
				iter2->value = iter2->next->value;
				iter2->next->value = tmp;
				swapped = true;
			}
			iter2 = iter2->next;
		}
	}
}

void	ft_replace(t_input *add, t_input **iter, t_input **list)
{
	t_input	*last;

	alpha_sort(add);
	last = ft_lstlast(add);
	if ((*iter)->prev)
		(*iter)->prev->next = add;
	else
		*list = add;
	if ((*iter)->next)
		(*iter)->next->prev = last;
	last->next = (*iter)->next;
	(*iter)->next = NULL;
	ft_lstfree(*iter);
	(*iter) = last;
}

int	skip_spaces(char *line, int i)
{
	while (is_space(line[i]) && line[i])
		i++;
	return (i);
}

void	check_additionals(char *line, t_quotes *check)
{
	if (check->quotes != 1 && line[check->i] == '$')
	{
		check->expand = true;
		check->remove = check->quotes;
	}
}
