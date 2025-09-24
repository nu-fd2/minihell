/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:50:09 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 18:21:20 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_alldigit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

long long	ft_aoi(const char *str)
{
	int			i;
	int			sg;
	long long	nb;

	i = 0;
	sg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -sg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb > (LONG_MAX - (str[i] - '0')) / 10)
			return (LLONG_MAX);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sg);
}

long	get_out(char *num)
{
	long long	ts;

	ts = 0;
	ts = ft_aoi(num);
	if (ts == LLONG_MAX)
	{
		m_perror("exit", num, "numeric argument required");
		return (255);
	}
	return ((unsigned char)ts);
}

int	cmd_exit(t_data *data, char **arg)
{
	int	x;

	x = data->exm;
	if (arg[0] != NULL)
	{
		if (is_alldigit(arg[0]))
		{
			x = 255;
			m_perror("exit", arg[0], "numeric argument required");
		}
		else if (arg[1] != NULL)
		{
			x = 255;
			m_perror("exit", NULL, "too many arguments");
			return (1);
		}
		else
			x = get_out(arg[0]);
	}
	ft_lstfree(data->input);
	ft_lstfree_2(data->shart);
	fre_env(data->env);
	free(data);
	exit(x);
}
