/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:06:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 19:41:33 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

void	clus(t_data *data, int in, int ot)
{
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
}

int	pip_exc(t_data *data, t_short *shart, int in, int ot)
{
	int	ret;

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
		if (shart->args)
		{
			if (!shart->args[0] && !shart->expanded)
				m_perror(NULL, "", "command not found");
			else if (!shart->expanded || shart->args[0])
				ret = ex_rish_pip(data, shart->args);
		}
	}
	else
		data->exm = ret;
	clus(data, in, ot);
	return (ret);
}

int	sec_exc(t_data *data, t_short *shart, int in, int ot)
{
	int	ret;

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
	clus(data, in, ot);
	return (ret);
}

int	set_pipe(t_data *data, int s, t_short *tool)
{
	if (!s && tool->next)
	{
		pipe(data->pip1);
		data->p_in = data->pip1[0];
		data->p_ot = data->pip1[1];
		return (data->pip1[1]);
	}
	else if (s && tool->next)
	{
		pipe(data->pip2);
		data->p_in = data->pip2[0];
		data->p_ot = data->pip2[1];
		return (data->pip2[1]);
	}
	return (1);
}

int	main_exc(t_data *data, t_short *shart)
{
	t_short	*tool;

	int (in), (ot);
	in = 0;
	ot = 1;
	tool = shart;
	data->dog_kid = 0;
	cnt_dog(data, shart);
	if (man_dog(data, shart))
		return (1);
	if (!tool->next)
	{
		if (!tool->ambiguous)
		{
			sec_exc(data, tool, in, ot);
			cls_dog_pip(shart);
			return (clr_kids(data));
		}
		else
			return (data->exm = 1, m_perror(NULL, NULL, "ambiguous redirect"));
	}
	main_exc_h(data, tool, in, ot);
	return (cls_dog_pip(shart), clr_kids(data), 0);
}
