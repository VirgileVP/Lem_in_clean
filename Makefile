# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/09 13:35:26 by zseignon     #+#   ##    ##    #+#        #
#    Updated: 2020/02/11 10:50:26 by zseignon    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in

CC = gcc
CFLAGS = #-Wall -Werror -Wextra 
INCLUDES = -I inc -I libft/inc

LIB = libft/libft.a
OBJ_DIR = ./obj/
SRC_DIR = ./src/

SRC = 	main.c \
		ant_convert.c\
		ant_dup.c\
		ant_kill.c\
		ant_scout.c\
		barr.c\
		bf.c\
		check_error_utils.c\
		check_error.c\
		eval.c\
		multipath.c\
		oneshot.c\
		parse_tool.c\
		parse.c\
		pathfinding.c\
		print_path.c\
		unipath.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:$(NAME)

$(NAME):$(OBJ) $(LIB)
	$(CC) $(CFLAGS) -L libft -l ft $^ -o $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(LIB):
		make -C libft

clean:
		make clean -C libft

fclean:clean
		make fclean -C libft
		rm -rf $(OBJ)
		rm -f $(NAME)

re:fclean
		make all


.PHONY: clean fclean re all
