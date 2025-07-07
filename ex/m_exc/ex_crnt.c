/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_crnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:55:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/07 14:12:52 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char    *ex_crnt(t_data *data, char *cmd)
{
	char (*ful_path), (*path), (*ult), (*n_cmd);
	ult = NULL;
	ful_path = gky_env(data->env, "PWD");
	n_cmd = ft_sstrjoin("/", cmd);
    path = ft_sstrjoin(ful_path, n_cmd);
    free(ful_path);
    if (access(path, F_OK) == -1)
        m_perror(NULL, cmd, "no such file or directory");
    else if (access(path, X_OK) == -1)
        m_perror(NULL, cmd, "permission denied");
    else
        ult = ft_strdup(path);
    free(path);
	free(n_cmd);
	return (ult);
}
