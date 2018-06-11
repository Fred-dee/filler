SRC_PATH = ./src/
INC_PATH = ./includes/
SRC = $(addprefix $(SRC_PATH), $(wildcard *.c))
OBJ = $(SRC:.c=.o)
OBJ_PATH = ./obj/
FLAGS = -Wall \
		-Werror \
		-Wextra
NAME = mdilapi.filler
LDFLAGS = -L./libft/
LFT = -lft

all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)
	@make -C./libft/
	gcc $(FLAGS) $(LDFLAGS) $(LFT) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc -I$(INC_PATH) -o $@ -c $<

clean : libclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

libclean:
	@make clean -C ./libft/

flcean: clean flibclean
	@rm -f $(NAME)

flibclean:
	@make fclean -C ./libft

re : clean all