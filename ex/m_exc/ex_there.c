/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_there.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 07:12:00 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 23:33:01 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	cln_splt(char **spltd)
{
	int	i;

	i = 0;
	while (spltd[i])
		free(spltd[i++]);
	free(spltd);
}

char	*ex_there_h(t_data *data, char **hed_path, char *n_cmd, char *cmd)
{
	char	*ult;
	char	*path;

	int (i), (s);
	i = 0;
	s = 0;
	ult = NULL;
	while (hed_path[i] && !s)
	{
		path = ft_sstrjoin(hed_path[i], n_cmd);
		if (!access(path, X_OK))
		{
			ult = ft_strdup(path);
			s = 1;
		}
		free(path);
		i++;
	}
	if (!ult)
	{
		data->exm = 127;
		m_perror(cmd, NULL, "command not found");
	}
	return (ult);
}

char	*ex_there(t_data *data, char *cmd)
{
	char	*ult;
	char	*n_cmd;
	char	*ful_path;
	char	**hed_path;

	if (!cmd)
		return (NULL);
	ult = NULL;
	ful_path = gky_env(data, "PATH");
	if (!ful_path)
		return (m_perror(cmd, NULL, "No such file or directory"), NULL);
	hed_path = ft_ssplit(ful_path, ':');
	n_cmd = ft_sstrjoin("/", cmd);
	ult = ex_there_h(data, hed_path, n_cmd, cmd);
	free(n_cmd);
	cln_splt(hed_path);
	return (ult);
}
