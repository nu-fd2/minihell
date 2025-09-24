/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:25:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:25:53 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

void	*ft_memset(void *ptr, int n, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		((unsigned char *)ptr)[i++] = (unsigned char)n;
	return (ptr);
}
