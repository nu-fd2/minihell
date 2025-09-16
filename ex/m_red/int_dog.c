/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:14:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/16 21:40:11 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

// int open_dog(t_data *data, t_short *fart, char *key)
// {
// 	char *put;
//     int  pip[2];

//     pipe(pip);
// 	while (1)
// 	{
//         put = readline("\e[1;34m>\e[0m ");
// 		if (!put)
// 			break;
// 		if (ft_strcmp(key, put) == 0)
// 		{
// 			free(put);
// 			break;
// 		}
// 		ft_putstr_fd(put, pip[1]);
// 		ft_putstr_fd("\n", pip[1]);
// 		free(put);
// 	}
// 	close(pip[1]);
// 	return pip[0];
// }

// int int_dog(t_data *data, t_short *shart, int *m_pip)
// {
//     int		i;
//     int     pip_0;
//     char    *s;

//     pip_0 = 0;
//     i = 0;
//     if (shart->reds)
//     {
//         while (shart->reds[i])
//         {
//             if (ft_strncmp(shart->reds[i], "<<", 3) == 0)
//             {
//                 i++;
//                 pip_0 = open_dog(data, shart, shart->reds[i]);
//             }
//             i++;
//         }
//     }
//     printf("______%d\n", m_pip[1]);
//     if (i)
//     {
//         s = get_next_line(pip_0);  
//         int sss = 0;
//         while (s)
//         {
//             sss++;
//             ft_putstr_fd(s, m_pip[1]);
//             ft_putstr_fd("pp: ", 1);
//             ft_putstr_fd(s, 1);
//             free(s);
//             s = get_next_line(pip_0);
//         }
//         close(m_pip[1]);
//         printf("ts tsss %d>%d  >< %d\n", m_pip[0], m_pip[1], sss);
        // ft_putstr_fd("WERUIO\n", 1);
        // read(m_pip[0], s, 1);
        // write(1, "-", 1);
        // write(1, &s[0], 1);
        // write(1, "-\n", 2);
        // s = NULL;
        // s[0] = '\0';
//         s = get_next_line(m_pip[0]);
//         if (!s || !s[0])
//             ft_putstr_fd("S AAAAA\n", 1);
//             // printf("s 5aw\n");
//         else
//             ft_putstr_fd("S MMMMMMAAAAA\n", 1);
//             // printf("s maa\n");
//         while (s)
//         {
//             ft_putstr_fd("nn: ", 1);
//             ft_putstr_fd(s, 1);
//             free(s);
//             s = get_next_line(m_pip[0]);
//         }
//     }
//     printf("sla\n");
//     if (pip_0 != 0)
//         close(pip_0);
//     return 0;
// }

// int frk_dog(t_data *data, t_short *shart)
// {
//     int pid;
//     int ret;

//     printf("frk : %d>%d\n", shart->pip[0], shart->pip[1]);
//     pmo = 1;
//     pid = fork();
//     if (pid < 0)
//         return(m_perror("dog", "kid", "forkn\'t"));
//     else if (pid == 0)
//     {
//         signal(SIGINT, SIG_DFL);
//         printf("frg get %d", shart->pip[1]);
//         ret = int_dog(data, shart, shart->pip);
//         printf("sla2\n");
//         exit(ret);
//     }
//     else
//         data->dog_kid = pid;
//     return pid;
// }
