/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:52:25 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:28:15 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	del_env(t_data *data, char *key)
{
	t_env	*tm_env;
	t_env	*pr_env;
	int		l;

	if (!data || !data->env)
		return (1);
	if (!key)
		return (0);
	pr_env = NULL;
	tm_env = data->env;
	l = ft_strlen(key);
	while (tm_env != NULL)
	{
		if (ft_strncmp(tm_env->key, key, l) == 0 && tm_env->key[l] == '\0')
		{
			if (pr_env == NULL)
				data->env = tm_env->next;
			else
				pr_env->next = tm_env->next;
			return (free(tm_env->key), free(tm_env->value), free(tm_env), 0);
		}
		pr_env = tm_env;
		tm_env = tm_env->next;
	}
	return (1);
}
