/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:38:53 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 18:18:38 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	man_red(t_data *data, char **red)
{
	int	i;
	int	ret;

	i = 0;
	while (red[i])
	{
		ret = src_red(data, &red[i]);
		i += 2;
		if (ret)
			return 1;
	}
	return ret;
}
