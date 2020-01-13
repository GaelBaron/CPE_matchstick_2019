##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

SRC	=       src/matchstick.c			\
		src/mapping.c				\
		src/game.c				\
		src/error.c				\
		src/ai.c

MAIN 	=	src/main.c

TEST 	=	tests/tests_error_gestion.c	\

OBJ     =       $(SRC:.c=.o)

OBJ2    =       $(MAIN:.c=.o)

BUG	=	-Wall -Wextra -Werror -g3

UTESTS	=	-lcriterion --coverage

NAME    =       matchstick

$(NAME):        $(OBJ) $(OBJ2)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(OBJ2) -L./lib -lmy

all:    $(NAME)

debug:          $(OBJ) $(OBJ2)
	gcc -o $(NAME) $(OBJ) $(OBJ2) -L./lib -lmy $(BUG)

tests_run:          $(OBJ)
	make -C lib/my/
	gcc -o unit_tests $(TEST) $(OBJ) -L./lib -lmy $(BUG) $(UTESTS)
	./unit_tests

clean:
	make clean -C lib/my/
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)
	rm -f libmy.a
	rm -f unit_tests

re:     clean all

.PHONY: all clean fclean re test_run debug
