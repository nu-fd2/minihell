/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:24:05 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	lst_print_2(t_input *head)
{
	char	*data;
	// t_input *og;
	int	size;

	// og = head;
	size = 0;
	if (!head)
		printf("\033[1;31mhead 5awi a zmr\033[0m\n");
	while (head)
	{
		size++;
		data = head->value;
		if (data == NULL)
			printf("\033[1;31m%s\033[0m", data);
		else
		{
			printf("\033[1;31m%d > \033[0m", head->index);
			if(head->type == TOKEN_WORD)
				printf("\033[1;34m%s\033[0m", "WORD");
			else if(head->type == TOKEN_OP)
				printf("\033[1;34m%s\033[0m", "OP");
			else if(head->type == TOKEN_CMD)
				printf("\033[1;34m%s\033[0m", "CMD");
			else if(head->type == TOKEN_ARG)
				printf("\033[1;34m%s\033[0m", "ARG");
			else if(head->type == TOKEN_FILE)
				printf("\033[1;34m%s\033[0m", "FILE");
			else if(head->type == TOKEN_R_RED)
				printf("\033[1;34m%s\033[0m", "R_RED");
			else if(head->type == TOKEN_L_RED)
				printf("\033[1;34m%s\033[0m", "L_RED");
			else if(head->type == TOKEN_R_APP)
				printf("\033[1;34m%s\033[0m", "R_APP");
			else if(head->type == TOKEN_HEREDOC)
				printf("\033[1;34m%s\033[0m", "L_APP");
			else if(head->type == TOKEN_PIPE)
				printf("\033[1;34m%s\033[0m", "PIPE");
			else if(head->type == TOKEN_O_PAR)
				printf("\033[1;34m%s\033[0m", "O_PAR");
			else if(head->type == TOKEN_C_PAR)
				printf("\033[1;34m%s\033[0m", "C_PAR");
			else if(head->type == TOKEN_AND)
				printf("\033[1;34m%s\033[0m", "AND");
			else if(head->type == TOKEN_OR)
				printf("\033[1;34m%s\033[0m", "OR");
			else if(head->type == TOKEN_EOF)
				printf("\033[1;34m%s\033[0m", "EOF");
			printf(" : \033[1;36m%s\033[0m", data);
		}
		printf("\033[1;37m -> \033[0m");
		head = head->next;
	}
	printf("\033[1;35mNULL\033[0m");
	printf("\033[1;33m %d\033[0m\n", size);
}

void lst_assign_2(t_short **new, t_short **lst)
{
	t_short	*ptr;
    t_short *prev;

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
    t_short *new;

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

void ft_lstfree_2(t_short *lst)
{
    int i;
    int j;
    t_short *tmp;

	while(lst)
	{
        i = 0;
        j = 0;
        tmp = lst;
        while(lst->args && lst->args[i])
            free(lst->args[i++]);
        while(lst->reds && j < lst->red_size)
            free(lst->reds[j++]);
		if(lst->args)
			free(lst->args);
		if(lst->reds)
			free(lst->reds);
		lst->args = NULL;
		lst->reds = NULL;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}
