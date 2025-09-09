NAME	= tst

SRC = tst.c \
	add_env.c grp_env.c int_env.c fre_env.c \
	del_env.c prn_env.c lvl_env.c \
	int_chr_env.c fre_chr_env.c \
	prn_port_env.c \
	../libft/ft_strlen.c \
	../libft/ft_calloc.c \
	../libft/ft_bzero.c \
	../libft/ft_memset.c \
	../libft/ft_strdup.c \
	../libft/ft_strndup.c \
	../libft/ft_strncmp.c \
	../libft/ft_strlcpy.c \
	../libft/ft_putstr_fd.c \
	../libft/ft_putchar_fd.c \
	../libft/ft_itoa.c \
	../libft/ft_isdigit.c \
	../libft/ft_strjoin.c \
	../libft/ft_strlcat.c \
	../libft/ft_strcmp.c \
	../m_perror.c \
	\

OBJ = $(SRC:.c=.o)

# ========== COMPILER SETTINGS ==========
CC			= cc -g
CFLAGS		= -Wall -Wextra -Werror
FSANITIZE	= -fsanitize=address -g

# ========== BUILD MODES ==========

all: run_status norm

norm: CFLAGS := $(CFLAGS)
norm: $(NAME)

noflags: CFLAGS :=
noflags: run_status $(NAME)

sanitize: CFLAGS := $(CFLAGS) $(FSANITIZE)
sanitize: run_status $(NAME)

v: re
	valgrind --leak-check=full ./tst

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ========== PYTHON STATUS SCRIPT ==========
run_status:
	@echo "Running env_auto_status.py..."
	@python env_auto_status.py > /dev/null 2>&1 || echo "⚠️ Python error: check env_auto_status.py"

.PHONY: all norm noflags sanitize clean fclean re run_status
