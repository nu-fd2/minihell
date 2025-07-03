/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void syntax_error(t_token type, t_input *list, t_input *iter)
{
    if(type == TOKEN_PIPE)
        printf("Syntax Error near unexpected Token '|' \n");
    if(type == TOKEN_R_RED || type == TOKEN_L_RED)
    {
        if(iter->next->value == NULL)
            printf("Syntax Error near unexpected Token 'newline' \n");
        else
            printf("Syntax Error near unexpected Token '%s' \n", iter->next->value);
    }
    else if(type == TOKEN_R_APP || type == TOKEN_HEREDOC)
    {
        if(iter->next->value == NULL)
            printf("Syntax Error near unexpected Token 'newline' \n");
        else
            printf("Syntax Error near unexpected Token '%s' \n", iter->next->value);
    }
}

// this function manages the first level of syntax checking (words, operators, delimiters)
void filter(t_input *list)
{
    t_input *iter;

    iter = list;
    while(iter)
    {
        if(iter->type == TOKEN_PIPE && iter->next->type == TOKEN_PIPE)
            return(syntax_error(TOKEN_PIPE, list, iter));
        if((iter->type == TOKEN_R_RED || iter->type == TOKEN_L_RED) && !(iter->next->value))
            return(printf("3 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if((iter->type == TOKEN_R_APP || iter->type == TOKEN_HEREDOC) && !(iter->next->value))
            return(printf("4 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if(iter->type == TOKEN_PIPE && (!(iter->prev) || !(iter->next->value)))
            return(printf("1 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        if(iter->category == TOKEN_RED_APP && iter->next->category != TOKEN_WORD)
            return(printf("5 : %d\n", iter->index) ,syntax_error(iter->type, list, iter));
        iter = iter->next;
    }
    if(list->quotes != 0)
    {
        if(list->quotes == 1)
            printf("Open Single Quote Error\n");
        if(list->quotes == 2)
            printf("Open Double Quote Error\n");
    }
}
