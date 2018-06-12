SRC_PATH = ./src/
INC_PATH = ./includes/
SRC = $(wildcard $(SRC_PATH)*.c)
INCLUDES = $(wildcard $(INC_PATH)*.h)
OBJ = $(SRC:.c=.o)
OBJ_PATH = ./obj/
FLAGS = -Wall \
		-Werror \
		-Wextra
NAME = ./resources/players/mdilapi.filler
LDFLAGS = -L./libft/
LFT = -lft
vpath %.o ./src

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@make -C./libft/
	gcc $(FLAGS) $(LDFLAGS) $(LFT) $(wildcard *.o) -o $@

$(SRC_PATH)%.o: $(SRC)
	gcc -c $(FLAGS) -I$(INCLUDES) $(SRC) 

clean : libclean
	@rm -f $(OBJ)

libclean:
	@make clean -C ./libft/

flcean: clean flibclean
	@rm -f $(NAME)

flibclean:
	@make fclean -C ./libft

re : clean all