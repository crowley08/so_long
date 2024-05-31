SRCS			=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_put_u_nbr.c \
					ft_putadd.c ft_put_low_hex.c ft_put_up_hex.c ft_format.c \
					ft_printf.c
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all 


.PHONY:			all clean fclean re
