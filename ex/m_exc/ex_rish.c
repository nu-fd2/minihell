/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_rish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:50:59 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/04 00:06:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_allspace(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ' && !(arg[i] > 9 && arg[i] < 13))
			return 1;
		i++;
	}
	return 0;
}

int	ex_rish(t_data *data, char **arg)
{
	int	i;
	char *cmd;

	cmd = NULL;
	i = 0;
	if (if_allspace(arg[0]))
		return (0);
	if (ex_bults(data, arg) != 69)
		return (0);
	cmd = ex_there(data, arg[0]);
	if (!arg[0])
		prompt_msg(data);
	else if (cmd == NULL)
	{
		
		return (m_perror(arg[0], NULL, "command not found"));
	}
	else
	{
		data->chr_env = int_chr_env(data);
		data->ex = ex_cpro(data, cmd, arg);
		fre_chr_env(data->chr_env);
	}
	return (free(cmd), 0);
}
