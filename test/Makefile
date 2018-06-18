NAME = test

all : $(NAME)

$(NAME) : test_main.c
	gcc ../includes/filler.h ../src/get_next_line.c \
		../src/map.c ../src/piece.c ../src/play.c -L. -lft test_main.c

run : $(NAME)
	./a.out