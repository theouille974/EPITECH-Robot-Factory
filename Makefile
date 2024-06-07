##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	$(shell find ./src/ -name '*.c' -not -name 'main.c')

IFLAGS	=	-I include/ -L lib/ -lmy

CFLAGS	=	-W -Wall -Werror -Wextra $(IFLAGS) -g3

TEST_FLAGS	=	-lcriterion --coverage

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_SRC	=	$(shell find ./tests/ -name '*.c')

TEST	=	unit_tests

all:	$(OBJ)
	make -C lib/my/	all
	gcc src/main.c $(OBJ) $(CFLAGS) -o $(NAME)

debug:
	make -C lib/my/ all
	gcc src/main.c $(SRC) $(CFLAGS) -o $(NAME) -g3 -ggdb

clean:
	rm -f $(OBJ)

fclean:	clean
	make -C lib/my/	fclean
	rm -f libmy.a $(NAME)

re:	fclean all

tests_run:
	make -C lib/my all
	gcc $(SRC) tests/units_test.c $(TEST_FLAGS) $(CFLAGS) $(IFLAGS) -o $(TEST)
	./unit_tests && gcovr -e tests/ && gcovr -e tests/ -b
	rm -f unit_tests
	rm -f *.gcda *.gcno *.gcda
