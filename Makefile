NAME = test.out
NAME_BONUS = test_bonus.out
# FLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=2
#FLAGS = -Wall -Werror -Wextra -fsanitize=address -D BUFFER_SIZE=8
SRCS = get_next_line.c get_next_line_utils.c tests/main.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c tests/main.c

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRCS)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

$(NAME_BONUS): $(SRCS_BONUS)
	gcc $(FLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

fclean:
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

test:
	make fclean
	make $(NAME)
	./$(NAME)

test_bonus:
	make fclean
	make $(NAME_BONUS)
	./$(NAME_BONUS)		
