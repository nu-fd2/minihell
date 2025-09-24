/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 01:17:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 01:18:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

void	main_exc_h(t_data *data, t_short *fart, int in, int ot)
{
	int	s;

	s = 0;
	while (fart)
	{
		ot = set_pipe(data, s, fart);
		if (!fart->ambiguous)
			pip_exc(data, fart, in, ot);
		else
			data->exm = m_perror(NULL, NULL, "ambiguous redirect");
		if (!s && fart->next)
			in = data->pip1[0];
		else if (s && fart->next)
			in = data->pip2[0];
		s = !s;
		fart = fart->next;
	}
}
