/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_env_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:55:17 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/03 13:42:20 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

t_env	*tmp_env(void)
{
	t_env	*neo;
	char	*pwd;

	neo = NULL;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (NULL);
	neo = ft_calloc(sizeof(t_env), 1);
	neo->key = ft_strdup("PWD");
	neo->value = ft_strdup(pwd);
	neo->next = NULL;
	neo->ported = 1;
	free(pwd);
	return (neo);
}

t_env	*int_env(char **env)
{
	t_env	*hd_env;
	t_env	*nu_env;
	t_env	*tm_env;

	int (i), (j);
	if (!env || !env[0])
		return (tmp_env());
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j] != '\0')
			j++;
		nu_env = ft_calloc(sizeof(t_env), 1);
		nu_env->key = ft_strndup(env[i], j);
		nu_env->value = ft_strdup(&env[i][j + 1]);
		nu_env->ported = 1;
		if (i == 0)
			hd_env = nu_env;
		else
			tm_env->next = nu_env;
		tm_env = nu_env;
		i++;
	}
	return (hd_env);
}
