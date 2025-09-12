/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:37:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/11 17:26:57 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	cmd_pwd(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (m_perror("pwd", "getcwd", "Error"));
	ft_putstr_fd(pwd, data->fd);
	ft_putstr_fd("\n", data->fd);
	free(pwd);
	return (0);
}
