/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/24 02:42:02 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_bonus.h"

int			g_pmo = 0;

void	manager(t_data *data, char *line)
{
	t_input	*input;
	t_short	*shart;

	input = tokenize(line);
	if (filter(input))
		return (ft_lstfree(input));
	seperator(input);
	input = money_expansion(input, data);
	input = star_expansion(input);
	striper(input);
	shart = last_lst_creater(input);
	if ((!shart->args || !shart->args[0]) && !shart->reds)
		return ;
	data->input = input;
	data->shart = shart;
	g_pmo = 1;
	main_exc(data, shart);
	g_pmo = 0;
	ft_lstfree(input);
	ft_lstfree_2(shart);
}

int	prompt_msg(t_data *data)
{
	char	*line;

	line = readline("❯ ");
	if (!line)
	{
		write(1, "exit\n", 5);
		free(line);
		return (0);
	}
	if (ft_skip_spaces(data, line))
		return (free(line), 1);
	add_history(line);
	manager(data, line);
	free(line);
	return (1);
}

static void	hnd_sig(int sig)
{
	(void)sig;
	if (g_pmo == 1)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	int		ret;

	(void)ac;
	(void)av;
	ret = 1;
	data = ft_calloc(1, sizeof(t_data));
	data->env = int_env(env);
	data->fd = 1;
	data->fd2 = 0;
	data->p_in = 0;
	data->p_ot = 1;
	data->exm = 0;
	data->kids = NULL;
	lvl_env(data);
	signal(SIGINT, hnd_sig);
	signal(SIGQUIT, SIG_IGN);
	while (69)
	{
		ret = prompt_msg(data);
		if (ret == 0)
			break ;
	}
	return (fre_env(data->env), free(data), ret);
}
