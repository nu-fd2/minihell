/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


t_env	*int_env(char **env)
{
	int		i;
	int		j;

	t_env (*hd_env), (*nu_env), (*tm_env);
	nu_env = NULL;
	i = 0;
	while(env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j] != '\0')
			j++;
		nu_env = ft_calloc(sizeof(t_env), 1);
		nu_env->key = ft_strndup(env[i], j);
		nu_env->value = ft_strdup(&env[i][j + 1]);
		nu_env->ported = 1;
		nu_env->next = NULL;
		if (i == 0)
			hd_env = nu_env;
		else
			tm_env->next = nu_env;
		tm_env = nu_env;
		i++;
	}
	return (hd_env);
}
