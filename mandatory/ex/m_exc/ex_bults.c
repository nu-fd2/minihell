/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_bults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:36:40 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 02:10:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ex_bults(t_data *data, char **arg)
{
	if (ft_strncmp(arg[0], "env", 4) == 0)
		data->exm = cmd_env(data);
	else if (ft_strncmp(arg[0], "cd", 3) == 0)
		data->exm = cmd_cd(data, &arg[1]);
	else if (ft_strncmp(arg[0], "export", 7) == 0)
		data->exm = cmd_export(data, &arg[1], NULL, NULL);
	else if (ft_strncmp(arg[0], "unset", 6) == 0)
		data->exm = cmd_unset(data, &arg[1]);
	else if (ft_strncmp(arg[0], "echo", 5) == 0)
		data->exm = cmd_echo(data, &arg[1]);
	else if (ft_strncmp(arg[0], "pwd", 4) == 0)
		data->exm = cmd_pwd(data);
	else if (ft_strncmp(arg[0], "exit", 5) == 0)
		data->exm = cmd_exit(data, &arg[1]);
	else
		return (69);
	return (0);
}

int	ex_bults_pip(t_data *data, char **arg, int bc)
{
	if (!bc)
		return (1);
	else if (bc == 1)
		return (cmd_env(data));
	else if (bc == 2)
		return (cmd_cd(data, &arg[1]));
	else if (bc == 3)
		return (cmd_export(data, &arg[1], NULL, NULL));
	else if (bc == 4)
		return (cmd_unset(data, &arg[1]));
	else if (bc == 5)
		return (cmd_echo(data, &arg[1]));
	else if (bc == 6)
		return (cmd_pwd(data));
	else if (bc == 7)
		return (cmd_exit(data, &arg[1]));
	return (1);
}

int	ex_bults_chk(char **arg)
{
	if (ft_strncmp(arg[0], "env", 4) == 0)
		return (1);
	else if (ft_strncmp(arg[0], "cd", 3) == 0)
		return (2);
	else if (ft_strncmp(arg[0], "export", 7) == 0)
		return (3);
	else if (ft_strncmp(arg[0], "unset", 6) == 0)
		return (4);
	else if (ft_strncmp(arg[0], "echo", 5) == 0)
		return (5);
	else if (ft_strncmp(arg[0], "pwd", 4) == 0)
		return (6);
	else if (ft_strncmp(arg[0], "exit", 5) == 0)
		return (7);
	return (0);
}
