/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fre_chr_env_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:04:24 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/24 12:24:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

void	fre_chr_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	if (!env[0])
	{
		free(env);
		return ;
	}
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
