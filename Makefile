# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/09 13:35:26 by zseignon     #+#   ##    ##    #+#        #
#    Updated: 2019/10/09 13:47:19 by vveyrat-    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 		=	lem-in
CC 			=	gcc-9
CFLAGS		=	-O3 -march=native -Wall -Werror -Wextra

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc

SRC_NAME	=	main.c
				check

OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	lem_in.h\
				check_error.h

MKDIRP		=	mkdir -p

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
INC			=	$(addprefix $(INC_DIR)/, $(INC_NAME))

INC_FLAG	=	-I$(INC_DIR)
LIB_FAGS	=	-Llibft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIB_FLAGS) $< -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then $(MKDIRP) $(OBJ_DIR); fi
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
