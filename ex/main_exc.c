/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/11 10:32:50 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int clr_kids(t_data *data)
{
	t_kids *ts;
	int x;

	x = ex_waitkid(data->kids);
	if (x != 0)
		data->exm = x;
	while (data->kids)
	{
		ts = data->kids;
		data->kids = data->kids->next;
		free(ts);
	}
	data->kids = NULL;
	return 0;
}

int sec_exc(t_data *data, t_short *shart, int in, int ot)
{
	int ret;

	ret = 0;
	data->fd = ot;
	data->fd2 = in;
	if (shart->reds)
		ret = man_red(data, shart, shart->reds);
	if (!ret)
	{
		if (shart->args)
		{
			if (!shart->args[0] && !shart->expanded)
				m_perror(NULL, "", "command not found");
			else if (!shart->expanded || shart->args[0])
				ex_rish(data, shart->args);
		}
	}
	else
		data->exm = ret;
	if (data->fd != 1 && data->fd != ot)
		close(data->fd);
	if (data->fd2 != 0 && data->fd2 != in)
		close(data->fd2);
	if (in != 0)
		close (in);
	if (ot != 1)
		close (ot);
	data->fd = 1;
	data->fd2 = 0;
	return 0;
}

int	set_pipe(int s, int *pip1, int *pip2, t_short *fart)
{
	if (!s && fart->next)
	{
		pipe(pip1);
		return pip1[1];
	}
	else if (s && fart->next)
	{
		pipe(pip2);
		return pip2[1];
	}
	return 1;
}

int main_exc(t_data *data, t_short *shart)
{
	t_short *fart;

	int (s), (in), (ot), (pip1[2]), (pip2[2]);
	s = 0;
	in = 0;
	ot = 1;
	fart = shart;
	int_dog(data, shart);
	if (!fart->next)
	{
		sec_exc(data, fart, in, ot);
		return clr_kids(data);
	}
	while (fart)
	{
		ot = set_pipe(s, pip1, pip2, fart);
		sec_exc(data, fart, in, ot);
		if (!s && fart->next)
			in = pip1[0];
		else if (s && fart->next)
			in = pip2[0];
		s = !s;
		fart = fart->next;
	}
	clr_kids(data);
	return 0;
}
