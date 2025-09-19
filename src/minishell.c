/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/19 06:53:03 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

typedef struct s_expansion
{
	char					*input;
	char					*output;
	int						s_quote;
	int						d_quote;
	int						i_index;
	int						o_index;
	int						len;
}							t_expansion;

void	init_expansion(t_expansion *exp, char *input)
{
	exp->input = input;
	exp->len = ft_strlen(input);
	exp->s_quote = 0;
	exp->d_quote = 0;
	exp->i_index = 0;
	exp->o_index = 0;
    exp->output = NULL;
}

const char *get_env_value(t_env *env, const char *key) {
    const char *value = NULL;

    while (env) {
        if (strcmp(env->key, key)) {
            value = strdup(env->value);
            break;
        }
        env = env->next;
    }
    return value;
}

int get_var_len(t_env *env, char *key) {
    char *tmp_value;

    tmp_value = get_env_value(env, key);
    if (tmp_value)
        return strlen(tmp_value);
    return 0;
}

void process_input(t_expansion *exp) {
    char *tmp_key;
    int key_len = 0;

    while (exp->input[exp->i_index]) {
        // not sure about the conditions: look up the valid vars namings in man bash
        if ( exp->input[exp->i_index] == '$' ) {
            exp->len--;
            exp->i_index ++;
            while (!is_space(exp->input[exp->i_index])) {
                exp->i_index ++;
                key_len ++;
            }
            
        }

        exp->i_index++;
    }
}

// Should take the raw input and do a search and replace for each env var
char *expand_env_vars(char *raw_line, t_env *env) {
    t_expansion expansion;

    init_expansion(&expansion, raw_line);
    // get expected len

    // allocate the new_line

    // iterate and replace
    

    return expansion.output;
}


void manager(t_data *data, char *line)
{
    t_input *input;
    t_short *shart;

    // checker(line);
    input = tokenize(line);
	// printf("tokenize finished\n");
    if(filter(input))
        return(ft_lstfree(input));
	// printf("filter finished\n");
    seperator(input);
	// printf("seperator finished\n");
    // input = money_expansion(input, data);
	// // printf("money_expansion finished\n");
    // input = star_expansion(input);
	// printf("star_expansion finished\n");
    striper(input);
	// printf("striper finished\n");
    shart = last_lst_creater(input);
	// printf("last_lst_creater finished\n");
    lst_print(input);
    lst_print2(shart);
	// printf("lst_print2 finished\n");

    // TS AHHHHHHH
    //fnc(shart)

    // write(1, "parsih\n", 7);
    if((!shart->args || !shart->args[0]) && !shart->reds)
        return;
    data->input = input;
    data->shart = shart;

    main_exc(data, shart);

    // write(1, "exih\n", 5);
    // printf("\e[1;32m%d\e[0m\n", data->exm);

    // lst_print(input);
    // printf("\e[1;32mCums!\e[0m\n");
    // shart = transformer(input);
    ft_lstfree(input);
    ft_lstfree_2(shart);
}

int ft_skip_spaces(char *line)
{
    int i;

    i = 0;
	while(is_space(line[i]) && line[i])
		i++;
	if(line[i] == '\0')
		return 1;
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
        // exit(0);
        return 0;
    }
    if (ft_skip_spaces(line))
        return (free(line), 1);
    add_history(line);
    manager(data, line);
    free(line);
    return 1;
}

void t()
{
    system("leaks minishell");
}

static void hnd_sig(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int main(int ac, char **av, char **env)
{
    t_data  *data;
    int     ret;

    (void)ac;
    (void)av;
    ret = 1;
    data = ft_calloc(1, sizeof(t_data));
    data->env = int_env(env);
    data->fd = 1;
    data->fd2 = 0;
    data->exm = 0;
    data->kids = NULL;
    lvl_env(data);
    signal(SIGINT, hnd_sig);
	signal(SIGQUIT, SIG_IGN);

    // atexit(t);

    write(1, "\e[1;31mstartin hell...!\e[0m\n", 28);
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
