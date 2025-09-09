/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_waitkid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:23:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/08/03 21:56:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ex_waitkid(t_data *data)
{
	t_kids	*ts;
	int		sta;
	int		x;

	ts = data->kids;
	x = 0;
	while (ts)
	{
		waitpid(ts->kid, &sta, 0);
		if (WIFEXITED(sta))
			ts->ex = WEXITSTATUS(sta);
		else if (WIFSIGNALED(sta))
			ts->ex = 128 + WTERMSIG(sta);
		else
			ts->ex = 0;
		x = ts->ex;
		// fprintf(stderr, "kid sala %d\n", x);
		if (data->fd2 != 0)
			close(data->fd2);
		if (data->fd != 1)
			close(data->fd);
		ts = ts->next;
	}
	return x;
}
