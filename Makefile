# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nograu <nograu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 12:51:52 by nograu            #+#    #+#              #
#    Updated: 2025/11/21 13:36:39 by nograu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
      ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

BONUS_SRC	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
                ft_lstclear_bonus.c ft_lstdelone_bonus.c

OBJ	=	$(SRC:.c=.o)

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

CC	=	cc

FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJ) $(BONUS_OBJ) 
	ar rcs $(NAME) $(BONUS_OBJ)

.PHONY: clean fclean bonus all re