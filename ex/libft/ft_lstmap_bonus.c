/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:29:37 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:22 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*hd;
	void	*cnt;

	hd = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cnt = f(lst->content);
		new = ft_lstnew(cnt);
		if (!new)
		{
			free (cnt);
			ft_lstclear(&hd, del);
			return (NULL);
		}
		ft_lstadd_back(&hd, new);
		lst = lst->next;
	}
	return (hd);
}
