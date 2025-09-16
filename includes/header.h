/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:27:37 by mdakni            #+#    #+#             */
/*   Updated: 2025/07/01 14:55:22 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <sys/wait.h>

#ifdef linux
#include <readline/history.h>
#include <readline/readline.h>
#else
#include "../readline/history.h"
#include "../readline/readline.h"
#endif

#include "../get_next_line/get_next_line_bonus.h"

// Tokens used to categorise each word in the input string.
// R : right, L : left, S : single, D : double, O : opened, C : closed.
typedef enum s_tokens
{
    TOKEN_WORD,
    TOKEN_OP,
    TOKEN_RED_APP,
    TOKEN_DELIMITER,
    TOKEN_CMD,
    TOKEN_ARG,
    TOKEN_FILE,
    TOKEN_R_RED,
    TOKEN_L_RED,
    TOKEN_R_APP,
    TOKEN_HEREDOC,
    TOKEN_PIPE,
    TOKEN_O_PAR,
    TOKEN_C_PAR,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_EOF
}   t_token;

// AaaaaaaaaaaaaaaaaaaaaA

extern int pmo;

// volatile sig_atomic_t g_sig = 0;

// extern int g_sig;

// typedef struct s_latest t_short;

// typedef struct s_data t_data;

// typedef struct s_env t_env;

// typedef struct s_kids t_kids;

// typedef struct s_nodes t_input;

// typedef struct s_latest t_short;

// typedef struct s_data
// {
// 	int				fd; // out 1
// 	int				fd2; // in 0
// 	int				ex;
// 	int				exm;
// 	int				pmo;
//     int             p_in;
//     int             p_ot;
//     int             dog_kid;
// 	char			**chr_env;
// 	t_env			*env;
//     t_kids          *kids;
//     t_input         *input;
//     t_short         *shart;
// }					t_data;

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			ported;
	struct s_env	*next;
}					t_env;

typedef struct s_kids
{
    pid_t           kid;
    int             ex;
    struct s_kids   *next;
}                   t_kids;

// typedef struct s_pips
// {
//     int         i_pip;
//     int         o_pip;
//     t_pips      *next;
// }               t_pips;

//================================================

typedef struct s_nodes
{
    int index;
    int quotes; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    int strip;
    bool star;
    t_token type;
    t_token category;
    bool red_app;
    bool expand;
    char *value;
    struct s_nodes *next;
    struct s_nodes *prev;
    struct s_nodes *tail;
}   t_input;

typedef struct s_latest
{
    char **args; // this mf
    char **reds; // ls -la | grep 'x' > outfile  -------- args == [ls] [la]
    struct s_latest *next;
    struct s_latest *prev;
    struct s_latest *tail;
    bool ambiguous;
    int red_size;
    bool expanded;
    int pip[2];
    int has_dog;
}   t_short;

typedef struct s_size
{
    int nodes;
    int size_cmd;
    int size_red;
}   t_size;

typedef struct s_quotes
{
    int i;
    int quotes;
    int remove; // 0 : no problems, 1 : open single quotes, 2 : open double quotes
    bool expand;
}   t_quotes;

typedef struct s_flags
{
    char *string;
    char *expand;
    int quotes;
    int start;
    int end;
    int d_start;
    int d_end;
} t_flags;

typedef struct s_blah
{
    int args;
    int reds;
    int args_i;
    int reds_i;
    char **args2;
    char **reds2;
    bool ambiguous;
    int size;
    bool expanded;
} t_blah;

typedef struct s_star
{
    struct dirent *data;
    struct s_star *next;
    
}   t_star;


//////////////////////////////////////////////////////////


typedef struct s_data
{
	int				fd; // out 1
	int				fd2; // in 0
	int				ex;
	int				exm;
	int				pmo;
    int             p_in;
    int             p_ot;
    int             dog_kid;
	char			**chr_env;
	t_env			*env;
    t_kids          *kids;
    t_input         *input;
    t_short         *shart;
}					t_data;


///////////////////////////////////////////////////////////



t_input *tokenize(char *line);
void	*my_calloc(size_t count, size_t size);
char	*my_strdup(const char *s1);
char	*my_strndup(const char *s1, int n);
int	my_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_input **lst, char *content);
void	ft_lstadd_back_2(t_short **lst, t_blah blah);
t_input	*ft_lstlast(t_input *lst);
size_t	my_strlen(const char *s);
void ft_lstfree(t_input *lst);
bool is_space(char c);
void	lst_print(t_input *bruh);
int prompt_msg(t_data *data);//---------
void ft_lstfree_2(t_short *lst);
t_short	*ft_lstlast_2(t_short *lst);
void	ft_lstadd_back_2(t_short **lst, t_blah blah);
void lst_assign_2(t_short **new, t_short **lst);
char	*my_strjoin(char *s1, char *s2);
char	*my_strnjoin(char *s1, char *s2, int n);
int	my_isalpha(int c);
int	my_isalnum(int c);
int handle_pipe(t_input **list, char *line);
int handle_red(t_input **list, char *line);
int handle_app(t_input **list, char *line);
int handle_quotes(t_input **list, char *line);
int handle_word(t_input **list, char *line);
bool check_limit(char *line, t_quotes *check);
char	*my_substr(char const *s, unsigned int start, size_t len);

int filter(t_input *list);
void checker(char *line);
void seperator(t_input *list);
t_short *transformer(t_input *list);
t_input *money_expansion(t_input *list, t_data *data);
t_input *star_expansion(t_input *list);
char	**my_split(char const *s);
t_input *striper(t_input *list);
void lst_print2(t_short *list);
int ft_checker(char c, int quote_flag);
t_short *last_lst_creater(t_input *lst);
void handle_clear(t_input *list, t_blah *blah);

//================================================

size_t		ft_strlen(const char *who);//
size_t		ft_strlcpy(char *dst, const char *src, size_t n);//
size_t		ft_strlcat(char *dst, const char *src, size_t n);//
void		*ft_memset(void	*ptr, int n, size_t num);//
void		ft_bzero(void *s, size_t len);//
int			ft_isdigit(int c);//
int			ft_strncmp(const char *s1, const char *s2, size_t n);//
int			ft_strcmp(const char *s1, const char *s2);//
char		*ft_strchr(const char *str, int c);//
int			ft_atoi(const char *str);//
char		*ft_itoa(int n);//
char		*ft_strdup(const char *s1);//
char		**ft_ssplit(char const *s, char c);//
void		*ft_calloc(size_t count, size_t size);//
char		*ft_ssubstr(char const *s, unsigned int start, size_t len);//
char		*ft_sstrjoin(char const *s1, char const *s2);//                                                                                                             
void		ft_putchar_fd(char c, int fd);//
void		ft_putstr_fd(char *s, int fd);//
int	ft_isalpha(int c);
int	ft_isalnum(int c);
char	*ft_strndup(const char *s1, size_t n);

int	cmd_export(t_data *data, char **arg);
int	cmd_unset(t_data *data, char **arg);
int	cmd_echo(t_data *data, char **arg);
int	cmd_exit(t_data *data, char **arg);
int	cmd_env(t_data *data);
int	cmd_pwd(t_data *data);
int cmd_cd(t_data *data, char **path);

t_env	*int_env(char **env);
int		prn_env(t_data *data);
int		prn_port_env(t_data *data);
int		fre_env(t_env *env);
int		del_env(t_data *data, char *key);
t_env	*grp_env(t_env *env, char *key);
char	*gky_env(t_data *data, char *key);
t_env	*add_env(t_env *env, char *key, char *value, bool ported);
int	lvl_env(t_data *data);
char	**int_chr_env(t_data *data);
void	fre_chr_env(char **env);

int	ex_rish(t_data *data, char **arg);
int	ex_rish_pip(t_data *data, char **arg);
int	ex_bults(t_data *data, char **arg);
int	ex_bults_pip(t_data *data, char **arg, int bc);
int	ex_bults_chk(t_data *data, char **arg);
char    *ex_there(t_data *data, char *cmd);
char    *ex_crnt(t_data *data, char *cmd);
int	ex_cpro(t_data *data, char *cmd, char **arg);
int	ex_cpro_bult(t_data *data, char **arg, int bc);

int	man_red(t_data *data, t_short *shart, char **red);
int	src_red(t_data *data, t_short *shart, char **red);
int	red_red(t_data *data, char *red);
int	apn_red(t_data *data, char *red);
int	inn_red(t_data *data, char *red);
int frk_dog(t_data *data, t_short *shart);
int man_dog(t_data *data, t_short *shart);
void cls_dog_pip(t_short *shart);
int cnt_dog(t_data *data, t_short *shart);

int main_exc(t_data *data, t_short *shart);
int	ex_waitkid(t_data *data);
int clr_kids(t_data *data);

int	m_perror(char *cmd, char *arg, char *msg);

#endif // HEADER_H
