/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	in_chk(char *key)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_')
		s = 1;
	while (!s && key[i] != '\0')
	{
	printf("\033[1;32mHii\033[0m\n");
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			s = 1;
		i++;
	}
	if (s)
	{
		ft_putstr_fd("Error: unset: tf xhad l9lawi \"", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("\"\n", 2);
	}
	return (s);
}

int	cmd_unset(t_data *data, char **arg)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (!data || !(data->env))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!arg || !arg[0] || arg[0][0] == '\0')
		return (s);
	while (arg[i])
	{
		s = in_chk(arg[i]);
		del_env(data->env, arg[i]);
		i++;
	}
	return (s);
}
