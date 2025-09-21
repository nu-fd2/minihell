/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_dog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 06:41:04 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/21 22:40:16 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

typedef struct s_expansion
{
    char	*input;
    char	*output;
    int		s_quote;
    int		d_quote;
    int		i_index;
    int		o_index;
    int		len;
} t_expansion;

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


char *expand_env_vars(char *raw_line, t_env *env) {
    t_expansion expansion;

    init_expansion(&expansion, raw_line);

    process_input(&expansion, env);
    
    expansion.output = malloc(expansion.len + 1);
    if (!expansion.output)
        return NULL;

    expansion.i_index = 0;
    expansion.o_index = 0;
    expansion.s_quote = 0;
    expansion.d_quote = 0;
    
    
    fill_output(&expansion, env);

    free(expansion.input);
    return expansion.output;
}

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

void f_dog_pip(t_data *data, t_short *ts, t_dog dog)
{
    char *s;

    s = get_next_line(dog.p_in);
    while (s)
    {
        if (data && !dog.quote)
            s = ft_expand_str(s, data);
        // s = expand_env_vars(s, data->env);
        ft_putstr_fd(s, ts->pip[1]);
        free(s);
        s = get_next_line(dog.p_in);
    }
    close(dog.p_in);
    close(ts->pip[1]);
}

bool check_quotes(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == '"' || s[i] == '\'')
            return (true);
        i++;
    }
    return (false);
}

t_dog red_dog(t_data *data, t_short *ts, char *key)
{
    char *s;
    int pip[2];
    t_dog dog;

    if (pipe(pip) == -1)
        return (dog.p_in = -1, dog);
    dog.quote = check_quotes(key);
    key = tmp_assignment(key, ft_calculate_size(key));
    if(!key)
        key = ft_strdup("");
    while (1)
    {
        s = readline("\e[1;34m>\e[0m ");
        printf("s : %s, key : %s\n", s, key);
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
    return (dog.p_in = pip[0], dog);
}

int hot_dog(t_data *data, t_short *ts)
{
    int i;
    int ret;
    t_dog dog;
    

    i = 0;
    ret = 0;
    dog.p_in = 0;
    if (ts->reds)
    {
        while (ts->reds[i])
        {
            if (dog.p_in)
                close(dog.p_in);
            if (ft_strcmp(ts->reds[i], "<<") == 0)
            {
                i++;
                if (dog.p_in != 0)
                    close(dog.p_in);
                // p_in = red_dog(data, ts, ts->reds[i]);
                dog = red_dog(data, ts, ts->reds[i]);
                if (dog.p_in == -1)
                {
                    ret = 1;
                    break;
                }
            }
            i++;
        }
        f_dog_pip(data, ts, dog);
    }
    return ret;
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
        
        data->exm = hot_dog(data, ts);
        exer(data, ts, 1);
    }
    else
    {
        waitpid(lil_vro, &stat, 0);
        if (WIFEXITED(stat))
			data->exm = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
        {
			data->exm = 1;
            return 1;
        }
		else
			data->exm = 0;
        
    }
    return 0;
}

int man_dog(t_data *data, t_short *shart)
{
    t_short *ts;
    int ret;

    ts = shart;
    ret = 0;
    while (ts)
    {
        if (ts->has_dog)
        {
            pipe(ts->pip);
            ret = frk_dog(data, ts);
            if ( ret == -1 || ret == 1)
            {
                close(ts->pip[1]);
                return ret;
            }
            close(ts->pip[1]);
        }
        ts = ts->next;
    }
    return 0;
}
