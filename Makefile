SRCS 	= check_map.c ft_split.c main.c window.c utils.c utils2.c key_handle.c move.c error.c flood_fill.c

NAME	= so_long

CC 	= gcc
FLAGS	= -Wall -Werror -Wextra -g
MLX_FLAGS	= -L./minilibx-linux -lmlx -lX11 -lXext -lm

all:	$(NAME)
$(NAME):	
			@cd get_next_line && make
			@cd printf && make
			$(CC) $(FLAGS) $(SRCS) $(MLX_FLAGS) get_next_line/gnl.a  printf/libftprintf.a -o $(NAME)

clean:
		@cd get_next_line && make clean
		@cd printf && make clean

fclean:
		@cd get_next_line && make fclean
		@cd printf && make fclean
		rm -f $(NAME)
		clear

re:	fclean all