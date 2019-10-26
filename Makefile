##
## EPITECH PROJECT, 2019
## AIA_gomoku_2019
## File description:
## Makefile
##

NAME =	pbrain-gomoku-ai

SRC =	sources/main.cpp		\
		sources/Launcher.cpp		\
		sources/Protocol.cpp	\
		sources/brain/Board.cpp	\
		sources/brain/Brain.cpp	\
		sources/brain/Heuristic.cpp\

OBJ =	$(SRC:.cpp=.o)

INC =	-I sources/ sources/brain/

CXXFLAGS=	$(INC) -W -Wall -Wextra

CXX =	g++

RM	=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

clean:
	make clean -C unit_tests/
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C unit_tests/
	$(RM) $(OBJ) $(NAME)

re:	fclean all

tests_run:
	make -C unit_tests/
	./unit_tests/units