NAME = minishell
NAME = minishell_bonus
CFLAGS = -Wall -Werror -Wextra -I./readline/include
RDFLAGS = -lreadline -lncurses
SRC = mandatory/src/minishell.c \
mandatory/parse/tokenize.c \
mandatory/parse/delimiters.c \
mandatory/parse/filter.c \
mandatory/parse/checker.c \
mandatory/parse/lst_functions.c \
mandatory/parse/operators.c \
mandatory/utils/libft_func.c \
mandatory/utils/libft_func2.c \
mandatory/parse/seperator.c \
mandatory/parse/money_expansion.c \
mandatory/utils/libft_func3.c \
mandatory/parse/striper.c \
mandatory/parse/last_lst_creater.c \
mandatory/parse/lst_functions_2.c \
mandatory/utils/libft_func4.c \
mandatory/utils/libft_func5.c \
mandatory/utils/libft_func6.c \
mandatory/ex/m_red/expand_str.c \
	\
mandatory/ex/m_bul/cmd_exit.c \
mandatory/ex/m_bul/cmd_cd.c \
mandatory/ex/m_bul/cmd_echo.c \
mandatory/ex/m_bul/cmd_env.c \
mandatory/ex/m_bul/cmd_export.c \
mandatory/ex/m_bul/cmd_pwd.c \
mandatory/ex/m_bul/cmd_unset.c \
mandatory/ex/m_env/add_env.c \
mandatory/ex/m_env/del_env.c \
mandatory/ex/m_env/fre_env.c \
mandatory/ex/m_env/gky_env.c \
mandatory/ex/m_env/grp_env.c \
mandatory/ex/m_env/int_env.c \
mandatory/ex/m_env/lvl_env.c \
mandatory/ex/m_env/prn_env.c \
mandatory/ex/m_env/int_chr_env.c \
mandatory/ex/m_env/fre_chr_env.c \
mandatory/ex/m_env/prn_port_env.c \
mandatory/ex/m_exc/ex_rish.c \
mandatory/ex/m_exc/ex_bults.c \
mandatory/ex/m_exc/ex_cpro.c \
mandatory/ex/m_exc/ex_there.c \
mandatory/ex/m_exc/ex_crnt.c \
mandatory/ex/m_exc/ex_waitkid.c \
mandatory/ex/m_red/src_red.c \
mandatory/ex/m_red/red_red.c \
mandatory/ex/m_red/apn_red.c \
mandatory/ex/m_red/inn_red.c \
mandatory/ex/m_red/man_red.c \
mandatory/ex/m_red/man_dog.c \
mandatory/ex/m_red/woman_dog.c \
mandatory/ex/m_red/dog_pip.c \
mandatory/ex/main_exc.c \
mandatory/ex/main_exc_h.c \
mandatory/ex/m_perror.c \
	\
mandatory/ex/libft/ft_atoi.c \
mandatory/ex/libft/ft_itoa.c \
mandatory/ex/libft/ft_putchar_fd.c \
mandatory/ex/libft/ft_putstr_fd.c \
mandatory/ex/libft/ft_strncmp.c \
mandatory/ex/libft/ft_split.c \
mandatory/ex/libft/ft_strjoin.c \
mandatory/ex/libft/ft_strchr.c \
mandatory/ex/libft/ft_substr.c \
mandatory/ex/libft/ft_strlcat.c \
mandatory/ex/libft/ft_strlcpy.c \
mandatory/ex/libft/ft_strlen.c \
mandatory/ex/libft/ft_calloc.c \
mandatory/ex/libft/ft_strndup.c \
mandatory/ex/libft/ft_isdigit.c \
mandatory/ex/libft/ft_isalnum.c \
mandatory/ex/libft/ft_strdup.c \
mandatory/ex/libft/ft_bzero.c \
mandatory/ex/libft/ft_isalpha.c \
mandatory/ex/libft/ft_memset.c \
mandatory/ex/libft/ft_strcmp.c \
	\
mandatory/includes/get_next_line/get_next_line_bonus.c \
mandatory/includes/get_next_line/get_next_line_utils_bonus.c \
	\

BSRC = bonus/src/minishell_bonus.c \
bonus/parse/tokenize_bonus.c \
bonus/parse/delimiters_bonus.c \
bonus/parse/filter_bonus.c \
bonus/parse/checker_bonus.c \
bonus/parse/lst_functions_bonus.c \
bonus/parse/operators_bonus.c \
bonus/utils/libft_func_bonus.c \
bonus/utils/libft_func2_bonus.c \
bonus/parse/seperator_bonus.c \
bonus/parse/money_expansion_bonus.c \
bonus/utils/libft_func3_bonus.c \
bonus/parse/star_expansion_bonus.c \
bonus/parse/striper_bonus.c \
bonus/parse/last_lst_creater_bonus.c \
bonus/parse/lst_functions_2_bonus.c \
bonus/utils/libft_func4_bonus.c \
bonus/utils/libft_func5_bonus.c \
bonus/utils/libft_func6_bonus.c \
bonus/ex/m_red/expand_str_bonus.c \
	\
