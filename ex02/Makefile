# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 17:53:22 by synicole          #+#    #+#              #
#    Updated: 2023/06/21 17:53:24 by synicole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 			= phonebook

# COMPILATION OPTIONS
CC				= g++
FLAGS 			= -std=c++98 -Wall -Werror -Wextra

# OBJ
OBJS_DIR   		= objs
OBJS 			= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

# SOURCES
SRCS_DIR   		= srcs
SRCS 			= $(wildcard $(SRCS_DIR)/*.cpp) \

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
all:			$(OBJS_DIR) $(NAME)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

$(NAME): 		$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)
				@echo "$(_SUCCESS)🚀Build!$(_END)"

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
				$(CC) $(FLAGS) -c $< -o $@

clean:
				/bin/rm -rf $(OBJS_DIR)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				/bin/rm -rf $(NAME)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re
