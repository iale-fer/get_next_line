# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanalefernandez <ivanalefernandez@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 11:11:31 by ivanalefern       #+#    #+#              #
#    Updated: 2023/05/01 13:48:13 by ivanalefern      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CFLAG = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

CC = gcc
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)

re : fclean all

clean :
	rm -f $(OBJ)

fclean : clean
	rm  -f $(NAME)

.PHONY : clean fclean all re