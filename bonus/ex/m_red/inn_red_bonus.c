/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inn_red_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:25:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:29:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	inn_red(t_data *data, char *red)
{
	int	neo;

	neo = -1;
	if (!red)
		return (m_perror(NULL, NULL, "ambiguous redirect"));
	if (access(red, F_OK) == -1)
		return (m_perror(NULL, red, "No such file or directory"));
	else if (access(red, R_OK) == -1)
		return (m_perror(NULL, red, "Permission denied"));
	else
		neo = open(red, O_RDONLY);
	data->fd2 = neo;
	return (0);
}
