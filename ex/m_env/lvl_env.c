/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:20:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/31 01:25:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

long	ft_attol(const char *str)
{
	long	sg;
	long	nb;
	long	i;

	i = 0;
	sg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -sg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		if (nb > INT_MAX)
			return (69696969696969);
		i++;
	}
	return (nb * sg);
}

int	alldigit(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (1);
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
	long	lvl;

	lvl = 1;
	if (!data->env)
	{
		data->env = add_env(data->env, "SHLVL", "1", 1);
		return (1);
	}
	env = grp_env(data->env, "SHLVL");
	if (!env || !env->value)
		return (add_env(data->env, "SHLVL", "1", 1), 1);
	if (alldigit(env->value))
		return (add_env(data->env, "SHLVL", "1", 1), 1);
	lvl = ft_attol(env->value);
	if (lvl < 0)
		return (add_env(data->env, "SHLVL", "0", 1), 1);
	if (lvl == 69696969696969)
		return (add_env(data->env, "SHLVL", "1", 1), 1);
	lvl += 1;
	if (lvl > 999 || lvl < 0)
	{
		add_env(data->env, "SHLVL", "1", 1);
		return (m_perror("warning", NULL,
				"shell level too high, resetting to 1"));
	}
	free(env->value);
	env->value = ft_itoa((int)lvl);
	return (lvl);
}
