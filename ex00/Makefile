# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmario <dmario@student.42luanda.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/24 10:48:58 by dmario            #+#    #+#              #
#    Updated: 2026/09/24 10:48:59 by dmario           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

NAME = convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re