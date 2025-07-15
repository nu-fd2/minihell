/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:01:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/07/14 10:36:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int main(int ac, char **av, char **env)
{
    t_env *nu_env;
    // t_env *tm_env;

    if (ac == 0 && !av && !env)
        return 0;
    printf("start\n");
    // tm_env = int_env(NULL);
    // nu_env = tm_env;
    // while (nu_env)
    // {
        nu_env = add_env(NULL, "KEY", "VALVE", 1);
        printf("%s %s\n", nu_env->key, nu_env->value);
        // nu_env = nu_env->next;
    // }
    printf("end\n");
    free(nu_env);
    // fre_env(tm_env);
    return 0;
}
