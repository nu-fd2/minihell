/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:35:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int calculate_size_blyat(char *str)
{
    int i;
    int size;
    int quote_flag;

    i = 0;
    size = 0;
    quote_flag = 0;
    while(str[i])
    {
        quote_flag = ft_checker(str[i], quote_flag);
        if((str[i] == '"' && quote_flag != 1) || (str[i] == '\'' && quote_flag != 2))
        {
            i++;
            continue;
        }
        size++;
        i++;
    }
    // printf(" size is : %d\n", dick_size);
    return(size + 1);
}

char *tmp_assignment(t_input *list, int size)
{
    int i;
    int j;
    char *tmp;
    int quote_flag;

    i = 0;
    j = 0;
    tmp = NULL;
    quote_flag = 0;
    tmp = my_calloc(size, 1);
    if(tmp == NULL)
        return NULL;
    while(list->value[i])
    {
        quote_flag = ft_checker(list->value[i], quote_flag);
        if((list->value[i] == '"'  && quote_flag != 1) || (list->value[i] == '\'' && quote_flag != 2))
        {
            i++;
            continue;
        }
        tmp[j++] = list->value[i++];
    }
    if(j > 0)
        return(tmp[j] = '\0', tmp);
    return (free(tmp) ,tmp = NULL, tmp);
}

void remove_middle_node(t_input **list, t_input **list_tmp)
{
    t_input *tmp;

    if((*list_tmp)->prev)
    {
        (*list_tmp)->prev->next = (*list_tmp)->next;
        if((*list_tmp)->next)
            (*list_tmp)->next->prev = (*list_tmp)->prev;
        tmp = (*list_tmp)->next;
        (*list_tmp)->next = NULL;
        ft_lstfree((*list_tmp));
        (*list_tmp) = tmp;
    }
    else
    {
        (*list_tmp) = (*list_tmp)->next;
        if(((*list)->next))
            (*list)->next->prev = NULL;
        tmp = (*list)->next;
        (*list)->next = NULL;
        ft_lstfree((*list));
        (*list) = tmp;
    }
}

int remove_or_ignore(char* tmp, t_input **list, t_input **list_tmp)
{   
    // if(tmp == NULL)
    //     return (remove_middle_node( list , list_tmp), 0);
    if((*list_tmp)->star == true)
        return ((*list_tmp) = (*list_tmp)->next, free(tmp), 0);
    return 1;
}

t_input *striper(t_input *list)
{
    char *tmp;
    int size;
    t_input *list_tmp;

    tmp = NULL;
    list_tmp = list;
    while(list_tmp && list_tmp->value)
    {
        size = calculate_size_blyat(list_tmp->value);
        if(size == 0 || ((list_tmp->prev && list_tmp->prev->type == TOKEN_HEREDOC)))
        {
            list_tmp = list_tmp->next;
           continue;
        }
        tmp = tmp_assignment(list_tmp, size + 1);
        if(remove_or_ignore(tmp ,&list, &list_tmp) == 0)
            continue;
        free(list_tmp->value);
        list_tmp->value = tmp;
        list_tmp = list_tmp->next;
    }
    return (list);
}
