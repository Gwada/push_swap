# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/01/13 19:59:12 by dlavaury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C		= checker
NAME_P_S	= push_swap
LIB			= libft

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
HARDFLAGS	= -Weverything
HEADER		= -I Includes -I $(LIB)/includes/

SOURCES		= \
SOURCES_C	= c_main.c \
SOURCES_P_S	= p_s_main.c \

OBJ_PS		= $(addprefix sources/,$(SOURCES_P_S:.c=.o))

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME_P_S) #$(NAME_C)

$(NAME_P_S): librarie $(OBJ_P_S)
	@$(CC) $(FLAGS) -o $(NAME_P_S) $(SOURCES_P_S) -L . -lft $(HEADER)
	@echo "\n$(_CYAN)$(NAME_P_S)$(_END) $(_GREEN)edited$(_END)"

#$(NAME_C)
#	@$(CC) $(FLAGS) -o $(NAME_C) $(SOURCES_C) -L . -lft $(HEADER)

%.o: %.c
	@$(CC) $(FLAGS) $(HEADER) -o $@

clean:
	@make -C $(LIB) clean
	@echo "$(_RED)clean$(_END)	:	$(_GREEN)done$(_END)"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME_P_S)
	@echo "$(_RED)fclean$(_END)	:	$(_GREEN)done$(_END)"

re: fclean
	@make all

librarie:
	@make -j3 -C $(LIB)

go:
	@clear
	@make all
#	@$(GCC) $(FLAGS) -o test $(SOURCES) -L . -lft $(HEADER)
#	@$(GCC) $(HARDFLAGS) -o test $(SOURCES) -L . -lft $(HEADER)
	@./$(NAME_P_S)

.PHONY: all re fclean clean
