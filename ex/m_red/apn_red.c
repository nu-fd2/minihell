/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apn_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:50:11 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/18 17:11:46 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	apn_red(t_data *data, char *red)
{
	int neo;

	neo = -1;
	if (!red)
		return (m_perror(NULL, NULL, "ambiguous redirect"));
	if (access(red, F_OK) == -1)
		neo = open(red, O_CREAT | O_WRONLY, 0644);
	else if (access(red, W_OK) == -1)
		return (m_perror(NULL, red, "Permission denied"));
	else
		neo = open(red, O_APPEND | O_WRONLY);
	data->fd = neo;
	return (0);
}
