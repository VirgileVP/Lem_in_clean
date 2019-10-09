# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/06 15:57:37 by zseignon     #+#   ##    ##    #+#        #
#    Updated: 2019/09/30 16:41:13 by zseignon    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 		=	libft.a
CC 			=	gcc-9
CFLAGS		=	-O3 -march=native -Wall -Werror -Wextra

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc

SRC_NAME	=	ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
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
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_read.c\
				ft_data_alloc.c\
				ft_read_alloc.c\
				ft_data_cat.c\
				ft_data_free.c\
				ft_read_free.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
INC_NAME	=	libft.h

MKDIRP		=	mkdir -p

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
INC			=	$(addprefix $(INC_DIR)/, $(INC_NAME))

INC_FLAG	=	-I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC)
	@if test ! -d $(OBJ_DIR); then $(MKDIRP) $(OBJ_DIR); fi
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
