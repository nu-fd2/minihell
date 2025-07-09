/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:14:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/09 01:13:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int open_dog(t_short *fart, char *key)
{
    char *put;
    int l;

    put = NULL;
    if (fart->pip[0] != 0)
        close(fart->pip[0]);
    if (fart->pip[1] != 1)
        close(fart->pip[1]);
    pipe(fart->pip);

    l = ft_strlen(key);
    write(1, "> ", 2);
    put =  get_next_line(0);
    while (put)
    {
        if ((ft_strncmp(key, put, l) == 0 && put[l] == '\n') || !put)
        {
            free(put);
            break;
        }
        ft_putstr_fd(put, fart->pip[1]);
        free(put);
        write(1, "> ", 2);
        put = get_next_line(0);
    }
    close(fart->pip[1]);
    return 0;
}

int int_dog(t_data *data, t_short *shart)
{
    t_short *fart;
    int i;

    fart = shart;
    while (fart)
    {
        i = 0;
        fart->pip[0] = 0;
        fart->pip[1] = 1;
        if (!fart->reds)
            return 0;
        while (fart->reds[i])
        {
        	if (ft_strncmp(fart->reds[i], "<<", 3) == 0)
            {
                i++;
                open_dog(fart, fart->reds[i]);
            }
            i++;
        }
        fart = fart->next;
    }
    return 0;
}
