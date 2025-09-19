/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 06:41:04 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/19 07:47:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void exer(t_data *data, t_short *shart, int stat)
{
    int ex;

    ex = data->exm;
    if (!stat)
        return ;
    ft_lstfree(data->input);
	ft_lstfree_2(data->shart);
	fre_env(data->env);
	free(data);
	exit(ex);
}

void f_dog_pip(t_data *data, t_short *ts, int p_in)
{
    char *s;

    s = get_next_line(p_in);
    while (s)
    {
        ft_putstr_fd(s, ts->pip[1]);
        s = get_next_line(p_in);
    }
    close(p_in);
    close(ts->pip[1]);
}

int red_dog(t_data *data, t_short *ts, char *key)
{
    char *s;
    int pip[2];

    pipe(pip);
    while (1)
    {
        s = readline("\e[1;34m>\e[0m ");
        if (!s)
            break;
        if (ft_strcmp(key, s) == 0)
        {
            free(s);
            break;
        }
        ft_putstr_fd(s, pip[1]);
        ft_putstr_fd("\n", pip[1]);
        free(s);
    }
    close(pip[1]);
    return (pip[0]);
}

int hot_dog(t_data *data, t_short *ts)
{
    int i;
    int p_in;

    i = 0;
    p_in = 0;
    if (ts->reds)
    {
        while (ts->reds[i])
        {
            if (p_in)
                close(p_in);
            if (ft_strcmp(ts->reds[i], "<<") == 0)
            {
                i++;
                if (p_in != 0)
                    close(p_in);
                p_in = red_dog(data, ts, ts->reds[i]);
            }
            i++;
        }
        f_dog_pip(data, ts, p_in);
    }
    return 0;
}

int frk_dog(t_data *data, t_short *ts)
{
    pid_t lil_vro;
    int stat;

    pmo = 1;
    lil_vro = fork();
    if (lil_vro < 0)
        return (m_perror(NULL, NULL, "forknt"), -1);
    else if (lil_vro == 0)
    {
        signal(SIGINT, SIG_DFL);
        data->exm = 1;
        data->exm = hot_dog(data, ts);
        exer(data, ts, 1);
    }
    else
    {
        waitpid(lil_vro, &stat, 0);
        if (WIFEXITED(stat))
			data->exm = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
			data->exm = 128 + WTERMSIG(stat);
		else
			data->exm = 0;
    }
    return 0;
}

int man_dog(t_data *data, t_short *shart)
{
    t_short *ts;

    ts = shart;
    while (ts)
    {
        if (ts->has_dog)
        {
            pipe(ts->pip);
            if (frk_dog(data, ts) == -1)
            {
                close(ts->pip[1]);
                return -1;
            }
            close(ts->pip[1]);
        }
        ts = ts->next;
    }
    return 0;
}
