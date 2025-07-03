/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:23:49 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void    clr_pip(t_data *data)
{
    t_pips  *tmp;
    t_pips  *pmt;

    tmp = data->pips;
    while (tmp)
    {
        pmt = tmp;
        tmp = tmp->next;
        close(pmt->i_pip);
        close(pmt->o_pip);
        free(pmt);
    }
}
