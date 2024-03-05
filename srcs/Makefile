NAME = srcs.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
AR = ar
ARFLAGS = -rcs

SRC = ft_printf.c \
		ft_printf_src.c \
		ft_printf_src2.c \
		get_next_line.c \
		get_next_line_utils.c \
		

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) ./ft_printf.h
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re