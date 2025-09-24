/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:52:30 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 16:55:46 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	m_perror(char *cmd, char *arg, char *msg)
{
	ft_putstr_fd("ts_ahh: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
