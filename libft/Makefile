# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 15:18:47 by zseignon          #+#    #+#              #
#    Updated: 2020/05/01 17:35:06 by user42           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME					=	libft.a

CC						=	gcc
CFLAGS					=	-O3 -march=native -Wall -Wextra

SRC_DIR					=	src
OBJ_DIR					=	obj

#	FT_VECTOR_DECLARATION	####################################################
FT_VECT_SRC_DIR			=	$(SRC_DIR)/ft_vect
FT_VECT_SRC_NAME		=	ft_vect_access.c\
							ft_vect_add.c\
							ft_vect_man.c\
							ft_vect_pop.c\
							ft_vect_sort.c\
							ft_vect_utils.c
FT_VECT_SRC				=	$(addprefix $(FT_VECT_SRC_DIR)/, $(FT_VECT_SRC_NAME))

#	FT_MEMORY_MANAGEMENT_DECLARATION	########################################
FT_MEMMAN_SRC_DIR		=	$(SRC_DIR)/ft_memman
FT_MEMMAN_SRC_NAME		=	ft_memory_manager.c\
							ft_malloc.c\
							ft_nomm_realloc.c\
							ft_free.c
FT_MEMMAN_SRC			=	$(addprefix $(FT_MEMMAN_SRC_DIR)/, $(FT_MEMMAN_SRC_NAME))

#	FT_CMP_DECLARATION	########################################################
FT_CMP_SRC_DIR			=	$(SRC_DIR)
FT_CMP_SRC_NAME			=	ft_cmp.c
FT_CMP_SRC				=	$(addprefix $(FT_CMP_SRC_DIR)/, $(FT_CMP_SRC_NAME))

#	FT_ERROR_DECLARATION	####################################################
FT_ERROR_SRC_DIR		=	$(SRC_DIR)/ft_error
FT_ERROR_SRC_NAME		=	ft_error.c
FT_ERROR_SRC			=	$(addprefix $(FT_ERROR_SRC_DIR)/, $(FT_ERROR_SRC_NAME))

#	LIBC_DECLARATION	########################################################
LIBC_SRC_DIR			=	$(SRC_DIR)/libc
LIBC_SRC_NAME			=	ft_atoi.c\
							ft_bzero.c\
							ft_isalnum.c\
							ft_isalpha.c\
							ft_isascii.c\
							ft_isdigit.c\
							ft_isprint.c\
							ft_itoa.c\
							ft_memalloc.c\
							ft_memccpy.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_memcpy.c\
							ft_memdup.c\
							ft_memdel.c\
							ft_memmove.c\
							ft_memset.c\
							ft_putchar.c\
							ft_putchar_fd.c\
							ft_putendl.c\
							ft_putendl_fd.c\
							ft_putnbr.c\
							ft_putnbr_fd.c\
							ft_putstr.c\
							ft_putstr_fd.c\
							ft_strcat.c\
							ft_strchr.c\
							ft_strclr.c\
							ft_strcmp.c\
							ft_strcpy.c\
							ft_strcspn.c\
							ft_strdel.c\
							ft_strdup.c\
							ft_strequ.c\
							ft_striter.c\
							ft_striteri.c\
							ft_strjoin.c\
							ft_strlcat.c\
							ft_strlen.c\
							ft_strmap.c\
							ft_strmapi.c\
							ft_strncat.c\
							ft_strncmp.c\
							ft_strncpy.c\
							ft_strnequ.c\
							ft_strnew.c\
							ft_strnstr.c\
							ft_strrchr.c\
							ft_strsplit.c\
							ft_strstr.c\
							ft_strsub.c\
							ft_strtrim.c
LIBC_SRC				=	$(addprefix $(LIBC_SRC_DIR)/, $(LIBC_SRC_NAME))

#	SRC_DECLARATION	############################################################
SRC_NAME				=	$(FT_VECT_SRC_NAME)\
							$(FT_MEMMAN_SRC_NAME)\
							$(FT_CMP_SRC_NAME)\
							$(FT_ERROR_SRC_NAME)\
							$(LIBC_SRC_NAME)

SRC						=	$(FT_VECT_SRC)\
							$(FT_MEMMAN_SRC)\
							$(FT_CMP_SRC)\
							$(FT_ERROR_SRC)\
							$(LIBC_SRC)

#	OBJ_DECLARATION	############################################################
OBJ_NAME				=	$(SRC_NAME:.c=.o)
OBJ						=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

#	HEADER	####################################################################
INC_DIR					=	inc
INC_NAME				=	ft_cmp.h\
							ft_error.h\
							ft_memman.h\
							ft_vector.h\
							libft.h\
							typedef.h\
							libc.h
INC						=	$(addprefix $(INC_DIR)/, $(INC_NAME))
INC_FLAG				=	-I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) $(INC_FLAG) -c -o test.o test.c
	$(CC) $(CFLAGS) -L./ -lft test.o -o a.out
	./a.out

#	FT_VECTOR_COMPILATION	####################################################
$(OBJ_DIR)/%.o: $(FT_VECT_SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INC_FLAG)

#	FT_MEMORY_MANAGEMENT_COMPILATION	########################################
$(OBJ_DIR)/%.o : $(FT_MEMMAN_SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INC_FLAG)

#	FT_CMP_COMPILATION	########################################################
$(OBJ_DIR)/%.o : $(FT_CMP_SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INC_FLAG)

#	FT_ERROR_COMPILATION	####################################################
$(OBJ_DIR)/%.o : $(FT_ERROR_SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INC_FLAG)

#	LIBC_COMPILATION	########################################################
$(OBJ_DIR)/%.o : $(LIBC_SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then mkdir -p $(OBJ_DIR); fi
	$(CC) $(CFLAGS) -o $@ -c $< $(INC_FLAG)
	
.PHONY: test clean fclean re

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all