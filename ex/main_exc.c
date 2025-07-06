/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/06 19:23:32 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void clr_kids(t_kids *kids)
{
	t_kids *ts;

	while (kids)
	{
		ts = kids;
		kids = kids->next;
		free(ts);
	}
}

int sec_exc(t_data *data, t_short *shart, int in, int ot)
{
	int ret;

	ret = 0;
	data->fd = ot;
	data->fd2 = in;
	if (shart->reds)
		ret = man_red(data, shart->reds);
	printf("%d>%d\n", in, ot);
	if (!ret)
		ex_rish(data, shart->args);
	if (data->fd != 1 && data->fd != ot)
		close(data->fd);
	if (data->fd2 != 0 && data->fd2 != in)
		close(data->fd2);
	data->fd = 1;
	data->fd2 = 0;
	return 0;
}

int main_exc(t_data *data, t_short *shart)
{
	t_short *fart;
	int pip1[2];
	int pip2[2];
	int     s;
	int     in;
	int     ot;

	s = 0;
	in = 0;
	ot = 1;
	fart = shart;
	if (!fart->next)
	{
		sec_exc(data, fart, in, ot);
		ex_waitkid(data->kids);
		clr_kids(data->kids);
		data->kids = NULL;
		return 0;
	}
	while (fart)
	{
		if (!s && fart->next)
		{
			pipe(pip1);
			ot = pip1[1];
		}
		else if (s && fart->next)
		{
			pipe(pip2);
			ot = pip2[1];
		}
		else
			ot = 1;

		sec_exc(data, fart, in, ot);

		if (in != 0)
			close (in);
		if (ot != 1)
			close (ot);
		if (!s && fart->next)
			in = pip1[0];
		else if (s && fart->next)
			in = pip2[0];
		s = !s;
		fart = fart->next;
	}
	ex_waitkid(data->kids);
	clr_kids(data->kids);
	data->kids = NULL;
	return 0;
}
