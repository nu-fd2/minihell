/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "bul_cmd.h"

#include "../../includes/header.h"

char	*n_path(t_data *data, char *opeth)
{
	char *path;
	char *tmpp;
	char *home;

	tmpp = NULL;
	if (opeth[0] != '~')
	{
		path = ft_strdup(opeth);
		return (path);
	}
	home = gky_env(data->env, "HOME");
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

int cmd_cd(t_data *data, char **arg)
{
	t_env	*pwd;

	char (*tmp), (*pmt);
	if (!data || !data->env)
		return (1);
	if (!arg[0] || arg[0][0] == '\0')
	{
		pmt = getenv("HOME");
		tmp = ft_strdup(pmt);
	}
	else
		tmp = n_path(data, arg[0]);
	pwd = grp_env(data->env, "PWD");
	if (!pwd)
	{
		printf("tmp 1: %s\n", tmp);
		return (free(tmp), 1);
	}
	if (chdir(tmp))
	{
		write(2, "Error: chdir: fin ghadi??\n", 26);
		return (free(tmp), 1);
	}
	add_env(data->env, "OLDPWD", pwd->value, 1);
	add_env(data->env, "PWD", tmp, 1);
	printf("tmp 2: %s\n", tmp);
	free(tmp);
	return (0);
}
