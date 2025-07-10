/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_bults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:36:40 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/10 22:39:08 by oel-mado         ###   ########.fr       */
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
		data->exm = cmd_export(data, &arg[1]);
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
	return 0;
}
