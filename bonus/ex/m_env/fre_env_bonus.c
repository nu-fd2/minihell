/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:52:53 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:28:22 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	fre_env(t_env *env)
{
	t_env	*tm_env;

	while (env)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		tm_env = env;
		env = env->next;
		free(tm_env);
	}
	return (0);
}
