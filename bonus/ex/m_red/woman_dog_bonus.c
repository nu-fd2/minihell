/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woman_dog_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:47:38 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 18:30:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header_bonus.h"

int	chocolate_starfish(t_short *ts, t_dog *dog)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (ts->reds[i])
	{
		if (dog->p_in)
			close(dog->p_in);
		if (ft_strcmp(ts->reds[i], "<<") == 0)
		{
			i++;
			if (dog->p_in != 0)
				close(dog->p_in);
			*dog = red_dog(ts->reds[i]);
			if (dog->p_in == -1)
			{
				ret = 1;
				break ;
			}
		}
		i++;
	}
	return (ret);
}

int	hot_dog(t_data *data, t_short *ts)
{
	t_dog	dog;
	int		ret;

	ret = 0;
	dog.p_in = 0;
	if (ts->reds)
	{
		ret = chocolate_starfish(ts, &dog);
		f_dog_pip(data, ts, dog);
	}
	return (ret);
}

int	flavored_water(t_data *data, t_short *ts)
{
	pid_t	lil_vro;
	int		stat;

	g_pmo = 1;
	lil_vro = fork();
	if (lil_vro < 0)
		return (m_perror(NULL, NULL, "can\'t fork"), -1);
	else if (lil_vro == 0)
	{
		signal(SIGINT, SIG_DFL);
		data->exm = hot_dog(data, ts);
		exer(data, 1);
	}
	else
	{
		waitpid(lil_vro, &stat, 0);
		if (WIFEXITED(stat))
			data->exm = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
			return (data->exm = 1, 1);
		else
			data->exm = 0;
	}
	return (0);
}
