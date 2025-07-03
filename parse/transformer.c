/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:28:07 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool check_tokens(t_input *list)
{
    bool tmp;

    tmp = false;
    if(list->type == TOKEN_PIPE)
        tmp = true;
    else if(list->type == TOKEN_OR)
        tmp = true;
    else if(list->type == TOKEN_AND)
        tmp = true;
    else if(list->type == TOKEN_O_PAR)
        tmp = true;
    else if(list->type == TOKEN_C_PAR)
        tmp = true;
    else if(list->type == TOKEN_EOF)
        tmp = true;
    return tmp;
}

bool check_reds(t_input *list)
{
    bool tmp;

    tmp = false;
    if(list->type == TOKEN_L_RED)
        tmp = true;
    else if(list->type == TOKEN_R_RED)
        tmp = true;
    else if(list->type == TOKEN_HEREDOC)
        tmp = true;
    else if(list->type == TOKEN_R_APP)
        tmp = true;
    return tmp;
}

void add_string(t_short *shart, t_input *list, bool args)
{
    // int i;
    int j;
    // int k;

    // i = 0;
    j = 0;
    // k = 0;
    (void)args;
    while(list)
    {
        if(list->type == TOKEN_CMD || list->type == TOKEN_ARG)
        {
            shart->args[j] = my_strdup(list->value);
            j++;
        }
        list = list->next;
    }
}

t_size count_nodes(t_input *list, t_size nodes, t_short *shart)
{
    (void)shart;
    while(list)
    {
        if(check_reds(list))
        {
            nodes.size_red += 2;
            list = list->next->next;
        }
        else if(!check_tokens(list))
        {
            if(list->type == TOKEN_CMD)
                nodes.nodes++;
            nodes.size_cmd++;
            if(!check_reds(list))
                list = list->next;
        }
        else if(!check_reds(list))
                list = list->next;
    }
    return nodes;
}
// this function compresses the nodes to smaller pieces easier to transport
t_short *transformer(t_input *list)
{
    t_size nodes;
    t_short *shart;

    nodes.nodes = 0;
    nodes.size_cmd = 0;
    nodes.size_red = 0;
    shart = my_calloc(sizeof(t_short), 1);
    nodes = count_nodes(list, nodes, shart);
    shart->args = my_calloc(sizeof(char *), nodes.size_cmd);
    shart->reds = my_calloc(sizeof(char *), nodes.size_red);
    printf("\n nodes : %d, args : %d, reds : %d\n", nodes.nodes, nodes.size_cmd, nodes.size_red);
    int i = 0;
    while(shart->args[i])
    {
        printf("%d : %s\n", i, shart->args[i]);
        i++;
    }
    i = 0;
    while(shart->reds[i])
    {
        printf("%d : %s\n", i, shart->reds[i]);
        i++;
    }
    return NULL;
}
