/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_waitkid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:23:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/06 06:49:08 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ex_waitkid(t_kids *kids)
{
	t_kids	*ts;
	int		sta;

	ts = kids;
	while (ts)
	{
		waitpid(ts->kid, &sta, 0);
		if (WIFEXITED(sta))
			ts->ex = WIFEXITED(sta);
		else if (WEXITSTATUS(sta))
			ts->ex = 128 + WEXITSTATUS(sta);
		else
			ts->ex = 1;
		printf("%d\n", ts->ex);
		ts = ts->next;
	}
	return 1;
}
