/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:01:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/31 12:21:20 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int main(int ac, char **av, char **env)
{
	t_data *data;
	// t_env	*nv;
	if (ac == 0 && !av && !env)
		return 0;
	printf("start\n");
	data = malloc(sizeof(t_data) * 1);
	data->fd = 1;
	// nv = malloc(sizeof(t_env) * 1);
	// nv->key = ft_strdup("SHL");
	// nv->value = ft_strdup("3");
	// nv->ported = 1;
	data->env = NULL;
	lvl_env(data);

	prn_port_env(data);

	printf("end\n");
	fre_env(data->env);
	free(data);
	return 0;
}
