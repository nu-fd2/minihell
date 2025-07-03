/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:20:12 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 18:17:06 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	src_red(t_data *data, char **red)
{
	int	ret;

	ret = 0;
	if (!red || !red[0] || !red[1])
		return 1;
	else if (ft_strncmp(red[0], ">", 2) == 0)
		ret = red_red(data, red[1]);
	else if (ft_strncmp(red[0], ">>", 3) == 0)
		ret = apn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<", 2) == 0)
		ret = inn_red(data, red[1]);
	else if (ft_strncmp(red[0], "<<", 3) == 0)
	{
		printf("dogs ahead\n");
		return 1;
	}
	else
		printf("cum\n");
	return ret;
}
