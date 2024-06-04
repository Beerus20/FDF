NAME		= fdf
FILES		= main.c ft_show_map.c ft_get_params.c
OBJS		= $(FILES:%.c=./output/%.o)
CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror
LIBX_FLAGS	= -lXext -lX11 -lm -lz

#LIB
P_MINILIBX	= ./minilibx
P_GNL		= ./gnl
P_LIBFT		= ./libft
P_PRINTF	= ./printf
MINILIBX	= -I $(P_MINILIBX) -L $(P_MINILIBX) -lmlx
GNL			= -I $(P_GNL) -L $(P_GNL) -lgnl
LIBFT		= -I $(P_LIBFT) -L $(P_LIBFT) -lft
PRINTF		= -I $(P_PRINTF) -L $(P_PRINTF) -lftprintf

all				: $(NAME)

output			:
					@if [ ! -d output ]; then\
						mkdir output; \
					fi

./output/%.o	: %.c | output
					$(CC)  -c $< -o $@

test\:%			:
					valgrind --leak-check=full --track-origins=yes ./fdf maps/$(subst test:,,$@)

$(NAME)			: $(OBJS)
					make -C $(P_MINILIBX) && make -C $(P_GNL) && make -C $(P_LIBFT) && make -C $(P_PRINTF)
					$(CC) $(OBJS) $(MINILIBX) $(GNL) $(LIBFT) $(PRINTF) $(LIBX_FLAGS) -o $@

norme			:
					norminette $(P_GNL) $(P_LIBFT) $(P_PRINTF)

clean			:
					make clean -C $(P_MINILIBX)
					make clean -C $(P_GNL)
					make clean -C $(P_LIBFT)
					make clean -C $(P_PRINTF)
					rm -rf $(OBJS)

fclean			: clean
					make fclean -C $(P_GNL)
					make fclean -C $(P_LIBFT)
					make fclean -C $(P_PRINTF)
					rm -rf $(NAME)

re				: fclean $(NAME)

.PHONY			: all clean fclean re