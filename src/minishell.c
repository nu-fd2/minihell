/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel <sel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:16:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/09/19 09:07:20 by sel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

    // Look ahead
    // char next = exp->input[exp->i_index + 1];

    // Case 1: end of string → keep it as literal '$'
    // if (next == '\0') {
    //     exp->i_index++;
    //     continue;
    // }

    // Case 2: $$ → special case (bash = PID, for you maybe just keep "$$")
    // if (next == '$') {
        // here you can either:
        //   - expand to PID if you want full bash behavior
        //   - or just leave "$$"
    //     exp->i_index += 2; 
    //     continue;
    // }

    // Case 3: invalid var char after '$' (like space, punctuation, etc.)
    // if (!(isalpha((unsigned char)next) || next == '_')) {
        // not a valid var name start → keep '$'
    //     exp->i_index++;
    //     continue;
    // }

    // Case 4: valid variable name → collect and expand (your original logic)
    // exp->i_index++; // skip '$'
    // start = exp->i_index;
    // key_len = 0;

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

char *get_env_value(t_env *env, const char *key) {
    char *value = NULL;

    while (env) {
        if (!strcmp(env->key, key)) {
            value = strdup(env->value);
            break;
        }
        env = env->next;
    }
    return value;
}

int get_var_len(t_env *env, char *key) {
    char *tmp_value;
    int len;

    tmp_value = get_env_value(env, key);
    if (tmp_value) {
        len = strlen(tmp_value);
        free(tmp_value);
        return len;
    }
    return 0;
}

void process_input(t_expansion *exp, t_env *env) {
    char *tmp_key;
    int key_len;
    int start;

    while (exp->input[exp->i_index]) {
        // Quotes d zeb once again : btw this could be a function i did a lot of non DRY coding here sorry Skully
        if (exp->input[exp->i_index] == '\'')
            exp->s_quote = !exp->s_quote;
        else if (exp->input[exp->i_index] == '\"')
            exp->d_quote = !exp->d_quote;

        if (!exp->s_quote && exp->input[exp->i_index] == '$') {
            start = ++exp->i_index;
            exp->len--;
            key_len = 0;
            while (exp->input[exp->i_index] &&
                    (isalnum((unsigned char)exp->input[exp->i_index]) ||
                    exp->input[exp->i_index] == '_')) {
                exp->i_index++;
                exp->len--;
                key_len++;
            }
            if (key_len > 0) {
                tmp_key = malloc(key_len + 1);
                if (!tmp_key)
                    return;
                strncpy(tmp_key, exp->input + start, key_len);
                tmp_key[key_len] = '\0';
                exp->len += get_var_len(env, tmp_key);
                free(tmp_key);
            } else {
                exp->len++;
            }
        }
        else
            exp->i_index++;
    }
    exp->i_index = 0;
}

void fill_output(t_expansion *exp, t_env *env) {
    while (exp->input[exp->i_index]) {
        char c = exp->input[exp->i_index];
        // Quotes d zeb once again : quotes d zeb again you better implement a function that does update the state of the quotes i aint doing it for u nigga (literally copy this code some where else)
        if (c == '\'' && !exp->d_quote)
            exp->s_quote = !exp->s_quote;
        else if (c == '"' && !exp->s_quote)
            exp->d_quote = !exp->d_quote;
            
        if (!exp->s_quote && c == '$') {
            int start = ++exp->i_index;
            int key_len = 0;
            while (exp->input[exp->i_index] && 
                    (isalnum((unsigned char)exp->input[exp->i_index]) || 
                    exp->input[exp->i_index] == '_')) {
                exp->i_index++;
                key_len++;
            }
            if (key_len > 0) {
                char *tmp_key = malloc(key_len + 1);
                if (tmp_key) {
                    strncpy(tmp_key, exp->input + start, key_len);
                    tmp_key[key_len] = '\0';
                    char *val = get_env_value(env, tmp_key);
                    if (val) {
                        int vlen = strlen(val);
                        memcpy(exp->output + exp->o_index, val, vlen);
                        exp->o_index += vlen;
                        free(val);
                    }
                    free(tmp_key);
                }
            } else {
                exp->output[exp->o_index++] = '$';
            }
        } else
            exp->output[exp->o_index++] = exp->input[exp->i_index++];
    }
    exp->output[exp->o_index] = '\0';
}


// Should take the raw input and do a search and replace for each env var
char *expand_env_vars(char *raw_line, t_env *env) {
    t_expansion expansion;

    init_expansion(&expansion, raw_line);

    // get expected len
    process_input(&expansion, env);
    
    // allocate the new_line
    expansion.output = malloc(expansion.len + 1);
    if (!expansion.output)
        return NULL;

    // maybe a function for this and wrap the whole expansion in a diff file : this shit AHHHH
    expansion.i_index = 0;
    expansion.o_index = 0;
    expansion.s_quote = 0;
    expansion.d_quote = 0;
    
    // iterate and replace
    fill_output(&expansion, env);

    free(expansion.input);
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
    printf("old input: %s\n", line);
    line = expand_env_vars(line, data->env);
    printf("new input: %s\n", line);
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
