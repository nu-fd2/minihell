/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_there.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 07:12:00 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 00:15:26 by oel-mado         ###   ########.fr       */
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

char	*ex_there(t_data *data, char *cmd)
{
	char	**hed_path;

	int (s), (i);
	char (*ful_path), (*path), (*ult), (*n_cmd);
	if (!cmd)
		return (NULL);
	s = 0;
	i = 0;
	ult = NULL;
	ful_path = gky_env(data, "PATH");
	if (!ful_path)
		return (m_perror(cmd, NULL, "No such file or directory"), NULL);
	hed_path = ft_ssplit(ful_path, ':');
	n_cmd = ft_sstrjoin("/", cmd);
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
		m_perror(cmd, NULL, "command not found");
	free(n_cmd);
	cln_splt(hed_path);
	return (ult);
}
