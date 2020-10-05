# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 11:01:38 by jalvaro           #+#    #+#              #
#    Updated: 2020/05/03 11:01:38 by jalvaro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha	\
ft_isascii ft_isdigit ft_isprint ft_itoa ft_memccpy			\
ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset			\
ft_putchar_fd ft_putendl_fd ft_putstr_fd ft_putnbr_fd		\
ft_split ft_strchr ft_strdup ft_strjoin ft_strlcat			\
ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr		\
ft_strrchr ft_strtrim ft_substr ft_toupper ft_tolower		\
ft_memjoin ft_ultoa_base ft_memsub ft_lstadd_back 			\
ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter 		\
ft_lstlast ft_lstmap ft_lstnew ft_lstsize ft_uitoa_base		\
get_next_line ft_putchar ft_putstr ft_skip_nbr

SRC_DIR = ./srcs/
SRC_FILE = $(FILES:=.c)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_TEMP = $(addprefix $(SRC_DIR), %.c)
BONUS_SRC =  $(addprefix $(SRC_DIR), $(BONUS_FILES:=.c))


OBJ_DIR = ./obj/
OBJ_FILE = $(FILES:=.o)
OBJ = $(addprefix $(OBJ_DIR), $(FILES:=.o))
OBJ_TEMP = $(addprefix $(OBJ_DIR), %.o)

INCLUDES = ./includes/
HEADER = $(addprefix $(INCLUDES), libft.h)

.PHONY: all clean fclean re bonus

all: $(OBJ_DIR) $(NAME) $(SRC)

$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib libft.a
	@echo Библиотека $(NAME) готова

$(OBJ_TEMP): $(SRC_TEMP) $(HEADER)
	@gcc -c -Wall -Werror -Wextra -I $(INCLUDES) $< -o $@ -D BUFFER_SIZE=5
	@echo Собираю $@ из $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean: 
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f libft.a
	@echo libft: Все очищено

re: fclean all
