/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prn_port_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 18:53:21 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	cp_envv(t_env *nu_env, t_env *og_env)
{
	nu_env->key = ft_strdup(og_env->key);
	nu_env->value = ft_strdup(og_env->value);
	nu_env->ported = og_env->ported;
	nu_env->next = NULL;
}

t_env	*cpy_env(t_data *data)
{
	t_env	*hd_env;
	t_env	*nu_env;
	t_env	*tm_env;
	t_env	*og_env;
	int		i;

	i = 0;
	nu_env = NULL;
	if (!data || !data->env || !data->env->key)
		return (NULL);
	og_env = data->env;
	while (og_env)
	{
		nu_env = ft_calloc(sizeof(t_env), 1);
		cp_envv(nu_env, og_env);
		if (i == 0)
			hd_env = nu_env;
		else
			tm_env->next = nu_env;
		i = 1;
		tm_env = nu_env;
		og_env = og_env->next;
	}
	return (hd_env);
}

void	swp_env(t_env *a, t_env *b)
{
	char	*tmp;
	int		port;

	port = 0;
	tmp = a->key;
	a->key = b->key;
	b->key = tmp;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	port = a->ported;
	a->ported = b->ported;
	b->ported = port;
}

t_env	*srt_env(t_data *data)
{
	t_env	*n_env;
	t_env	*c_env;
	int		s;

	n_env = cpy_env(data);
	if (!n_env)
		return (NULL);
	s = 0;
	while (!s)
	{
		s = 1;
		c_env = n_env;
		while (c_env && c_env->next)
		{
			if (c_env->next->key && (ft_strcmp(c_env->key,
						c_env->next->key) > 0))
			{
				swp_env(c_env, c_env->next);
				s = 0;
			}
			c_env = c_env->next;
		}
	}
	return (n_env);
}

int	prn_port_env(t_data *data)
{
	t_env	*h_env;
	t_env	*n_env;

	h_env = srt_env(data);
	if (!h_env)
		return (1);
	n_env = h_env;
	if (n_env == NULL)
		return (1);
	else
	{
		while (n_env != NULL)
		{
			ft_putstr_fd("declare -x ", data->fd);
			ft_putstr_fd(n_env->key, data->fd);
			if (n_env->ported == 1)
				(ft_putstr_fd("=\"", data->fd), ft_putstr_fd(n_env->value,
						data->fd), ft_putstr_fd("\"", data->fd));
			ft_putstr_fd("\n", data->fd);
			n_env = n_env->next;
		}
		fre_env(h_env);
	}
	return (0);
}
