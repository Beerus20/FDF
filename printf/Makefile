NAME		= libftprintf.a
FUNCS		= \
	ft_utils_bonus.c				\
	ft_get_flags_bonus.c			\
	ft_add_bonus.c					\
	ft_get_len_bonus.c

BONUS_TYPES_FUNC = \
	ft_char_bonus.c					\
	ft_str_bonus.c					\
	ft_number_bonus.c				\
	ft_unumber_bonus.c				\
	ft_hex_bonus.c					\
	ft_pointer_bonus.c

SRC_OBJ				= ./output/ft_printf.o
BONUS_OBJS			= $(FUNCS:%.c=./output/%.o)
BONUS_TYPES_OBJS	= $(BONUS_TYPES_FUNC:%.c=./output/%.o)
FLAGS				= -Wall -Wextra -Werror
CC					= cc -g

all						:	$(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

./output/%.o			:	./functions/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/%.o			:	./functions/types/%.c
							$(CC) $(FLAGS) -c $< -o $@

$(SRC_OBJ)				:
							$(CC) $(FLAGS) -c ft_printf.c -o $@

$(NAME)					:	output $(BONUS_TYPES_OBJS) $(BONUS_OBJS) $(SRC_OBJ)
							ar -rcs $(NAME) $(BONUS_TYPES_OBJS) $(BONUS_OBJS) $(SRC_OBJ)

clean					:
							rm -rf $(SRC_OBJ) $(BONUS_OBJS) $(BONUS_TYPES_OBJS)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all
.PHONY					:	all clean fclean bonus re
