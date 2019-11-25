##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

CC		=	gcc

FLAGS		=	-Werror -Wall -Wextra

MAIN		=	main.c

SRC		=	minishell.c \
			minishell_text.c \
			minishell_tools.c \
			minishell_command.c

OBJ     	=       $(SRC:.c=.o) $(MAIN:.c=.o)

NAME    	=       mysh

INCLUDE 	=       ./include

LIB_FOLDER      =       ./lib/my

LIB_NAME        =       my

TEST		=	tests/test_bootstrap.c

TEST_FLAG	=	--coverage -lcriterion

TEST_NAME	=	unit_tests

OBJ_TEST	=	$(SRC:.c=.o) $(TEST:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_FOLDER)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE) -L$(LIB_FOLDER) -l$(LIB_NAME)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TEST)
		cd $(LIB_FOLDER) && make clean
		rm -f *~
		rm -f *#

fclean:		clean
		cd $(LIB_FOLDER) && make fclean
		rm -f $(NAME)
		rm -f $(TEST_NAME)
		rm -f *.gcda
		rm -f *.gcno

tests_run:	$(OBJ_TEST)
		make -C $(LIB_FOLDER)
		$(CC) $(FLAGS) -o $(TEST_NAME) $(OBJ_TEST) $(TEST_FLAG) -I$(INCLUDE) -L$(LIB_FOLDER) -l$(LIB_NAME) && ./$(TEST_NAME)

re:		fclean all
		cd $(LIB_FOLDER) && make re

auteur:
		echo $(USER) > auteur

.PHONY: 	all clean fclean re tests_run
