# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 16:40:56 by oel-mado          #+#    #+#              #
#    Updated: 2025/09/24 17:51:27 by mdakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = minishell_bonus
CFLAGS = -Wall -Werror -Wextra -I./readline/include
RDFLAGS = -lreadline -lncurses
SRC = src/minishell_bonus.c \
parse/tokenize_bonus.c \
parse/delimiters_bonus.c \
parse/filter_bonus.c \
parse/checker_bonus.c \
parse/lst_functions_bonus.c \
parse/operators_bonus.c \
utils/libft_func_bonus.c \
utils/libft_func2_bonus.c \
parse/seperator_bonus.c \
parse/money_expansion_bonus.c \
utils/libft_func3_bonus.c \
parse/star_expansion_bonus.c \
parse/striper_bonus.c \
parse/last_lst_creater_bonus.c \
parse/lst_functions_2_bonus.c \
utils/libft_func4_bonus.c \
utils/libft_func5_bonus.c \
utils/libft_func6_bonus.c \
ex/m_red/expand_str_bonus.c \
	\
ex/m_bul/cmd_exit_bonus.c \
ex/m_bul/cmd_cd_bonus.c \
ex/m_bul/cmd_echo_bonus.c \
ex/m_bul/cmd_env_bonus.c \
ex/m_bul/cmd_export_bonus.c \
ex/m_bul/cmd_pwd_bonus.c \
ex/m_bul/cmd_unset_bonus.c \
ex/m_env/add_env_bonus.c \
ex/m_env/del_env_bonus.c \
ex/m_env/fre_env_bonus.c \
ex/m_env/gky_env_bonus.c \
ex/m_env/grp_env_bonus.c \
ex/m_env/int_env_bonus.c \
ex/m_env/lvl_env_bonus.c \
ex/m_env/prn_env_bonus.c \
ex/m_env/int_chr_env_bonus.c \
ex/m_env/fre_chr_env_bonus.c \
ex/m_env/prn_port_env_bonus.c \
ex/m_exc/ex_rish_bonus.c \
ex/m_exc/ex_bults_bonus.c \
ex/m_exc/ex_cpro_bonus.c \
ex/m_exc/ex_there_bonus.c \
ex/m_exc/ex_crnt_bonus.c \
ex/m_exc/ex_waitkid_bonus.c \
ex/m_red/src_red_bonus.c \
ex/m_red/red_red_bonus.c \
ex/m_red/apn_red_bonus.c \
ex/m_red/inn_red_bonus.c \
ex/m_red/man_red_bonus.c \
ex/m_red/man_dog_bonus.c \
ex/m_red/woman_dog_bonus.c \
ex/m_red/dog_pip_bonus.c \
ex/main_exc_bonus.c \
ex/main_exc_h_bonus.c \
ex/m_perror_bonus.c \
	\
ex/libft/ft_atoi_bonus.c \
ex/libft/ft_itoa_bonus.c \
ex/libft/ft_putchar_fd_bonus.c \
ex/libft/ft_putstr_fd_bonus.c \
ex/libft/ft_strncmp_bonus.c \
ex/libft/ft_split_bonus.c \
ex/libft/ft_strjoin_bonus.c \
ex/libft/ft_strchr_bonus.c \
ex/libft/ft_substr_bonus.c \
ex/libft/ft_strlcat_bonus.c \
ex/libft/ft_strlcpy_bonus.c \
ex/libft/ft_strlen_bonus.c \
ex/libft/ft_calloc_bonus.c \
ex/libft/ft_strndup_bonus.c \
ex/libft/ft_isdigit_bonus.c \
ex/libft/ft_isalnum_bonus.c \
ex/libft/ft_strdup_bonus.c \
ex/libft/ft_bzero_bonus.c \
ex/libft/ft_isalpha_bonus.c \
ex/libft/ft_memset_bonus.c \
ex/libft/ft_strcmp_bonus.c \
	\
includes/get_next_line/get_next_line_bonus_bonus.c \
includes/get_next_line/get_next_line_utils_bonus_bonus.c \
	\

OBJ = $(SRC:_bonus.c=.o)

CC = cc
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@echo "$(YELLOW)Linking...⛓$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) readline/libreadline.a readline/libhistory.a -o $(NAME) $(RDFLAGS)
	@echo "$(GREEN)Finished Compilation!✅$(RESET)"

%.o: %.c includes/header_bonus.h
	@echo "$(YELLOW)Compiling...🛠$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...🧹$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Its Clean! ✅$(RESET)"

fclean: clean
	@echo "$(YELLOW)Super Cleaning...🧼$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Its SUPER Clean! ✅$(RESET)"

re: fclean all

.PHONY: clean