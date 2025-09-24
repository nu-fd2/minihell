/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 06:41:04 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 00:40:07 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	exer(t_data *data, t_short *shart, int stat)
{
	int	ex;

	ex = data->exm;
	if (!stat)
		return ;
	ft_lstfree(data->input);
	ft_lstfree_2(data->shart);
	fre_env(data->env);
	free(data);
	exit(ex);
}

void	f_dog_pip(t_data *data, t_short *ts, t_dog dog)
{
	char	*s;

	s = get_next_line(dog.p_in);
	while (s)
	{
		if (data && !dog.quote)
			s = ft_expand_str(s, data);
		ft_putstr_fd(s, ts->pip[1]);
		free(s);
		s = get_next_line(dog.p_in);
	}
	close(dog.p_in);
	close(ts->pip[1]);
}

bool	check_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			return (true);
		i++;
	}
	return (false);
}

t_dog	red_dog(t_data *data, t_short *ts, char *key)
{
	char	*s;
	int		pip[2];
	t_dog	dog;

	if (pipe(pip) == -1)
		return (dog.p_in = -1, dog);
	dog.quote = check_quotes(key);
	key = tmp_assignment(key, ft_calculate_size(key));
	if (!key)
		key = ft_strdup("");
	while (1)
	{
		s = readline("\e[1;34m>\e[0m ");
		if (!s)
			break ;
		if (ft_strcmp(key, s) == 0)
		{
			free(s);
			break ;
		}
		ft_putstr_fd(s, pip[1]);
		ft_putstr_fd("\n", pip[1]);
		free(s);
	}
	return (close(pip[1]), dog.p_in = pip[0], dog);
}

int	man_dog(t_data *data, t_short *shart)
{
	t_short	*ts;
	int		ret;

	ts = shart;
	ret = 0;
	while (ts)
	{
		if (ts->has_dog)
		{
			pipe(ts->pip);
			ret = flavored_water(data, ts);
			if (ret == -1 || ret == 1)
			{
				close(ts->pip[1]);
				return (ret);
			}
			close(ts->pip[1]);
		}
		ts = ts->next;
	}
	return (0);
}
