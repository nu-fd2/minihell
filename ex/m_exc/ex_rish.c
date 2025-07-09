/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_rish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:50:59 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/09 16:24:33 by oel-mado         ###   ########.fr       */
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
	t_kids	*kids;

	cmd = NULL;
	i = 0;
	// if (!arg[0])
	// 	prompt_msg(data);
	if (!is_allspace(arg[0]))
		return (0);
	if (ex_bults(data, arg) != 69)
		return (0);
	if (arg[0][0] == '.' && arg[0][1] == '/')
		cmd = ex_crnt(data, arg[0]);
	else
		cmd = ex_there(data, arg[0]);
	// if (cmd == NULL)
	// 	prompt_msg(data);
	if (cmd == NULL)
		return (1);
	else
	{
		data->chr_env = int_chr_env(data);
		ex_cpro(data, cmd, arg);
		fre_chr_env(data->chr_env);
	}
	return (free(cmd), 0);
}
