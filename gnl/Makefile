NAME	= libgnl.a
FILES	= get_next_line.c get_next_line_utils.c
OBJS	= $(FILES:%.c=./output/%.o)
CFLAGS	= -Wall -Wextra -Werror
CC		= cc -g

all		: $(NAME)

output	:
			@if [ ! -d output ]; then\
				mkdir output;\
			fi

./output/%.o		: %.c | output
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
			ar -rcs $@ $(OBJS)

clean	:
			rm -rf $(OBJS)

fclean	: clean
			rm -rf $(NAME)

re		: fclean $(NAME)

.PHONY	: all re clean fclean