/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:17:29 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:27:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	cmd_env(t_data *data)
{
	if (!data || !(data->env))
		return (m_perror("env", NULL, "env is NULL"));
	prn_env(data);
	return (0);
}
