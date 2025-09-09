/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/08 21:37:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int pmo = 0;

// int g_sig = 0;

// void	sig_handler(int sig)
// {
// 	if (sig == SIGINT)
// 		g_sig = SIGINT;
// }

// void	sig_handler(int sig)
// {
	// if (sig == SIGINT)
		// pmo = SIGINT;
// }

// void manager(t_data *data, char *line)
// {
    // t_input *input;
    // t_short *shart;

    // checker(line);
    // input = tokenize(line);
	// printf("tokenize finished\n");
    // if(filter(input))
        // return(ft_lstfree(input));
	// printf("filter finished\n");
    // seperator(input);
	// printf("seperator finished\n");
    // input = money_expansion(input, data);
	// printf("money_expansion finished\n");
    // input = star_expansion(input);
	// printf("star_expansion finished\n");
    // striper(input);
	// printf("striper finished\n");
    // shart = last_lst_creater(input);
	// printf("last_lst_creater finished\n");

    // lst_print2(shart);
	// printf("lst_print2 finished\n");

    // TS AHHHHHHH
    //fnc(shart)

    // write(1, "parsih\n", 7);

    // if((!shart->args || (!shart->args[0] && !shart->expanded)) && !shart->reds)
    //     return;
    // data->input = input;
    // data->shart = shart;

    // main_exc(data, shart);

    // write(1, "exih\n", 5);
    // printf("\e[1;32m%d\e[0m\n", data->exm);

    // lst_print(input);
    // printf("\e[1;32mCums!\e[0m\n");
    // shart = transformer(input);
//     ft_lstfree(input);
//     ft_lstfree_2(shart);
// }

// int ft_skip_spaces(char *line)
// {
//     int i;

//     i = 0;
// 	while(is_space(line[i]) && line[i])
// 		i++;
// 	if(line[i] == '\0')
// 		return 1;
// 	return 0;
// }

// int prompt_msg(t_data *data)
// {
    // g_sig = 0;
    // pmo = 0;
    // signal(SIGINT, sig_handler);
	// signal(SIGQUIT, SIG_IGN);
    // char *line;
    // printf("\e[1;33m%d \e[0m", data->exm);
    // if (!data->exm)
        // line = readline("\e[1;32m❯ \e[0m");
    // else
    //     line = readline("\e[1;31m✖ \e[0m");
    // data->exm = 0;
    // if (g_sig == SIGINT)
    // {
    //     write(1, "\n", 1); // newline for clean prompt
    //     rl_on_new_line();  // readline: prepare new line
    //     rl_replace_line("", 0); // clear the input line
    //     rl_redisplay();    // redraw prompt
    //     g_sig = 0;         // reset signal
    //     free(line);
    //     return 0;
    // }
    // if (pmo)
    // {
    //     write(1, "\n", 1); // newline for clean prompt
    //     rl_on_new_line();  // readline: prepare new line
    //     rl_replace_line("", 0); // clear the input line
    //     rl_redisplay();    // redraw prompt
    //     pmo = 0;         // reset signal
    //     free(line);
    //     return 0;
    // }
//     if (!line)
//     {
//         write(1, "exit\n", 5);
//         free(line);
//         return 0;
//     }
//     if (ft_skip_spaces(line))
//         return (free(line), 1);
//     add_history(line);
//     manager(data, line);
//     free(line);
//     return 1;
// }

// void t()
// {
//     system("leaks minishell");
// }

// void hnd_sig(int sig)
// {
// 	(void)sig;
//     pmo = 1;
// 	// write(1, "\n", 1);
// 	// rl_replace_line("", 0);
// 	// rl_on_new_line();
// 	// rl_redisplay();
// }

// int main(int ac, char **av, char **env)
// {
//     t_data  *data;
//     int     ret;

//     ret = 1;
//     data = ft_calloc(1, sizeof(t_data));
//     data->env = int_env(env);
//     data->fd = 1;
//     data->fd2 = 0;
//     data->p_in = 0;
//     data->p_ot = 1;
//     data->exm = 0;
//     // pmo = 0;
//     data->kids = NULL;
//     lvl_env(data);
//     // signal(SIGINT, hnd_sig);
//     // signal(SIGINT, sig_handler);
// 	// signal(SIGQUIT, SIG_IGN);

//     // atexit(t);

//     while(69)
//     {
//         ret = prompt_msg(data);
//         if (ret == 0)
//             break;
//     }
//     fre_env(data->env);
//     free(data);
//     return (ret);
// }




// int pmo = 0;

// void sig_handler(int sig, siginfo_t *info, void *context)
// {
//     (void)info;
//     (void)context;
//     if (sig == SIGINT)
//         pmo = SIGINT;
// }

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
    data->input = input;
    data->shart = shart;
    main_exc(data, shart);
    ft_lstfree(input);
    ft_lstfree_2(shart);
}

int ft_skip_spaces(char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]) && line[i])
        i++;
    if (line[i] == '\0')
        return 1;
    return 0;
}

// int prompt_msg(t_data *data)
// {
//     struct sigaction sa_int;
//     char *line;

//     pmo = 0;
//     sa_int.sa_sigaction = sig_handler;
//     sa_int.sa_flags = SA_SIGINFO | SA_RESTART; 
//     sigemptyset(&sa_int.sa_mask);
//     sigaction(SIGINT, &sa_int, NULL);
//     signal(SIGQUIT, SIG_IGN);
//     line = readline("\e[1;32m❯ \e[0m");
//     if (pmo == SIGINT)
//     {
//         write(1, "\n", 1);
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//         pmo = 0;
//         if (line)
//             free(line);
//         return 1;
//     }
//     if (!line)
//     {
//         write(1, "exit\n", 5);
//         free(line);
//         return 0;
//     }
//     if (ft_skip_spaces(line))
//     {
//         free(line);
//         return 1;
//     }
//     add_history(line);
//     manager(data, line);
//     free(line);
//     return 1;
// }


int prompt_msg(t_data *data)
{
    char *line;
    // printf("\e[1;33m%d \e[0m", data->exm);
    // if (!data->exm)
        line = readline("\e[1;32m❯ \e[0m");
    // else
    //     line = readline("\e[1;31m✖ \e[0m");
    // data->exm = 0;
    if (!line)
    {
        write(1, "exit\n", 5);
        free(line);
        return 0;
    }
    if (ft_skip_spaces(line))
        return (free(line), 1);
    add_history(line);
    manager(data, line);
    free(line);
    return 1;
}

static void hnd_sig(int sig)
{
	(void)sig;

    if (pmo == 1)
        return ;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int main(int ac, char **av, char **env)
{
    t_data  *data;
    int     ret;

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