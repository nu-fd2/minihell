/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 01:14:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/10 22:08:56 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int open_dog(t_data *data, t_short *fart, char *key)
{
	char *put;
    int  pip[2];

    pipe(pip);
	while (1)
	{
        put = readline("\e[1;34m\e[0m ");
		if (!put)
			break;
		if (ft_strcmp(key, put) == 0)
		{
			free(put);
			break;
		}
		ft_putstr_fd(put, pip[1]);
		free(put);
	}
	close(pip[1]);
	return pip[0];
}

int int_dog(t_data *data, t_short *shart, int m_pip_1)
{
    int		i;
    int     pip_0;
    char    *s;

    pip_0 = 0;
    i = 0;
    if (shart->reds)
    {
        while (shart->reds[i])
        {
            if (ft_strncmp(shart->reds[i], "<<", 3) == 0)
            {
                i++;
                pip_0 = open_dog(data, shart, shart->reds[i]);
            }
            i++;
        }
    }
    if (i)
    {
        s = get_next_line(pip_0);
        while (s)
        {
            ft_putstr_fd(s, m_pip_1);
            free(s);
            s = get_next_line(pip_0);
        }
    }
//    if (pip_0 != 0)
//        close(pip_0);
    return 0;
}

int frk_dog(t_data *data, t_short *shart, int m_pip_1)
{
    int pid;
    int ret;

    pmo = 1;
    pid = fork();
    if (pid < 0)
        return(-1, m_perror("dog", "kid", "forkn\'t"));
    else if (pid == 0)
    {
        signal(SIGINT, SIG_DFL);
        ret = int_dog(data, shart, m_pip_1);
        exit(ret);
    }
    else
        data->dog_kid = pid;
    return pid;
}

////////////////////////////////////////////////////////////////////////


// int open_dog(t_data *data, t_short *fart, char *key, int m_pip[2])
// {
//     int pip[2];
//     char *put;

//     if (pipe(pip) == -1)
//         return m_perror("dog", "pipe", NULL);

//     // collect heredoc input into pip[1]
//     while (1)
//     {
//         put = readline("\e[1;34m>\e[0m ");
//         if (!put || ft_strcmp(key, put) == 0)
//         {
//             free(put);
//             break;
//         }
//         ft_putstr_fd(put, pip[1]);
//         ft_putstr_fd("\n", pip[1]);
//         free(put);
//     }
//     close(pip[1]); // writer closed

//     // now copy from pip[0] -> m_pip[1]
//     char *line = get_next_line(pip[0]);
//     while (line)
//     {
//         ft_putstr_fd(line, m_pip[1]);
//         free(line);
//         line = get_next_line(pip[0]);
//     }
//     close(pip[0]);

//     return 0;
// }

// int int_dog(t_data *data, t_short *shart)
// {
//     t_short *fart = shart;
//     int i;
//     int m_pip[2];

//     if (pipe(m_pip) == -1)
//         return m_perror("dog", "pipe", NULL);

//     while (fart)
//     {
//         i = 0;
//         while (fart->reds && fart->reds[i])
//         {
//             if (ft_strncmp(fart->reds[i], "<<", 2) == 0)
//                 open_dog(data, fart, fart->reds[++i], m_pip);
//             i++;
//         }
//         fart = fart->next;
//     }

//     close(m_pip[1]);       // child finished writing
//     fart = shart;
//     fart->pip[0] = m_pip[0]; // save reader for parent
//     return 0;
// }

// int frk_dog(t_data *data, t_short *shart)
// {
//     int pid;
//     int ret;

//     pmo = 1;
//     pid = fork();
//     if (pid < 0)
//         return (-1, m_perror("dog", "kid", "forkn\'t"));
//     else if (pid == 0)
//     {
//         signal(SIGINT, SIG_DFL);
//         ret = int_dog(data, shart);
//         exit(ret);
//     }
//     else
//         data->dog_kid = pid;
//     return pid;
// }

