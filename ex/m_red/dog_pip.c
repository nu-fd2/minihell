/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:44 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/10 22:02:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int cnt_dog(t_short *shart)
{
    t_short *ts;
    int i;
    int c;

    ts = shart;
    i = 0;
    c = 0;
    while (ts)
    {
        i = 0;
        if (!ts->reds)
            continue;
        while (ts->reds[i])
        {
        	if (ft_strncmp(ts->reds[i], "<<", 3) == 0)
            {
                i++;
                c++; // lol
                if (c > 16)
                    return c;
            }
            i++;
        }
        ts = ts->next;
    }
    return c;
}

int man_dog(t_data *data, t_short *shart)
{
    t_short *ts;

    ts = shart;
    while (ts)
    {
        pip(ts->pip);
        ts = ts->next;
    }
    return 0;
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
