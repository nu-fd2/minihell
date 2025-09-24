/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:25:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:25:11 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	if (size == 0 || count == 0)
		return (ptr);
	else
		ft_bzero(ptr, count * size);
	return (ptr);
}
