# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:35:26 by zseignon          #+#    #+#              #
#    Updated: 2020/05/05 11:08:08 by zseignon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in

CC				=	gcc
CFLAGS			=	-O3 -march=native -Wall -Wextra

SRC_DIR			=	src

GRAPH_SRC_DIR	=	$(SRC_DIR)/graph
GRAPH_SRC_NAME	=	graph_access.c\
					graph_utils.c\
					iter_init.c\
					iter_next.c\
					iter.c
GRAPH_SRC		=	$(addprefix $(GRAPH_SRC_DIR)/, $(GRAPH_SRC_NAME))

PARSE_SRC_DIR	=	$(SRC_DIR)/parse
PARSE_SRC_NAME	=	check_error_utils.c\
					check_error.c\
					parse_tool.c\
					parse.c
PARSE_SRC		=	$(addprefix $(PARSE_SRC_DIR)/, $(PARSE_SRC_NAME))

PRINT_SRC_DIR	=	$(SRC_DIR)/print
PRINT_SRC_NAME	=	multipath.c\
					multipath2.c\
					oneshot.c\
					resolve_tool.c\
					unipath.c
PRINT_SRC		=	$(addprefix $(PRINT_SRC_DIR)/, $(PRINT_SRC_NAME))

QUEUE_SRC_DIR	=	$(SRC_DIR)/queue
QUEUE_SRC_NAME	=	queue_add.c\
					queue_base.c\
					queue_pop.c
QUEUE_SRC		=	$(addprefix $(QUEUE_SRC_DIR)/, $(QUEUE_SRC_NAME))

SOLVE_SRC_DIR	=	$(SRC_DIR)/solve
SOLVE_SRC_NAME	=	node_bypass.c\
					node_mark.c\
					pathfinding.c\
					ft_qsort.c
SOLVE_SRC		=	$(addprefix $(SOLVE_SRC_DIR)/, $(SOLVE_SRC_NAME))

WAY_SRC_DIR		=	$(SRC_DIR)/way
WAY_SRC_NAME	=	way_ant_dispatch.c\
					way_reverse_new.c\
					way_set_restore.c\
					way_set.c\
					way.c
WAY_SRC			=	$(addprefix $(WAY_SRC_DIR)/, $(WAY_SRC_NAME))

MISC_SRC_DIR	=	$(SRC_DIR)/misc
MISC_SRC_NAME	=	ft_count_words.c\
					ft_is_strdigit.c\
					ft_isspace.c\
					get_next_line.c\
					nmatch.c
MISC_SRC		=	$(addprefix $(MISC_SRC_DIR)/, $(MISC_SRC_NAME))

SRC_NAME		=	$(GRAPH_SRC_NAME)\
					$(PARSE_SRC_NAME)\
					$(PRINT_SRC_NAME)\
					$(QUEUE_SRC_NAME)\
					$(SOLVE_SRC_NAME)\
					$(WAY_SRC_NAME)\
					$(MISC_SRC_NAME)\
					main.c

OBJ_DIR			=	obj
OBJ_NAME		=	$(SRC_NAME:.c=.o)
OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

INC_NAME		=	inc/check_error.h\
					inc/graph.h\
					inc/lemin.h\
					inc/parsing.h\
					inc/print.h\
					inc/resolve_print.h\
					inc/queue.h\
					inc/solve.h\
					inc/way.h\
					inc/misc.h\
					inc/ft_qsort.h
INCFLAGS		=	-Iinc/ -Ilibft/inc/
LIBFLAGS		=	-Llibft/ -lft

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFLAGS)

$(OBJ_DIR)/%.o: $(GRAPH_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(PARSE_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(PRINT_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(QUEUE_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(SOLVE_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(WAY_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/%.o: $(MISC_SRC_DIR)/%.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_NAME) Makefile
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INCFLAGS)

clean:
		rm -rf $(OBJ_DIR)
		make -C libft/ clean

fclean:
		rm -rf $(OBJ_DIR)
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
