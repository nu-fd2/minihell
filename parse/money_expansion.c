/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:50:07 by skully            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void expand_and_append(t_input *list, t_flags *check, t_data *data)
{
    //append what was previously read from outside $, then read until finishing $ then append what was read, then continue reading and appending
    char *tmp;
    char *tmp2;
    char *tmp3;

    check->string = my_strnjoin(check->string, list->value + check->start, (check->end - 1) - check->start);
    check->end++;
    check->start = check->end;
    if(!my_isalpha(list->value[check->end]) && list->value[check->end] != '_')
    {
        check->string = my_strnjoin(check->string, "$", 1);
        // check->string = NULL;
        return;
    }
    while(my_isalnum(list->value[check->end]) || list->value[check->end] == '_')
        check->end++;
    tmp = my_substr(list->value, check->start, (check->end) - check->start);
    check->start = check->end;
    tmp3 = gky_env(data->env, tmp);
    if(!tmp3)
        return(free(tmp));
    tmp2 = my_strdup(tmp3);
    free(tmp);
    check->string = my_strnjoin(check->string, tmp2, my_strlen(tmp2));
    free(tmp2);
}

void node_check(t_input *list, t_flags *check, t_data *data)
{
    if(list->value[check->end] == '"' && check->quotes != 1)
    {
        if(check->quotes == 2)
            check->quotes = 0;
        else
            check->quotes = 2;
    }
    else if(list->value[check->end] == '\'' && check->quotes != 2)
    {
        if(check->quotes == 1)
            check->quotes = 0;
        else
            check->quotes = 1;
    }
    if(list->value[check->end] == '$' && check->quotes != 1)
        expand_and_append(list, check, data);
    else
        check->end++;
    if(list->value[check->end] == '\0')
        check->string = my_strnjoin(check->string, list->value + check->start, (check->end - 1) - check->start);
}

void node_mod(t_input *list, t_data *data)
{
    t_flags check;

    check.string = NULL;
    check.expand = NULL;
    check.start = 0;
    check.end = 0;
    check.d_end = 0;
    check.d_start = 0;
    check.quotes = 0;
    while(list->value[check.end])
        node_check(list, &check, data);
    free(list->value);
    list->value = check.string;
}

