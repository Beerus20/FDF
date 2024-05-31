NAME		= fdf
FILES		= main.c
OBJS		= $(FILES:%.c=./output/%.o)
MINILIBX	= -I ./minilibx -L ./minilibx/ -lmlx
CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror
LIBX_FLAGS	= -lXext -lX11 -lm -lz

all			: $(NAME)

output		:
				@if [ ! -d output ]; then\
					mkdir output; \
				fi

./output/%.o	: %.c | output
				$(CC)  -c $< -o $@

# test		:

$(NAME)		: $(OBJS)
				make -C ./minilibx
				$(CC) $(OBJS) $(MINILIBX) $(LIBX_FLAGS) -o $@

clean		:
				make clean -C ./minilibx
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean $(NAME)

.PHONY		: all clean fclean re