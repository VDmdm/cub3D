# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/01 19:18:04 by jalvaro           #+#    #+#              #
#    Updated: 2020/06/21 22:29:04 by jalvaro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILES = main color_parse data_init data_utils init_prs main_utils_1	\
main_utils_2 map_prs map_prs_utils raycasting raycasting_utils		\
tex_prs pad sprite bmp

COMPILLER = clang
FLAGS = -Wall -Werror -Wextra -g
LIBS = -lmlx -lXext -lX11 -lm -L./ -lft

SRC_DIR = ./srcs/
SRC_FILE = $(FILES:=.c)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_TEMP = $(addprefix $(SRC_DIR), %.c)


OBJ_DIR = ./obj/
OBJ_FILE = $(FILES:=.o)
OBJ = $(addprefix $(OBJ_DIR), $(FILES:=.o))
OBJ_TEMP = $(addprefix $(OBJ_DIR), %.o)

INCLUDES = ./includes/
HEADER = $(addprefix $(INCLUDES), map_draw.h)

LIB = libft.a
LIB_DIR = ./srcs/libft/
LIB_FILE = $(addprefix $(LIB_DIR), $(LIB))
INCLUDES_LIB = ./srcs/libft/includes/
HEADER_LIB = $(addprefix $(INCLUDES_LIB), libft.h)

.PHONY: all clean fclean re bonus

all: libmake $(OBJ_DIR) $(NAME) $(SRC)

$(NAME): $(OBJ)
	@$(COMPILLER) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) 
	@echo Программа $(NAME) готова

libmake:
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@cp $(LIB_FILE) $(LIB)

$(OBJ_TEMP): $(SRC_TEMP) $(HEADER) $(LIB_FILE)
	@echo Собираю $@ из $<
	@$(COMPILLER) $(FLAGS) -c $< -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@ 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -f $(LIB)
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo $(NAME): удаляю *.o

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR) --no-print-directory
	@rm -f $(NAME)
	@echo $(NAME): программа удалена

re: fclean all