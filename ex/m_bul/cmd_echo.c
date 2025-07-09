/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:35:49 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/09 15:37:01 by oel-mado         ###   ########.fr       */
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

int chk_n(char *arg)
{
	int i;

	i = 1;
	if (!arg)
		return 0;
	if (arg[0] != '-')
		return 0;
	if (arg[1] != 'n')
		return 0;
	while (arg[i])
	{
		i++;
		if (arg[i] != 'n')
			break;
	}
	if (arg[i] != '\0')
		return 0;
	return 1;
}

int	cmd_echo(t_data *data, char **arg)
{
	int (i), (j), (n);
	i = 0;
	j = 0;
	n = 0;
	if (!data || !arg)
		return (1);
	if (!arg[0])
	{
		ft_putstr_fd("\n", data->fd);
		return (0);
	}
	if (chk_n(arg[j]) == 1)
		n = 1;
	while (arg[j])
	{
		if (chk_n(arg[j]) != 1)
			break;
		j++;
	}
	if (arg[j])
		prn_all(data->fd, &arg[j]);
	if (!n)
		ft_putstr_fd("\n", data->fd);
	return (0);
}
