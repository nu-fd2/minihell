/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:44 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/12 07:38:01 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void 	extt(t_data *data, int c)
{
	if (c < 17)
		return ;
	else
	{
		m_perror(NULL, NULL, "maximum her-dog count exceeded");
		ft_lstfree(data->input);
		ft_lstfree_2(data->shart);
		clr_kids(data);
		fre_env(data->env);
		free(data);
		exit(2);
	}
}

int	cnt_dog(t_data *data, t_short *shart)
{
	t_short	*ts;

	int (i), (c);
	ts = shart;
	i = 0;
	c = 0;
	while (ts)
	{
		i = 0;
		if (ts->reds)
		{
			while (ts->reds[i] && c < 17)
			{
				if (ft_strncmp(ts->reds[i], "<<", 3) == 0)
				{
					i++;
					c++; // lol
				}
				i++;
			}
		}
		ts = ts->next;
	}
	extt(data, c);
	return (c);
}

int man_dog(t_data *data, t_short *shart)
{
	t_short *ts;

	ts = shart;
	while (ts)
	{
		pipe(ts->pip);
        frk_dog(data, ts, ts->pip[1]);
		ts = ts->next;
	}
	return (0);
}

void cls_dog_pip(t_short *shart)
{
	t_short *ts;

	ts = shart;
	while (ts)
	{
		close(ts->pip[0]);
		close(ts->pip[1]);
		ts = ts->next;
	}
}
