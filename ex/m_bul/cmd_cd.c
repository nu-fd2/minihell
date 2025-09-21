/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:47:13 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/21 23:48:51 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char *p_diddy(t_data *data, char *g_o)
{
	char *pwd;
	char *tmp;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = "";
	pwd = ft_sstrjoin(pwd, "/");
	tmp = ft_sstrjoin(pwd, g_o);
	return tmp;
}

int	cmd_cd(t_data *data, char **arg)
{
	char	*nu_pwd;
	char	*og_pwd;
	int		s;

	s = 0;
	if (!data || !data->env)
		return (1);
	if (!arg[0] || arg[0][0] == '\0')
	{
		s = 1;
		nu_pwd = ft_strdup(gky_env(data, "HOME"));
		if (!nu_pwd[0])
			return (m_perror("cd", arg[0], "HOME not set"));
	}
	else if (arg[0][0] == '/')
		nu_pwd = ft_strdup(arg[0]);
	else
		nu_pwd = p_diddy(data, arg[0]);
	og_pwd = gky_env(data, "PWD");
	if (chdir(nu_pwd))
		return (free(nu_pwd), m_perror("cd", arg[0], "No such file or directory"));
	nu_pwd = getcwd(NULL, 0);
	add_env(data->env, "OLDPWD", og_pwd, 1);
	add_env(data->env, "PWD", nu_pwd, 1);
	return (free(nu_pwd), 0);
}
