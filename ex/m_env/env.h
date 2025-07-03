/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:00:33 by oel-mado          #+#    #+#             */
/*   Updated: 2025/06/16 18:41:17 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

#include "../m_exec.h"

typedef struct s_data t_data;

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			ported;
	struct s_env	*next;
}					t_env;

t_env	*int_env(char **env);
int		prn_env(t_data *data);
int		prn_port_env(t_data *data);
int		fre_env(t_env *env);
int		del_env(t_env *env, char *key);
t_env	*grp_env(t_env *env, char *key);
char	*gky_env(t_env *env, char *key);
t_env	*add_env(t_env *env, char *key, char *value, bool ported);
int	lvl_env(t_data *data);
char	**int_chr_env(t_data *data);
void	fre_chr_env(char **env);

#endif // ENV_H
