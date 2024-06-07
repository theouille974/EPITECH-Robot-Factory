##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Testing Makefile
##

CC	=	gcc

LIB 	= 	$(wildcard *.c)

OBJ 	= 	$(LIB:.c=.o)

IFLAGS	=	-I include/

CFLAGS	=	-W -Wall -Werror -Wextra $(IFLAGS)

LIBNAME = 	libmy.a

all:	$(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	cp $(LIBNAME) ../

clean:
	rm -f $(OBJ)

fclean: 	clean
	rm -f $(LIBNAME)
	rm -f ../$(LIBNAME)
	rm -f *~

re: 	fclean all
