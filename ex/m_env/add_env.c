/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:50:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/16 00:12:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_env	*mak_env(char *key, char *value, bool ported)
{
	t_env	*nu_env;

	nu_env = ft_calloc(sizeof(t_env), 1);
	if (!nu_env)
		return (NULL);
	nu_env->key = ft_strdup(key);
	if (!nu_env->key)
		return (free(nu_env), NULL);
	if (value)
		nu_env->value = ft_strdup(value);
	else
		nu_env->value = NULL;
	nu_env->ported = ported;
	nu_env->next = NULL;
	return (nu_env);
}

t_env	*add_env(t_env *env, char *key, char *value, bool ported)
{
	t_env	*tm_env;

	if (!key || key[0] == '\0')
		return (NULL);
	if (!env)
		return (mak_env(key, value, ported));
	tm_env = grp_env(env, key);
	if (!tm_env)
	{
		tm_env = env;
		while (tm_env->next)
			tm_env = tm_env->next;
		tm_env->next = mak_env(key, value, ported);
		if (!tm_env->next)
			return (NULL);
		return (tm_env->next);
	}
	if (ported == 0)
		return (tm_env->next);
	free(tm_env->value);
	tm_env->value = ft_strdup(value);
	tm_env->ported = 1;
	return (tm_env);
}
