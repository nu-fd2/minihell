/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_red_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:20:12 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 00:38:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	src_red(t_data *data, t_short *shart, char **red)
{
	int	ret;

	ret = 1;
	if (!red || !red[0])
		return (1);
	else if (ft_strncmp(red[0], ">", 2) == 0)
		ret = red_red(data, red[1]);
	else if (ft_strncmp(red[0], ">>", 3) == 0)
		ret = apn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<", 2) == 0)
		ret = inn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<<", 3) == 0)
	{
		data->fd2 = shart->pip[0];
		ret = 0;
	}
	return (ret);
}
