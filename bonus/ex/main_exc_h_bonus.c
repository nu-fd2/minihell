/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc_h_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 01:17:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 19:41:33 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

int	clr_kids(t_data *data)
{
	t_kids	*ts;
	int		x;

	x = ex_waitkid(data);
	if (x != 0)
		data->exm = x;
	while (data->kids)
	{
		ts = data->kids;
		data->exm = ts->ex;
		data->kids = data->kids->next;
		free(ts);
	}
	data->kids = NULL;
	return (0);
}

void	main_exc_h(t_data *data, t_short *tool, int in, int ot)
{
	int	s;

	s = 0;
	while (tool)
	{
		ot = set_pipe(data, s, tool);
		if (!tool->ambiguous)
		{
			if (pip_exc(data, tool, in, ot) == -1)
				break ;
		}
		else
			data->exm = m_perror(NULL, NULL, "ambiguous redirect");
		if (!s && tool->next)
			in = data->pip1[0];
		else if (s && tool->next)
			in = data->pip2[0];
		s = !s;
		tool = tool->next;
	}
}
