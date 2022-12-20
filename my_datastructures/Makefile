##
## EPITECH PROJECT, 2022
## My DataStructures
## File description:
## No file there, just an epitech header example.
## You can even have multiple lines if you want!
##
			## Linked list
SRC 	=	linked_list/init_ll.c		\
			linked_list/getters_ll.c	\
			linked_list/operators_ll.c

			## Stack
SRC 	+=	stack/init_stack.c			\
			stack/operators_stack.c

			## Queue
SRC 	+=	queue/init_queue.c			\
			queue/operators_queue.c

NAME	=	libmy_ds.a

OBJ		=	*.o

all: $(NAME) clean

$(NAME):
	gcc -c $(SRC) -g
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include
	cp my_datastructures.h ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my_datastructures.h

re: fclean all
