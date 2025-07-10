/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_waitkid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:23:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/10 22:36:39 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ex_waitkid(t_kids *kids)
{
	t_kids	*ts;
	int		sta;
	int		x;

	ts = kids;
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
		ts = ts->next;
	}
	return x;
}
