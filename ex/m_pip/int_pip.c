/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:19 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_pips	*neo_pip()
{
	int i;
	int fds[2];
	t_pips	*pips;

	i = 0;
	pips = malloc(sizeof(t_pips) * 1);
	if (pipe(fds) == -1)
		return (NULL);
	pips->i_pip = fds[0];
	pips->o_pip = fds[1];
	pips->next = NULL;
	return (pips);
}

int	cnt_pip(t_short *shart)
{
	t_short *fart;
	int n;

	n = 0;
	fart = shart;
	while (fart)
	{
		n++;
		fart = fart->next;
	}
	return (n);
}

int	int_pip(t_data *data, t_short *shart)
{
	int i;
	int n;
	t_pips	*pips;

	i = 1;
	n = cnt_pip(shart);
	if (n < 2)
		return (0);
	data->pips = neo_pip();
	pips = data->pips;
	if (!data->pips)
		return (clr_pip(data), 1);
	while (i < n - 1)
	{
		pips->next = neo_pip(data);
		if (!pips)
			return (clr_pip(data), 1);
		pips = pips->next;
		i++;
	}
	return (n - 1);
}
