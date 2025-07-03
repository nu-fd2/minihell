/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:29:44 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/13 01:11:27 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*run;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	run = lst;
	while (run->next != NULL)
	{
		run = run->next;
		i++;
	}
	return (i);
}
