/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:07:05 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/07 19:08:14 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int dog_red(t_data *data, char *red)
{
	int neo;

	neo = -1;
	if (access(red, F_OK) == -1)
	{
		ft_putstr_fd(red, 2);
		ft_putstr_fd(" not found\n", 2);
		return 1;
	}
	else if (access(red, R_OK) == -1)
	{
		write(2, "Permission denied\n", 19);
		return 1;
	}
	else
		neo = open(red, O_RDONLY);
	data->fd2 = neo;
	return 0;
}
