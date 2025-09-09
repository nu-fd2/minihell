/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:50:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/08/01 10:37:25 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_alldigit(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return 1;
		i++;
	}
	return 0;
}

int	cmd_exit(t_data *data, char **arg)
{
	int	x;
	int i;

	i = 0;
	x = data->exm;
	if (arg[0] != NULL)
	{
		if (is_alldigit(arg[0]))
		{
			x = 2;
			m_perror("exit", arg[0], "numeric argument required");
		}
		else if (arg[1] != NULL)
		{
			x = 255;
			m_perror("exit", NULL, "too many arguments");
			return (2);
		}
		else
			x = ft_atoi(arg[0]) % 256;
	}
    ft_lstfree(data->input);
    ft_lstfree_2(data->shart);
	fre_env(data->env);
	free(data);
	exit(x);
}
