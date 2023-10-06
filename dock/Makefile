# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohadmin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 19:15:34 by ohadmin           #+#    #+#              #
#    Updated: 2023/10/05 19:32:41 by ohadmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = fractal

# Flags al compilar
FLAGS = -g -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rcs

# Include
INC = fractal.h

# Functions
SRC = main.c init.c math_utils.c render.c string_utils.c

# Objects
OBJ = $(SRC:.c=.o)

MAIN = main.c

#### mlx
LMLX_DIR = mlx_linux/
LMLX = libmlx.a
#DEPS = $(addprefix $(LMLX_DIR), $(LMLX))

#### Compilacion del programa ####

all: $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

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
	$(CC) $(SRC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY: all clean fclean re
