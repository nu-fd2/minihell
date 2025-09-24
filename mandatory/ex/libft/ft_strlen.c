/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:08 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 15:47:19 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

size_t	ft_strlen(const char *who)
{
	size_t	ask;

	ask = 0;
	if (!who)
		return (0);
	while (who[ask])
		ask++;
	return (ask);
}
