/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:52:53 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	fre_env(t_env *env)
{
	t_env	*tm_env;

	if (env == NULL)
		return (1);
	else
	{
		while (env != NULL)
		{
			free(env->key);
			free(env->value);
			tm_env = env;
			env = env->next;
			free(tm_env);
		}
	}
	return (0);
}
