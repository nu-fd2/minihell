/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_rish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:50:59 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/02 17:53:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	ex_rish(t_data *data, char **arg)
{
	int	i;
	char *cmd;

	cmd = NULL;
	i = 0;
	if (ex_synau(data, arg) != 69)
		return (0);
	cmd = ex_there(data, arg[0]);
	if (!arg[0])
		prompt_msg(data);
	else if (cmd == NULL)
	{
		ft_putstr_fd("command not found\n", data->fd);
		return (1);
	}
	else
	{
		data->chr_env = int_chr_env(data);
		data->ex = ex_cpro(data, cmd, arg);
		fre_chr_env(data->chr_env);
	}
	return (free(cmd), 0);
}
