/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cpro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:56:16 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/24 02:35:50 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	lastkid(t_data *data, pid_t kid)
{
	t_kids	*neo;
	t_kids	*old;

	old = data->kids;
	neo = ft_calloc(sizeof(t_kids), 1);
	neo->kid = kid;
	neo->ex = 1;
	neo->next = NULL;
	if (!data->kids)
		data->kids = neo;
	else
	{
		while (old->next)
			old = old->next;
		old->next = neo;
	}
	return (neo->ex);
}

void	ex_kid_pro(t_data *data, char *cmd, char **arg)
{
	signal(SIGQUIT, SIG_DFL);
	dup2(data->fd2, 0);
	dup2(data->fd, 1);
	if (data->fd2 != data->p_in && data->p_in != 0)
		close(data->p_in);
	if (data->fd != data->p_ot && data->p_ot != 1)
		close(data->p_ot);
	execve(cmd, arg, data->chr_env);
	if (data->fd2 != 0)
		close(data->fd2);
	if (data->fd != 1)
		close(data->fd);
	m_perror(NULL, NULL, "Exec format error");
	exit(1);
}

int	ex_cpro(t_data *data, char *cmd, char **arg)
{
	pid_t	kid;

	g_pmo = 1;
	kid = fork();
	if (kid < 0)
		return (m_perror(NULL, NULL, "can\'t fork"));
	if (kid == 0)
		ex_kid_pro(data, cmd, arg);
	else
	{
		if (data->fd2 != 0)
			close(data->fd2);
		if (data->fd != 1)
			close(data->fd);
		lastkid(data, kid);
		return (kid);
	}
	return (0);
}

int	ex_cpro_bult(t_data *data, char **arg, int bc)
{
	pid_t	kid;
	int		out;

	out = 1;
	g_pmo = 1;
	kid = fork();
	if (kid < 0)
		return (m_perror(NULL, NULL, "can\'t fork"), -1);
	if (kid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(data->fd, 1);
		dup2(data->fd2, 0);
		out = ex_bults_pip(data, arg, bc);
		ft_lstfree(data->input);
		ft_lstfree_2(data->shart);
		clr_kids(data);
		fre_env(data->env);
		free(data);
		exit(out);
	}
	else
		return (lastkid(data, kid), kid);
	return (0);
}
