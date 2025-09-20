/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/20 16:34:57 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int pmo = 0;

void manager(t_data *data, char *line)
{
    t_input *input;
    t_short *shart;

    input = tokenize(line);
    if (filter(input))
        return(ft_lstfree(input));
    seperator(input);
    input = money_expansion(input, data);
    input = star_expansion(input);
    striper(input);
    shart = last_lst_creater(input);


//---------------------------------
    if((!shart->args || !shart->args[0]) && !shart->reds)
        return;
//---------------------------------

    data->input = input;
    data->shart = shart;
    pmo = 1;
    main_exc(data, shart);
    pmo = 0;
    ft_lstfree(input);
    ft_lstfree_2(shart);
}

int ft_skip_spaces(t_data *data, char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]) && line[i])
        i++;
    if (line[i] == '\0')
    {
        data->exm = 0;
        return 1;
    }
    return 0;
}

int prompt_msg(t_data *data)
{
    char *line;
        line = readline("\e[1;32m❯ \e[0m");
    if (!line)
    {
        write(1, "exit\n", 5);
        free(line);
        return 0;
    }
    if (ft_skip_spaces(data, line))
        return (free(line), 1);
    add_history(line);
    manager(data, line);
    free(line);
    return 1;
}
void disable_echoctl(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHOCTL;  // disable printing ^C
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void hnd_sig(int sig)
{
	(void)sig;

    if (pmo == 1)
        return ;
    disable_echoctl();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

// void t()
// {
//     system("leaks minishell");
// }

int main(int ac, char **av, char **env)
{
    t_data  *data;
    int     ret;

    // atexit(t);
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
    while(69)
    {
        ret = prompt_msg(data);
        if (ret == 0)
            break;
    }
    fre_env(data->env);
    free(data);
    return (ret);
}

