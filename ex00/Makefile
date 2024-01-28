# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 02:12:48 by ychahbi           #+#    #+#              #
#    Updated: 2024/01/28 05:17:07 by ychahbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SUBJ = btc
SRC  = BitcoinExchange.cpp main.cpp
CC= c++
FLAGS= -g -Wall -Wextra -Werror -std=c++98
RM= rm -f
OBJ_ALL = $(SRC:.cpp=.o)

all: $(SUBJ)

$(SUBJ): $(OBJ_ALL)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp BitcoinExchange.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(SUBJ)

re: fclean all

.PHONY: clean