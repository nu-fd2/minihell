/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:20:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	alldigit(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	lvl_env(t_data *data)
{
	t_env	*env;
	int		lvl;

	lvl = 0;
	env = grp_env(data->env, "SHLVL");
	if (!env->value)
		add_env(data->env, "SHLVL", "0", 1);
	else if (alldigit(env->value))
	{
		lvl = 1;
		add_env(data->env, "SHLVL", "1", 1);
	}
	else
	{
		lvl = ft_atoi(env->value);
		if (lvl < 0)
			add_env(data->env, "SHLVL", "0", 1);
		else
		{
			free(env->value);
			env->value = ft_itoa(lvl + 1);
		}
	}
	return (lvl);
}






