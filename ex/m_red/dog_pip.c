/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:44 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/16 23:35:45 by oel-mado         ###   ########.fr       */
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
			ts->has_dog = 0;
			while (ts->reds[i] && c < 17)
			{
				if (ft_strncmp(ts->reds[i], "<<", 3) == 0)
				{
					i++;
					ts->has_dog = 1;
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

void cls_dog_pip(t_short *shart)
{
	t_short *ts;

	ts = shart;
	while (ts)
	{
		if (ts->has_dog)
		{
			// printf("closin %d>%d\n", ts->pip[0], ts->pip[1]);
			close(ts->pip[0]);
			// close(ts->pip[1]);
		}
		ts = ts->next;
	}
}
