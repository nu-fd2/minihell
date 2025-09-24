/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:38:53 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 00:00:29 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	man_red(t_data *data, t_short *shart, char **red)
{
	int	i;
	int	ret;

	i = 0;
	while (red[i])
	{
		ret = src_red(data, shart, &red[i]);
		data->exm = ret;
		i += 2;
		if (ret)
			break ;
	}
	return (ret);
}