void free_split(char **split)
{
    int i;

    i = 0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

t_input *split_and_add(t_input **list, t_input **iter)
{
    char **tmp;
    t_input *lst_tmp;
    t_input *lst_tmp2;
    int i;

    lst_tmp = NULL;
    i = 0;
    tmp = my_split((*iter)->value);
    if(!tmp || !tmp[0] || tmp[1] == NULL)
        return(free_split(tmp) ,*list);
    while(tmp[i])
    {
        ft_lstadd_back(&lst_tmp, my_strdup(tmp[i]));
        lst_tmp2 = ft_lstlast(lst_tmp);
        lst_tmp2->type = (*iter)->type;
        i++;
    }
    free_split(tmp);
    if((*iter) != *list)
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
    return ((*iter) = lst_tmp, *list);
}

t_input *money_expansion(t_input *list, t_data *data)
{
    t_input *iter;

    iter = list;
    while(iter->value)
    {
        if(iter->type == TOKEN_HEREDOC)
        {
            iter = iter->next->next;
            continue;
        }
        node_mod(iter, data);
        list = split_and_add(&list, &iter);
        iter = iter->next;
    }
    return(list);
}

// // char *append_string(t_input *list, t_flags *check, bool dollar)
// // {
// //     if(dollar)
// //     {

// //     }
// //     else
// //     {
// //         my_strnjoin()
// //     }
// // }

// void insert_node(t_input *list, t_flags *check)
// {
//     t_input *tmp;
//     char *tmp2;

//     if(list->prev)
//     {
//         // printf("problem here......\n");
//         list->prev->next = NULL;
//         ft_lstadd_back(&(list->prev), check->string);
//         list->prev->next->next = list;
//     }
//     else
//     {
//         tmp = list->next;
//         list->next = NULL;
//         ft_lstadd_back(&list, check->string);
//         list->next->next = tmp;
//         tmp2 = list->value;
//         list->value = list->next->value;
//         list->next->value = tmp2;
//     }
// }

// void add_to_list(t_input *list, t_flags *check, char *var)
// {
//     if(!var)
//         return;
//     while(var[check->d_end])
//     {
//         if(is_space(var[check->d_end]))
//         {
//             check->expand = my_substr(var, check->d_start, check->d_end - check->d_start);
//             printf("str : %s, %d to %d => %s<-\n", check->string, check->d_start,check->d_end, check->expand);
//             check->string = my_strnjoin(check->string, check->expand, my_strlen(check->expand));
//             free(check->expand);
//             insert_node(list, check);
//             check->string = NULL;
//             while(is_space(var[check->d_end]) && var[check->d_end])
//                 check->d_end++;
//             check->d_start = check->d_end;
//         }
//         // printf("we reached the end, heres the final addition : ->%s<-\n", check->string);
//         check->d_end++;
//     }
//     if(var[check->d_end] == '\0')
//     {
//         check->expand = my_substr(var, check->d_start, check->d_end - check->d_start);
//         check->string = my_strnjoin(check->string, check->expand, my_strlen(check->expand));
//         return(free(check->expand));
//     }
// }

// void create_and_append(t_input *list, t_flags *check)
// {
//     // append what was previously read from outside $, then read inside dollar until spaces then create new node with read string
//     char *tmp;
//     char *tmp2;

//     check->string = my_strnjoin(check->string, list->value + check->start, (check->end - 1) - check->start);
//     check->end++;
//     check->start = check->end;
//     if(!my_isalpha(list->value[check->end]) && list->value[check->end] != '_')
//     {
//         check->string = my_strnjoin(check->string, "$", 1);
//         return;
//     }
//     while(my_isalnum(list->value[check->end]) || list->value[check->end] == '_')
//         check->end++;
//     tmp = my_substr(list->value, check->start, (check->end) - check->start);
//     tmp2 = getenv(tmp);
//     free(tmp);
//     check->start = check->end;
//     add_to_list(list, check, tmp2);
//     // free(tmp2);
// }

// void string_app(t_input *list, t_flags *check, bool flag)
// {
//     char *tmp;
//     tmp = check->string;
//     if(flag)
//     {
//         check->string = my_strnjoin(check->string, list->value + check->start, (check->i - 1) - check->start);
//         check->start = check->i + 1;
//     }
//     else
//         check->string = my_strnjoin(check->string, list->value + check->start, (check->i) - check->start);
//     free(tmp);
// }

// void handle_CA$H(t_input *list, t_flags *check)
// {
//     char *tmp;
//     char *tmp2;

//     check->changed = true;
//     check->i--;
//     string_app(list, check, false);
//     check->i += 2;
//     check->start = check->i;
//     if(!my_isalpha(list->value[check->i]) && list->value[check->i] != '_')
//     {
//         check->string = my_strnjoin(check->string, "$", 1);
//         check->start = check->i--;
//         return;
//     }
//     while(my_isalnum(list->value[check->i]) || list->value[check->i] == '_')
//         check->i++;
//     tmp = my_substr(list->value, check->start, (check->i) - check->start);
//     printf("\nsubstr : %s\n", tmp);
//     tmp2 = getenv(tmp);
//     check->string = my_strnjoin(check->string, tmp2, my_strlen(tmp2));
//     check->start = check->i;
//     check->i--;
//     free(tmp);
//     // free(tmp2);
// }

// void node_check(t_input *list, t_flags *check)
// {
//     if(list->value[check->i] == '"' && !check->flag_s)
//     {
//         if(check->flag_d)
//             check->flag_d = false;
//         else
//             check->flag_d = true;
//         check->changed = true;
//         string_app(list, check, true);
//     }
//     else if(list->value[check->i] == '\'' && !check->flag_d)
//     {
//         if(check->flag_s)
//             check->flag_s = false;
//         else
//             check->flag_s = true;
//         check->changed = true;
//         string_app(list, check, true);
//     }
//     if(list->value[check->i] == '$' && !check->flag_s)
//     {
//         handle_CA$H(list, check);
//     }
//     else if(list->value[check->i + 1] == '\0')
//         string_app(list, check, false);
// }
// void node_mod(t_input *list)
// {
//     t_flags check;

//     check.changed = false;
//     check.flag_d = false;
//     check.flag_s = false;
//     check.string = NULL;
//     check.start = 0;
//     check.i = 0;
//     while(list->value[check.i])
//     {
//         node_check(list, &check);
//         check.i++;
//     }
//     if(check.changed == true)
//         list->value = check.string;
// }

