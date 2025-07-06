/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cpro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:56:16 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/06 07:53:12 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int lastkid(t_data *data, pid_t kid)
{
	t_kids *neo;
	t_kids *old;

	old = data->kids;
	neo = ft_calloc(sizeof(t_kids), 1);
	neo->kid = kid;
	neo->ex = 1;
	neo->next = NULL;
	if (!data->kids)
		data->kids = neo;
	else
	{
		while (old->next)
			old = old->next;
		old->next = neo;
	}
	return neo->ex;
}

int	ex_cpro(t_data *data, char *cmd, char **arg)
{
	pid_t	kid;

	kid = fork();
	if (kid < 0)
		return (m_perror(NULL, NULL, "can't fork"));
	if (kid == 0)
	{
		dup2(data->fd, 1);
		dup2(data->fd2, 0);
		execve(cmd, arg, data->chr_env);
		m_perror("execve", NULL, "can't");
		exit(1);
	}
	else
	{
		lastkid(data, kid);
		return kid;
	}
	return (0);
}
