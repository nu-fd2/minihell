/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/03 16:37:17 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int sec_exc(t_data *data, t_short *shart, int in, int ot)
{
	int ret;

	ret = 0;
	data->fd = ot;
	data->fd2 = in;
	if (shart->reds)
		ret = man_red(data, shart->reds);
	if (!ret)
		ex_rish(data, shart->args);
	if (data->fd != 1)
		close(data->fd);
	if (data->fd2 != 0)
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
		return (sec_exc(data, fart, in, ot));
	while (fart)
	{
		if (!fart->next)
			ot = 1;
		if (!s)
		{
			pipe(pip1);
			ot = pip1[1];
		}
		else
		{
			pipe(pip2);
			ot = pip2[1];
		}

		sec_exc(data, fart, in, ot);

		if (in != 0)
			close (in);
		if (ot != 1)
			close (ot);
		if (in != 0)
		{
			close(in);
			in = 0;
		}
		if (!s && fart->next)
			in = pip1[0];
		else if (s && fart->next)
			in = pip2[0];
		s = !s;
		fart = fart->next;
	}
	return 0;
}


// int main_exc(t_data *data, t_short *shart)
// {
// 	t_short *fart;
// 	int pip1[2];
// 	int pip2[2];
// 	int s = 0;
// 	int in = 0;
// 	int ot = 1;

// 	fart = shart;
// 	if (!fart->next)
// 		return sec_exc(data, fart, in, ot);

// 	while (fart)
// 	{
// 		if (!fart->next)
// 			ot = 1;
// 		else if (!s)
// 		{
// 			if (pipe(pip1) == -1)
// 				return (perror("pipe1"), 1);
// 			ot = pip1[1];
// 			printf("s1 %d\n", ot);
// 		}
// 		else
// 		{
// 			if (pipe(pip2) == -1)
// 				return (perror("pipe2"), 1);
// 			ot = pip2[1];
// 			printf("s2 %d\n", ot);
// 		}

// 		printf("in = %d, ot = %d\n", in, ot);
// 		sec_exc(data, fart, in, ot);

// 		if (in != 0)
// 			close(in);
// 		if (ot != 1)
// 			close(ot);

// 		if (!s && fart->next)
// 			in = pip1[0];
// 		else if (s && fart->next)
// 			in = pip2[0];

// 		s = !s;
// 		fart = fart->next;
// 	}
// 	return 0;
// }

