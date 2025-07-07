/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_crnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:55:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/07 17:27:17 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char    *ex_crnt(t_data *data, char *cmd)
{
	char (*ful_path), (*path), (*ult), (*n_cmd);
	ult = NULL;
    // if (cmd[0] == '~' && cmd[1] == '/')
    // {
    //     ful_path = gky_env(data->env, "HOME"); 
    //     n_cmd = ft_sstrjoin(ful_path, tm);
    // }
    if (access(n_cmd, F_OK) == -1)
        m_perror(NULL, cmd, "no such file or directory");
    else if (access(n_cmd, X_OK) == -1)
        m_perror(NULL, cmd, "permission denied");
    else
        ult = ft_strdup(path);
    free(path);
	free(n_cmd);
	return (ult);
}