bonus/ex/m_bul/cmd_exit_bonus.c \
bonus/ex/m_bul/cmd_cd_bonus.c \
bonus/ex/m_bul/cmd_echo_bonus.c \
bonus/ex/m_bul/cmd_env_bonus.c \
bonus/ex/m_bul/cmd_export_bonus.c \
bonus/ex/m_bul/cmd_pwd_bonus.c \
bonus/ex/m_bul/cmd_unset_bonus.c \
bonus/ex/m_env/add_env_bonus.c \
bonus/ex/m_env/del_env_bonus.c \
bonus/ex/m_env/fre_env_bonus.c \
bonus/ex/m_env/gky_env_bonus.c \
bonus/ex/m_env/grp_env_bonus.c \
bonus/ex/m_env/int_env_bonus.c \
bonus/ex/m_env/lvl_env_bonus.c \
bonus/ex/m_env/prn_env_bonus.c \
bonus/ex/m_env/int_chr_env_bonus.c \
bonus/ex/m_env/fre_chr_env_bonus.c \
bonus/ex/m_env/prn_port_env_bonus.c \
bonus/ex/m_exc/ex_rish_bonus.c \
bonus/ex/m_exc/ex_bults_bonus.c \
bonus/ex/m_exc/ex_cpro_bonus.c \
bonus/ex/m_exc/ex_there_bonus.c \
bonus/ex/m_exc/ex_crnt_bonus.c \
bonus/ex/m_exc/ex_waitkid_bonus.c \
bonus/ex/m_red/src_red_bonus.c \
bonus/ex/m_red/red_red_bonus.c \
bonus/ex/m_red/apn_red_bonus.c \
bonus/ex/m_red/inn_red_bonus.c \
bonus/ex/m_red/man_red_bonus.c \
bonus/ex/m_red/man_dog_bonus.c \
bonus/ex/m_red/woman_dog_bonus.c \
bonus/ex/m_red/dog_pip_bonus.c \
bonus/ex/main_exc_bonus.c \
bonus/ex/main_exc_h_bonus.c \
bonus/ex/m_perror_bonus.c \
	\
bonus/ex/libft/ft_atoi_bonus.c \
bonus/ex/libft/ft_itoa_bonus.c \
bonus/ex/libft/ft_putchar_fd_bonus.c \
bonus/ex/libft/ft_putstr_fd_bonus.c \
bonus/ex/libft/ft_strncmp_bonus.c \
bonus/ex/libft/ft_split_bonus.c \
bonus/ex/libft/ft_strjoin_bonus.c \
bonus/ex/libft/ft_strchr_bonus.c \
bonus/ex/libft/ft_substr_bonus.c \
bonus/ex/libft/ft_strlcat_bonus.c \
bonus/ex/libft/ft_strlcpy_bonus.c \
bonus/ex/libft/ft_strlen_bonus.c \
bonus/ex/libft/ft_calloc_bonus.c \
bonus/ex/libft/ft_strndup_bonus.c \
bonus/ex/libft/ft_isdigit_bonus.c \
bonus/ex/libft/ft_isalnum_bonus.c \
bonus/ex/libft/ft_strdup_bonus.c \
bonus/ex/libft/ft_bzero_bonus.c \
bonus/ex/libft/ft_isalpha_bonus.c \
bonus/ex/libft/ft_memset_bonus.c \
bonus/ex/libft/ft_strcmp_bonus.c \
	\
bonus/includes/get_next_line/get_next_line_bonus_bonus.c \
bonus/includes/get_next_line/get_next_line_utils_bonus_bonus.c \
	\

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Linking...⛓$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) readline/libreadline.a readline/libhistory.a -o $(NAME) $(RDFLAGS)
	@echo "$(GREEN)Finished Compilation!✅$(RESET)"

$(BNAME): $(BOBJ)
	@echo "$(YELLOW)Linking...⛓$(RESET)"
	@$(CC) $(CFLAGS) $(BOBJ) readline/libreadline.a readline/libhistory.a -o $(BNAME) $(RDFLAGS)
	@echo "$(GREEN)Finished Compilation!✅$(RESET)"

mandatory/%.o: mandatory/%.c mandatory/includes/header.h
	@echo "$(YELLOW)Compiling...🛠$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/includes/header_bonus.h
	@echo "$(YELLOW)Compiling...🛠$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...🧹$(RESET)"
	@rm -f $(OBJ)
	@rm -f $(BOBJ)
	@echo "$(GREEN)Its Clean! ✅$(RESET)"

fclean: clean
	@echo "$(YELLOW)Super Cleaning...🧼$(RESET)"
	@rm -f $(NAME)
	@rm -f $(BNAME)
	@echo "$(GREEN)Its SUPER Clean! ✅$(RESET)"

re: fclean all

.PHONY: clean