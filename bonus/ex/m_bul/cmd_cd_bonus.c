/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:17:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/24 18:27:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	sta(char *path)
{
	struct stat	sat;

	if (!path)
		return (0);
	stat(path, &sat);
	if (!(S_ISDIR(sat.st_mode)))
		return (m_perror("cd", path, "Not a directory"));
	else if (access(path, X_OK) == -1)
		return (m_perror("cd", path, "Permission denied"));
	return (0);
}

char	*p_diddy(char *g_o)
{
	char	*pwd;
	char	*tmp;
	char	*pmt;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("");
	pmt = ft_sstrjoin(pwd, "/");
	tmp = ft_sstrjoin(pmt, g_o);
	free(pmt);
	free(pwd);
	return (tmp);
}

char	*get_nu_pwd(t_data *data, char *arg)
{
	char	*nu_pwd;

	if (!arg || arg[0] == '\0')
	{
		nu_pwd = ft_strdup(gky_env(data, "HOME"));
		if (!nu_pwd || !nu_pwd[0])
			return (NULL);
	}
	else if (arg[0] == '/')
		nu_pwd = ft_strdup(arg);
	else
		nu_pwd = p_diddy(arg);
	return (nu_pwd);
}

int	cmd_cd(t_data *data, char **arg)
{
	char	*nu_pwd;
	char	*og_pwd;

	if (!data || !data->env)
		return (1);
	nu_pwd = get_nu_pwd(data, arg[0]);
	if (!nu_pwd)
		return (m_perror("cd", arg[0], "HOME not set"));
	if (sta(arg[0]))
		return (free(nu_pwd), 1);
	og_pwd = gky_env(data, "PWD");
	if (chdir(nu_pwd))
		return (free(nu_pwd), 
			m_perror("cd", arg[0], "No such file or directory"));
	free(nu_pwd);
	nu_pwd = getcwd(NULL, 0);
	add_env(data->env, "OLDPWD", og_pwd, 1);
	add_env(data->env, "PWD", nu_pwd, 1);
	return (free(nu_pwd), 0);
}
