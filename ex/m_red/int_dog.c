/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:14:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/08 01:18:18 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int int_dog(t_data *data, t_short *shart)
{
    t_short *fart;
    char *red;
    int i;

    i = 0;
    fart = shart;
    while (fart)
    {
        red = fart->reds[i];
        while (red[i])
        	if (ft_strncmp(red, "<<", 3) == 0)
    }
}
