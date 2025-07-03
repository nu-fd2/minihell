/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cpro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:56:16 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/02 17:55:46 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	ex_cpro(t_data *data, char *cmd, char **arg)
{
	int		sta;
	int		firekeeper;
	int		firekeeper2;
	pid_t	kid;
	char	**nvv;

	sta = 0;

	printf("%s %d %d\n", cmd, data->fd2, data->fd);
	kid = fork();
	if (kid < 0)
		return 1;
	if (kid == 0)
	{
		dup2(data->fd, 1);
		dup2(data->fd2, 0);
		execve(cmd, arg, data->chr_env);
		perror("execve");
		exit(EXIT_FAILURE);
		return (1);
	}
	else
	{
        waitpid(kid, &sta, 0);
		firekeeper = WIFEXITED(sta);
		firekeeper2 = WEXITSTATUS(sta);
		if (firekeeper)
			return (firekeeper);
		else if (firekeeper2)
			return (128 + firekeeper2);
	}
	return (0);
}
