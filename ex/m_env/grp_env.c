/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grp_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:54:01 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/14 22:35:39 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_env	*grp_env(t_env *env, char *key)
{
	t_env	*tm_env;
	int		l;

	if (key == NULL || env == NULL)
		return (NULL);
	tm_env = env;
	l = ft_strlen(key);
	while (tm_env != NULL)
	{
		if (ft_strncmp(tm_env->key, key, l) == 0)
		{
			return (tm_env);
		}
		tm_env = tm_env->next;
	}
	return (NULL);
}
