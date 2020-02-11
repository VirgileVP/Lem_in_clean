# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/09 13:35:26 by zseignon     #+#   ##    ##    #+#        #
#    Updated: 2020/02/11 09:25:06 by zseignon    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 		=	lem-in
CC 			=	gcc
CFLAGS		=	-O3 -march=native -Wall -Werror -Wextra

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc

SRC_NAME	=	main.c\
				ant_convert.c\
				ant_dup.c\
				ant_kill.c\
				ant_scout.c\
				barr.c\
				bf.c\
				check_error.c\
				check_error_utils.c\
				eval.c\
				parse.c\
				parse_tool.c\
				pathfinding.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	lem_in.h\
				check_error.h\
				parse.h\
				pathfinding.h

MKDIRP		=	mkdir -p

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
INC			=	$(addprefix $(INC_DIR)/, $(INC_NAME))

INC_FLAG	=	-I$(INC_DIR) -Ilibft/inc
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
