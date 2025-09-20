/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 13:41:09 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	syntax_error(t_token type, t_input *iter)
{
	if (type == TOKEN_PIPE)
		printf("Syntax Error near unexpected Token '|' \n");
	if (type == TOKEN_R_RED || type == TOKEN_L_RED)
	{
		if (iter->next->value == NULL)
			printf("Syntax Error near unexpected Token 'newline' \n");
		else
			printf("Syntax Error near unexpected Token '%s' \n",
				iter->next->value);
	}
	else if (type == TOKEN_R_APP || type == TOKEN_HEREDOC)
	{
		if (iter->next->value == NULL)
			printf("Syntax Error near unexpected Token 'newline' \n");
		else
			printf("Syntax Error near unexpected Token '%s' \n",
				iter->next->value);
	}
}

int	ft_quote_print(t_input *list)
{
	if (list->quotes != 0)
	{
		if (list->quotes == 1)
			return (printf("Open Single Quote Error\n"), 1);
		if (list->quotes == 2)
			return (printf("Open Double Quote Error\n"), 1);
	}
	return (0);
}

int	filter(t_input *list)
{
	t_input	*iter;

	iter = list;
	while (iter)
	{
		if (iter->type == TOKEN_PIPE && iter->next->type == TOKEN_PIPE)
			return (syntax_error(TOKEN_PIPE, iter), 1);
		if ((iter->type == TOKEN_R_RED || iter->type == TOKEN_L_RED)
			&& !(iter->next->value))
			return (syntax_error(iter->type, iter), 1);
		if ((iter->type == TOKEN_R_APP || iter->type == TOKEN_HEREDOC)
			&& !(iter->next->value))
			return (syntax_error(iter->type, iter), 1);
		if (iter->type == TOKEN_PIPE && (!(iter->prev) || !(iter->next->value)))
			return (syntax_error(iter->type, iter), 1);
		if (iter->category == TOKEN_RED_APP
			&& iter->next->category != TOKEN_WORD)
			return (syntax_error(iter->type, iter), 1);
		iter = iter->next;
	}
	return (ft_quote_print(list));
}
