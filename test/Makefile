NAME = test

all : $(NAME)

$(NAME) : test_main.c
	gcc -Wall -Werror -Wextra ../includes/filler.h ../src/get_next_line.c \
		../src/map.c ../src/piece.c ../src/play.c ../src/heuristic.c ../src/evaluation.c ../src/helper_functions.c -L. -lft test_main.c
	find ../ -name "*.h.gch" -delete

run : $(NAME)
	./a.out