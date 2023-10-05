# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohadmin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 19:15:34 by ohadmin           #+#    #+#              #
#    Updated: 2023/10/02 19:23:53 by ohadmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = fractol.a

# Flags al compilar
FLAGS = -g -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rcs

# Include
INC = fractol.h

# Functions
SRC = main.c

# Objects
OBJ = $(SRC:.c=.o)

MAIN = main.c

#### mlx
LMLX_DIR = mlx_linux/
LMLX = libmlx.a
#DEPS = $(addprefix $(LMLX_DIR), $(LMLX))

#### Compilacion del programa ####

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o exe

#	cc migration from tutorial
%.o: %.c Makefile
	@echo Compiling $<...
	$(CC) -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo Compilation complete

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

test:
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o exe

.PHONY: all clean fclean re
