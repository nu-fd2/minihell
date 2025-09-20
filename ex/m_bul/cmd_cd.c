/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/20 01:55:45 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*n_path(t_data *data, char *opeth)
{
	char	*path;
	char	*tmpp;
	char	*home;

	tmpp = NULL;
	if (opeth[0] != '~')
	{
		path = ft_strdup(opeth);
		return (path);
	}
	home = gky_env(data, "HOME");
	if (!home)
		return (NULL);
	if (opeth[1] == '/')
		path = ft_sstrjoin(home, &opeth[1]);
	else
	{
		if (opeth[2] == '\0')
			tmpp = ft_strdup(home);
		else
			tmpp = ft_sstrjoin(home, "/");
		path = ft_sstrjoin(tmpp, &opeth[1]);
		free(tmpp);
	}
	return (path);
}

int	cmd_cd(t_data *data, char **arg)
{
	t_env	*pwd;

	char (*tmp), (*pmt);
	if (!data || !data->env)
		return (1);
	if (!arg[0] || arg[0][0] == '\0')
	{
		pmt = getenv("HOME");
		if (!pmt)
			return (1);
		tmp = ft_strdup(pmt);
	}
	else if (arg[1])
		return (m_perror("cd", NULL, "too many arguments"), 2);
	else
		tmp = n_path(data, arg[0]);
	pwd = grp_env(data->env, "PWD");
	if (!pwd)
		return (free(tmp), 1);
	if (chdir(tmp))
		return (m_perror("cd", tmp, "No such file or directory"), free(tmp), 1);
	add_env(data->env, "OLDPWD", pwd->value, 1);
	add_env(data->env, "PWD", tmp, 1);
	return (free(tmp), 0);
}
