##
## EPITECH PROJECT, 2022
## CWorkshopLib
## File description:
## No file there, just an epitech header example.
## You can even have multiple lines if you want!
##

SRC 	=	utils/utils.c			\
			rendering/rendering.c	\
			rendering/rendering_utils.c		\
			events/events.c			\
			events/events_creation.c		\
			events/events_utils.c	\
			events/free.c			\
			scenes/scene.c			\
			scenes/entity_sorting.c	\
			game/game_basics.c		\
			game/add_scene.c		\
			game/scene_manager.c	\
			game/variable_manager.c \
			game/variable_op.c		\
			params/params.c			\
			params/checking.c		\
			params/parsing.c		\
			entities/entity.c		\
			entities/entity_creation.c		\
			entities/entities_utils.c		\
			entities/collision.c	\
			entities/collision_updater.c \
			entities/collision_checker.c \
			entities/texture_management.c \
			gui/gui.c	\
			gui/text.c

OBJ		=	*.o

NAME	=	libgame.a

all: $(NAME) clean

$(NAME):
	gcc -c $(SRC) -g -lm -I../my
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include
	cp game.h ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/game.h

re: fclean all
