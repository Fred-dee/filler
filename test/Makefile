NAME = test

all : $(NAME)

$(NAME) : test_main.c
	gcc -Wall -Werror -Wextra ../includes/filler.h ../src/get_next_line.c \
		../src/map.c ../src/piece.c ../src/play.c ../src/heuristic.c ../src/evaluation.c -L. -lft test_main.c

run : $(NAME)
	./a.out