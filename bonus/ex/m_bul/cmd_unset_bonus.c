/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:48:51 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:28:04 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

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
			del_env(data, arg[i]);
		i++;
	}
	return (s);
}
