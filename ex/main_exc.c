/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/23 00:20:02 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int clr_kids(t_data *data)
{
	t_kids *ts;
	int x;

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
	return 0;
}

int pip_exc(t_data *data, t_short *shart, int in, int ot)
{
	int ret;

	ret = 0;
	if (data->fd != 1)
		close(data->fd);
	if (data->fd2 != 0)
		close(data->fd2);
	data->fd = ot;
	data->fd2 = in;
	if (shart->reds)
		ret = man_red(data, shart, shart->reds);
	if (!ret)
	{
		// if (!shart->ambiguous)
		// {
			if (shart->args)
			{
				if (!shart->args[0] && !shart->expanded)
					m_perror(NULL, "", "command not found");
				else if (!shart->expanded || shart->args[0])
					ex_rish_pip(data, shart->args);
			}
		// }
		// else
		// 	m_perror(NULL, shart->args[1], "ambiguous redirect");
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
	return ret;
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
		// if (!shart->ambiguous)
		// {
			if (shart->args)
			{
				if (!shart->args[0] && !shart->expanded)
					m_perror(NULL, "", "command not found");
				else if (!shart->expanded || shart->args[0])
					ex_rish(data, shart->args);
			}
		// }
		// else
		// 	m_perror(NULL, shart->args[1], "ambiguous redirect");
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

int	set_pipe(t_data *data, int s, int *pip1, int *pip2, t_short *fart)
{
	if (!s && fart->next)
	{
		pipe(pip1);
		data->p_in = pip1[0];
		data->p_ot = pip1[1];
		return pip1[1];
	}
	else if (s && fart->next)
	{
		pipe(pip2);
		data->p_in = pip2[0];
		data->p_ot = pip2[1];
		return pip2[1];
	}
	return 1;
}

int main_exc(t_data *data, t_short *shart)
{
	t_short *fart;

	int (s), (in), (ot), (pip1[2]), (pip2[2]);
	int d;
	s = 0;
	in = 0;
	ot = 1;
	d = 0;
	fart = shart;
	data->dog_kid = 0;
	cnt_dog(data, shart);
	d = man_dog(data, shart);
	if (d == 1 || d == -1)
		return d;
	if (!fart->next)
	{
		if (!fart->ambiguous)
		{
			sec_exc(data, fart, in, ot);
			cls_dog_pip(shart);
			return clr_kids(data);
		}
		else
			return (data->exm = 1, m_perror(NULL, NULL, "ambiguous redirect"));
	}
	while (fart)
	{
		ot = set_pipe(data, s, pip1, pip2, fart);
		if (!fart->ambiguous)
		{
			if (pip_exc(data, fart, in, ot) == 1)
				break ;
		}
		else
			data->exm = m_perror(NULL, NULL, "ambiguous redirect");
		if (!s && fart->next)
			in = pip1[0];
		else if (s && fart->next)
			in = pip2[0];
		s = !s;
		fart = fart->next;
	}
	cls_dog_pip(shart);
	clr_kids(data);
	return 0;
}

