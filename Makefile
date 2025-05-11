NAME = rush-02

SRC = src/main.c src/convert.c src/convert_utils.c src/ft_split.c src/main_helpers.c src/parser.c src/parser_fill.c src/parser_utils.c src/str_to_nbr.c src/str_add.c src/utils.c src/ft_strcmp_numbers.c src/str_add_utils.c src/str_subtract.c

# Objs recebe os mesmos valores de SRC, trocando .c por .o
OBJS = ${SRC:.c=.o}

CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

# Regra para compilar arquivos .c em .o
.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# Quando make é chamado sem argumentos
all:	${NAME}

# Limpeza dos arquivos .o
clean:
		${RM} ${OBJS}

# Limpeza de arquivos .o e do executável rush-02
fclean: clean
		${RM} ${NAME}

# Limpeza completa e recriação do executável
re: fclean all

# Informa que essas regras sempre devem ser executadas
.PHONY: all clean fclean re
