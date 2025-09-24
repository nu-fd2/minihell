/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/18 01:28:45 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	prn_env(t_data *data)
{
	t_env	*n_env;

	if (!data || !data->env)
		return (1);
	n_env = data->env;
	while (n_env)
	{
		if (n_env->ported == 1)
		{
			if (n_env->key)
			{
				ft_putstr_fd(n_env->key, data->fd);
				ft_putstr_fd("=", data->fd);
				if (n_env->value)
					ft_putstr_fd(n_env->value, data->fd);
				ft_putstr_fd("\n", data->fd);
			}
		}
		n_env = n_env->next;
	}
	return (0);
}
