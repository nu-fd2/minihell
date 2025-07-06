/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/05 22:26:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	cmd_unset(t_data *data, char **arg)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	if (!data || !(data->env))
		return (1);
	if (!arg || !arg[0] || arg[0][0] == '\0')
		return (s);
	while (arg[i])
	{
		if (!ft_isalpha(arg[i][0]) && arg[i][0] != '_')
			s = m_perror("unset", arg[i], "not a valid identifier");
		else
			del_env(data->env, arg[i]);
		i++;
	}
	return (s);
}
