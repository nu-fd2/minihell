/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gky_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 08:38:32 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/08 20:00:23 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


char	*gky_env(t_data *data, char *key)
{
	t_env	*n_env;

	n_env = grp_env(data->env, key);
	if(n_env == NULL)
		return NULL;
	return (n_env->value);
}
