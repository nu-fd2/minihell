/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:57 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 02:09:46 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*key_gen_h(char *key, int s, int i)
{
	if (key)
	{
		if (!ft_isalpha(key[0]) && key[0] != '_')
			s = m_perror("export", key, "not a valid identifier");
		else
		{
			while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
				i++;
			if (key[i] != '=' && key[i] != '\0')
				s = m_perror("export", key, "not a valid identifier");
		}
		if (s)
			return (free(key), NULL);
	}
	return (key);
}

char	*key_gen(char *arg)
{
	char	*key;

	int (s), (i);
	i = 0;
	s = 0;
	key = NULL;
	if (!arg)
		return (NULL);
	if (arg[0] == '=')
		return (m_perror("export", arg, "not a valid identifier"), NULL);
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	key = ft_strndup(arg, i);
	i = 0;
	return (key_gen_h(key, s, i));
}

char	*val_gen(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (NULL);
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	if (!arg[i])
		return (NULL);
	return (ft_strdup(&arg[i + 1]));
}

int	prt_gen(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	cmd_export(t_data *data, char **arg, char *key, char *val)
{
	int (i), (s), (ret);
	i = 0;
	ret = 0;
	if (!arg[0])
		return (prn_port_env(data), 0);
	while (arg[i])
	{
		key = NULL;
		val = NULL;
		key = key_gen(arg[i]);
		if (key)
		{
			s = prt_gen(arg[i]);
			val = val_gen(arg[i]);
			if (!data->env)
				data->env = add_env(data->env, key, val, s);
			else
				add_env(data->env, key, val, s);
		}
		else
			ret = 1;
		i++;
	}
	return (free(key), free(val), ret);
}
