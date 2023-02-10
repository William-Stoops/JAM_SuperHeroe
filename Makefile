##
## EPITECH PROJECT, 2023
## JAM_SuperHeroe
## File description:
## Makefile
##

CLASS	=	./src/class/Game.cpp \
			./src/class/Mob.cpp \

SRC	=	src/main.cpp	\
		src/SFML/Sfml.cpp \
		$(CLASS) \
		src/Character.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME =		EpitechJam

CPPFLAGS	=	-Wall -Wextra

all: $(OBJ)
	g++ -std=c++20 $(CPPFLAGS) $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

mac:
	g++ -std=c++20 $(CFLAGS) $(SRC) -lncurses -I ~/SFML/include -L ~/SFML/lib \
	-lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,/Users/noatrachez/SFML/lib \
	-o $(NAME)

re:	fclean all