/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:14:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/08/05 00:44:06 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

// int open_dog(t_data *data, t_short *fart, char *key)
// {
//     char *put;
//     int l;

//     put = NULL;
//     if (fart->pip[0] != 0)
//         close(fart->pip[0]);
//     if (fart->pip[1] != 1)
//         close(fart->pip[1]);
//     pipe(fart->pip);

//     l = ft_strlen(key);
//     pmo = 0;
//     write(1, "> ", 2);
//     put =  get_next_line(0);
//     while (put && pmo == 0)
//     {
//         if ((ft_strncmp(key, put, l) == 0 && put[l] == '\n') || !put)
//         {
//             free(put);
//             break;
//         }
//         ft_putstr_fd(put, fart->pip[1]);
//         free(put);
//         if (!pmo)
//         {
//             write(1, "> ", 2);
//             put = get_next_line(0);
//         }
//     }
//     write(1, "hi\n", 3);
//     close(fart->pip[1]);
//     return 0;
// }

int open_dog(t_data *data, t_short *fart, char *key)
{
	char *put;
	int l;

	if (fart->pip[0] != 0)
		close(fart->pip[0]);
	if (fart->pip[1] != 1)
		close(fart->pip[1]);
	pipe(fart->pip);

	l = ft_strlen(key);
	pmo = 0;
	write(1, "> ", 2);
	while (1)
	{
		put = get_next_line(0);
		if (pmo || !put)
			break;
		if (ft_strncmp(key, put, l) == 0 && put[l] == '\n')
		{
			free(put);
			break;
		}
		ft_putstr_fd(put, fart->pip[1]);
		free(put);
		if (pmo)
			return 1;
		write(1, "> ", 2);
	}
	if (pmo)
		return 1;
	close(fart->pip[1]);
	return 0;
}

int int_dog(t_data *data, t_short *shart)
{
    t_short *fart;
    int i;

    fart = shart;
    while (fart && pmo == 0)
    {
        i = 0;
        fart->pip[0] = 0;
        fart->pip[1] = 1;
        if (!fart->reds)
            return 0;
        while (fart->reds[i] && pmo == 0)
        {
        	if (ft_strncmp(fart->reds[i], "<<", 3) == 0 && pmo == 0)
            {
                i++;
                open_dog(data, fart, fart->reds[i]);
            }
            i++;
        }
        fart = fart->next;
    }
    return 0;
}
