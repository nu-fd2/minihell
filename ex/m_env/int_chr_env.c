/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_chr_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:09:54 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int	env_len(t_env *env)
{
	int		i;
	t_env	*ennnv;

	i = 0;
	ennnv = env;
	while(ennnv != NULL)
	{
		if (ennnv->ported == 1)
			i++;
		ennnv = ennnv->next;
	}
	return (i);
}

char	**int_chr_env(t_data *data)
{
	int		l;
	int		i;
	t_env	*ennv;
	char	**chr_env;
	char	*tmp_env;

	i = 0;
	ennv = data->env;
	l = env_len(data->env);
	chr_env = ft_calloc(l + 1, sizeof(char *));
	while (ennv)
	{
		if (ennv->ported)
		{
			tmp_env = ft_sstrjoin(ennv->key, "=");
			chr_env[i] = ft_sstrjoin(tmp_env, ennv->value);
			free(tmp_env);
			i++;
		}
		ennv = ennv->next;
	}
	return (chr_env);
}
