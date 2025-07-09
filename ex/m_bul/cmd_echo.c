/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:35:49 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/09 06:48:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	prn_all(int fd, char **arg)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (arg[i])
	{
		if (s == 1)
			ft_putstr_fd(" ", fd);
		ft_putstr_fd(arg[i++], fd);
		s = 1;
	}
}

int	cmd_echo(t_data *data, char **arg)
{
	int (i), (n);
	i = 0;
	n = 0;
	if (!data || !arg)
		return (1);
	if (!arg[0])
	{
		ft_putstr_fd("\n", data->fd);
		return (0);
	}
	if (arg[0][i++] == '-')
	{
		while (arg[0][i] == 'n')
		{
			i++;
			if (arg[0][i] == '\0')
				n = 1;
		}
	}
	if (arg[n])
		prn_all(data->fd, &arg[n]);
	if (!n)
		ft_putstr_fd("\n", data->fd);
	return (0);
}
