/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_crnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:55:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/08 15:06:55 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

char    *ex_crnt(t_data *data, char *cmd)
{
	char *ult;

	ult = NULL;
    if (access(cmd, F_OK) == -1)
        m_perror(NULL, cmd, "no such file or directory");
    else if (access(cmd, X_OK) == -1)
        m_perror(NULL, cmd, "permission denied");
    else
        ult = ft_strdup(cmd);
	return (ult);
}
