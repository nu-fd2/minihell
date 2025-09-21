/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:29:01 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/21 17:33:08 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	lst_print(t_input *bruh)
{
	char	*data;
	t_input *head;
	// t_input *og;
	int	size;

	// og = head;
	head = bruh;
	size = 0;
	if (!head)
		printf("\033[1;31mhead 5awi a zmr\033[0m\n");
	while (head)
	{
		size++;
		data = head->value;
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
		if(head->expand)
			printf("\033[1;31m EXPANDABLE! \033[0m");
		printf(" : \033[1;36m%s\033[0m", data);
		printf("\033[1;37m -> \033[0m");
		head = head->next;
	}
	printf("\033[1;35mNULL\033[0m");
	printf("\033[1;33m %d\033[0m\n", size);
}
void lst_print2(t_short *list)
{
	int i;
	while(list)
	{
		if(list->next == NULL)
		{
			if(list->args)
			{
				i = 0;
				if(list->ambiguous == true)
					printf("\e[1;34m└───\e[0m\e[1;31m[\e[0m\e[1;36mAmbiguous!\e[0m \e[1;31m| %s]\e[0m", list->args[0]);
				else
					printf("\e[1;34m└───\e[0m\e[1;31m[%s]\e[0m", list->args[0]);
				printf("    \e[1;34m\n     │\e[0m\e[1;35mcmd+args\e[0m\n");
				printf("    \e[1;34m ├──\e[0m");
				while(list->args[i])
				{
					if (list->args[i][0])
						printf("\e[1;31m─\e[0m\e[1;31m[%s]\e[0m", list->args[i]);
					else
						printf("\e[1;31m─\e[0m\e[1;31m[NULL]\e[0m");
					i++;
				}
			}
			else
			{
				printf("\e[1;34m└───\e[0m\e[1;31m[NULL]\e[0m");
				printf("    \e[1;34m\n     │\e[0m\e[1;35mcmd+args\e[0m\n");
				printf("    \e[1;34m ├──\e[0m");
			}
			if(list->reds)
			{
				printf("\n\e[1;34m     │\e[0m\e[1;36mRedirects\e[0m\n");
				printf("    \e[1;34m └──\e[0m");
				i = 0;
				while(list->reds[i])
				{
					printf("\e[1;34m─\e[0m\e[1;31m[%s]\e[0m", list->reds[i]);
					i++;
				}
				printf("\n");
			}
			else
			{
				printf("\n\e[1;34m     │\e[0m\e[1;36mRedirects\e[0m\n");
				printf("    \e[1;34m └──\e[0m");
				printf("\n");
			}
			list = list->next;
			continue;
		}
		if(list->args)
		{
			i = 0;
			printf("\e[1;34m├───\e[0m\e[1;31m[%s]\e[0m", list->args[0]);
			printf("    \e[1;34m\n│     │\e[0m\e[1;35mcmd+args\e[0m\n");
			printf("\e[1;34m│\e[0m");
			printf("    \e[1;34m ├──\e[0m");
			while(list->args[i])
			{
				printf("\e[1;31m─\e[0m\e[1;31m[%s]\e[0m", list->args[i]);
				i++;
			}
		}
		else
		{
			printf("\e[1;34m├───\e[0m\e[1;31m[NULL]\e[0m");
			printf("    \e[1;34m\n│     │\e[0m\e[1;35mcmd+args\e[0m\n");
			printf("\e[1;34m│\e[0m");
			printf("    \e[1;34m ├──\e[0m");
		}
		if(list->reds)
		{
			printf("\n\e[1;34m│     │\e[0m\e[1;36mRedirects\e[0m\n");
			printf("\e[1;34m│\e[0m");
			printf("    \e[1;34m └──\e[0m");
			i = 0;
			while(list->reds[i])
			{
				printf("\e[1;34m─\e[0m\e[1;31m[%s]\e[0m", list->reds[i]);
				i++;
			}
			printf("\n");
		}
		else
		{
			printf("\n\e[1;34m│     │\e[0m\e[1;36mRedirects\e[0m\n");
			printf("\e[1;34m│\e[0m");
			printf("    \e[1;34m └──\e[0m");
			printf("\n");
		}
		list = list->next;
	}
}