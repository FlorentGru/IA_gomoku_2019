##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## UnitTest Makefile
##

SRC_DIR		=	../sources

SRC		=	$(SRC_DIR)/brain/Brain.cpp	\
			$(SRC_DIR)/brain/Board.cpp	\
			$(SRC_DIR)/Launcher.cpp		\
			$(SRC_DIR)/Protocol.cpp		\
			$(SRC_DIR)/brain/Heuristic.cpp	\

SRC_UT_DIR	=	./sources

SRC_UT		= 	$(SRC_UT_DIR)/test_brain.cpp	\
				$(SRC_UT_DIR)/test_board.cpp	\
				$(SRC_UT_DIR)/test_protocol.cpp

INC	=	-I ../sources/ -I ../sources/brain/

OBJ		= 	$(SRC:%.cpp=%.o) $(SRC_UT:%.cpp=%.o)

CXXFLAGS	= 	$(INC) -Wall -Wextra --coverage

LDFLAGS		= 	-lcriterion -lgcov

CXX		=	g++

RM		=	rm -f

NAME		=	units

all		: 	$(NAME)

$(NAME)		: 	$(OBJ)
				$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ)

fclean		: 	clean
			$(RM) $(NAME)
			$(RM) $(SRC_UT_DIR)/*.gc*
			$(RM) $(SRC_DIR)/*.gc*

re		: 	fclean all
