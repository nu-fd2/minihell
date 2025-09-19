/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:41:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/19 17:01:41 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

bool wildcard_match(char *pattern, char *str)
{
    if(*pattern == '\0' && *str == '\0')
        return true;
    if(*pattern == '\0')
        return false;
    if(*pattern == '*')
        return wildcard_match(pattern + 1, str) || (*str != '\0' && wildcard_match(pattern, str + 1));
    if(*str == '\0')
        return false;
    if(*pattern == *str)
        return wildcard_match(pattern + 1, str + 1);
    return false;
}

void alpha_sort(t_input *iter)
{
    t_input *iter2;
    char *tmp;
    bool swapped;

    if(!iter)
        return;
    swapped = 1;
    while(swapped == 1)
    {
        swapped = false;
        iter2 = iter;
        while(iter2)
        {
            if(iter2->next && my_strcmp(iter->value, iter2->next->value) > 0)
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

void ft_replace(t_input *add, t_input **iter, t_input **list)
{
    t_input *last;

    alpha_sort(add);
    last = ft_lstlast(add);
    if((*iter)->prev)
        (*iter)->prev->next = add;
    else
        *list = add;
    if((*iter)->next)
        (*iter)->next->prev = last;
    last->next = (*iter)->next;
    (*iter)->next = NULL;
    ft_lstfree(*iter);
    (*iter) = last;
}

void add_and_assign_token(t_input **iter, struct dirent *read, t_input **add)
{
    t_input *last;
    t_input *tmp;
    char *tmp_str;

    tmp = (*iter)->next;
    tmp_str = my_strdup((*iter)->value);
    (*iter)->next = NULL;
    (*iter) = striper((*iter));
    (*iter)->next = tmp;
    if(wildcard_match((*iter)->value, read->d_name))
    {
        ft_lstadd_back(add, my_strdup(read->d_name));
        last = ft_lstlast(*add);
        last->type = (*iter)->type;
        last->star = true;
    }
    free((*iter)->value);
    (*iter)->value = tmp_str;
}

void read_and_create(t_input **iter, int q_flag, int s_flag, t_input **list)
{
    DIR *dir;
    struct dirent *read;
    t_input *add;

    (void)q_flag;
    // (void)list;
    add = NULL;
    dir = opendir(".");
    read = readdir(dir);
    while(read)
    {
        if(read->d_name[0] == '.' || (s_flag && read->d_type != DT_DIR))
        {
            read = readdir(dir);
            continue;
        }
        add_and_assign_token(iter, read, &add);
        // if(wildcard_match((*iter)->value, read->d_name))
        //     ft_lstadd_back(&add, my_strdup(read->d_name));
        read = readdir(dir);
    }
    if(add)
        ft_replace(add, iter, list);
    closedir(dir);
}

            // printf("%s\n", read->d_name);
int ft_checker(char c, int quote_flag)
{
    if(c == '"' && quote_flag != 1)
    {
        if(quote_flag == 2)
            quote_flag = 0;
        else
            quote_flag = 2;
    }
    else if(c == '\'' && quote_flag != 2)
    {
        if(quote_flag == 1)
            quote_flag = 0;
        else
            quote_flag = 1;
    }
    return quote_flag;
}
void create_and_replace(t_input **iter, t_input **list)
{
    int i;
    int quote_flag;
    int star_flag;
    int slash_flag;
    t_input *ih;

    i = 0;
    quote_flag = 0;
    star_flag = 0;
    slash_flag = 0;
    if((*iter)->value[i] == '.')
        return;
    if((*iter)->prev)
    {
        // printf("%p\n", *iter);
        ih = (*iter)->prev;
        // printf("before star\n");
        // lst_print(ih);
        // printf("after star\n");
        // printf("%p\n", *iter);
        // printf("iter->value : %s\n", (*iter)->prev->value);
        // printf("iter->type : %d\n", ih->type);
        if(ih && ih->type)
        {
            if((*iter)->prev->type == TOKEN_HEREDOC)
                return;
        }
    }
        while((*iter)->value[i])
    {
        quote_flag = ft_checker((*iter)->value[i], quote_flag);
        if((*iter)->value[i] == '*' && quote_flag == 0)
            star_flag = 1;
        else if((*iter)->value[i] == '/' && (*iter)->value[i + 1] == '\0')
            slash_flag = 1;
        i++;
    }
    if(star_flag == 1)
        read_and_create(iter, quote_flag, slash_flag, list);
}

t_input *star_expansion(t_input *list)
{
    t_input *tmp;

    tmp = list;
    // lst_print(list);
    while(tmp->value)
    {
        // printf("\nbefore iter : %s\n", tmp->value);
        // lst_print(tmp);
        create_and_replace(&tmp, &list);
        // printf("\nafter iter : %s\n", tmp->value);
        // lst_print(tmp);
        // printf("\nlist : \n");
        // lst_print(list);
        tmp = tmp->next;
    }
    return list;
}
