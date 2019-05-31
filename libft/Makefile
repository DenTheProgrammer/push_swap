# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:20:20 by mdebbi            #+#    #+#              #
#    Updated: 2019/04/11 13:03:01 by mdebbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = libft.h

SRCS = *.c

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS) $(INCLUDES)
	ar -rc $(NAME) *.o

all: $(NAME)

clean:
	rm -f *.o
	rm -f libft.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
