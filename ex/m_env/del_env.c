/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:52:25 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:40 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"


int del_env(t_env *env, char *key)
{
    t_env   *tm_env;
    t_env   *pr_env;
    int     l;

    if (env == NULL)
        return (1);
    tm_env = env;
    l = ft_strlen(key);
    while (tm_env != NULL)
    {
        if (tm_env->key[l] == '\0' && ft_strncmp(tm_env->key, key, l) == 0)
        {
            pr_env->next = tm_env->next;
            free(tm_env->key);
            free(tm_env->value);
            free(tm_env);
            return (0);
        }
        pr_env = tm_env;
        tm_env = tm_env->next;
    }
    return (1);
}
