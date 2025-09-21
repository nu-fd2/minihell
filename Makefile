NAME = minishell

# CFLAGS = -Wall -Werror -Wextra -I./readline/include
# CFLAGS = -fsanitize=address -g -I./readline/include
# CFLAGS = -fsanitize=address -I./readline/include
CFLAGS = -I./readline/include

RDFLAGS = -lreadline -lncurses

SRC = src/minishell.c parse/tokenize.c parse/delimiters.c \
	  parse/filter.c parse/checker.c parse/lst_functions.c \
	  parse/operators.c utils/libft_func.c utils/libft_func2.c \
	  parse/seperator.c parse/money_expansion.c test_print/lst_print.c \
	  utils/libft_func3.c parse/star_expansion.c parse/striper.c \
	  parse/last_lst_creater.c parse/lst_functions_2.c \
	  utils/libft_func4.c utils/libft_func5.c  utils/libft_func6.c \
	  ex/m_red/expand_str.c \
ex/m_bul/cmd_exit.c \
ex/m_bul/cmd_cd.c \
ex/m_bul/cmd_echo.c \
ex/m_bul/cmd_env.c \
ex/m_bul/cmd_export.c \
ex/m_bul/cmd_pwd.c \
ex/m_bul/cmd_unset.c \
ex/m_env/add_env.c \
ex/m_env/del_env.c \
ex/m_env/fre_env.c \
ex/m_env/gky_env.c \
ex/m_env/grp_env.c \
ex/m_env/int_env.c \
ex/m_env/lvl_env.c \
ex/m_env/prn_env.c \
ex/m_env/int_chr_env.c \
ex/m_env/fre_chr_env.c \
ex/m_env/prn_port_env.c \
ex/m_exc/ex_rish.c \
ex/m_exc/ex_bults.c \
ex/m_exc/ex_cpro.c \
ex/m_exc/ex_there.c \
ex/m_exc/ex_crnt.c \
ex/m_exc/ex_waitkid.c \
ex/m_red/src_red.c \
ex/m_red/red_red.c \
ex/m_red/apn_red.c \
ex/m_red/inn_red.c \
ex/m_red/man_red.c \
ex/m_red/man_dog.c \
ex/m_red/dog_pip.c \
ex/main_exc.c \
ex/m_perror.c \
	  \
ex/libft/ft_atoi.c \
ex/libft/ft_itoa.c \
ex/libft/ft_putchar_fd.c \
ex/libft/ft_putstr_fd.c \
ex/libft/ft_strncmp.c \
ex/libft/ft_split.c \
ex/libft/ft_strjoin.c \
ex/libft/ft_strchr.c \
ex/libft/ft_substr.c \
ex/libft/ft_strlcat.c \
ex/libft/ft_strlcpy.c \
ex/libft/ft_strlen.c \
ex/libft/ft_calloc.c \
ex/libft/ft_strndup.c \
ex/libft/ft_isdigit.c \
ex/libft/ft_isalnum.c \
ex/libft/ft_strdup.c \
ex/libft/ft_bzero.c \
ex/libft/ft_isalpha.c \
ex/libft/ft_memset.c \
ex/libft/ft_strcmp.c \
	\
get_next_line/get_next_line_bonus.c \
get_next_line/get_next_line_utils_bonus.c \
	\

OBJ = $(SRC:.c=.o)
# nnn -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc
# CC = cc -Wall -Wextra -Werror

t:
	@make re
	@make clean
	@clear

all:$(NAME)

# $(LBFT):
# 	make -C ex/libft

$(NAME):$(OBJ) $(LBFT)
	$(CC) $(CFLAGS) $(OBJ) readline/libreadline.a readline/libhistory.a -o $(NAME) $(RDFLAGS)

%.o: %.c includes/header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

