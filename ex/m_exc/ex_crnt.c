/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_crnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:55:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 23:09:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char	*ex_crnt(t_data *data, char *cmd)
{
	char		*ult;
	struct stat	sat;

	ult = NULL;
	stat(cmd, &sat);
	if (access(cmd, F_OK) == -1)
	{
		data->exm = 127;
		m_perror(NULL, cmd, "no such file or directory");
	}
	else if (S_ISDIR(sat.st_mode))
	{
		m_perror(NULL, cmd, "is a directory");
		data->exm = 126;
	}
	else if (access(cmd, X_OK) == -1)
	{
		m_perror(NULL, cmd, "permission denied");
		data->exm = 126;
	}
	else
		ult = ft_strdup(cmd);
	return (ult);
}
