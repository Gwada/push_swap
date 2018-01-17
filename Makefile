# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/01/17 20:16:24 by dlavaury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB				= libft
CHECKER			= checker
PUSH_SWAP		= push_swap

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
HARDFLAGS		= -Weverything
HEADER			= -I includes -I $(LIB)/includes/

SOURCES			= display.c \
					init.c \
					push_swap.c \
					quicksort.c
#SOURCES_C		= c_main.c 
SOURCES_C		= $(SOURCES) \
					c_main.c
SOURCES_PS		= $(SOURCES) \
					ps_main.c
#SOURCES_P_S		+= $(SOURCES)
OBJ_C			= $(addprefix sources/,$(SOURCES_C:.c=.o))
OBJ_PS			= $(addprefix sources/,$(SOURCES_PS:.c=.o))

#PROGRESS
#TC				= $(words $(SOURCES_C))
#TPS				= $(words $(SOURCES_P_S))
#N				= 0
#C				= $(words $N)$(eval N := x $N)
#ECHOC			= "[`expr $C '*' 100 / $(TC)`%]"
#ECHOPS			= "[`expr $C '*' 100 / $(TPS)`%]"

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

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): lib $(OBJ_C)
	@$(CC) $(FLAGS) -o $(CHECKER) $(OBJ_C) $(LIB)/$(LIB).a
	@echo "$(_CYAN)$(CHECKER)$(_END)			: $(_GREEN)compiled$(_END)"

$(PUSH_SWAP): lib $(OBJ_PS) 
	@$(CC) $(FLAGS) -o $(PUSH_SWAP) $(OBJ_PS) $(LIB)/$(LIB).a
	@echo "$(_CYAN)$(PUSH_SWAP)$(_END)		: $(_GREEN)compiled$(_END)"

%.o: %.c
#	@printf "%-60b\r" "$(ECHOPS)"
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	@make -C $(LIB) clean
	@make clean_C
	@make clean_PS
	@echo "$(_RED)clean $(_END)			: $(_GREEN)done$(_END)"
clean_C:
	@rm -f $(OBJ_C)
clean_PS:
	@rm -f $(OBJ_PS)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "$(_RED)fclean$(_END)			: $(_GREEN)done$(_END)"

re: fclean
	@make all

lib:
	@make -j3 -C $(LIB)

go:
	@clear
	@make clean_C
	@make clean_PS
	@make all
	@./$(CHECKER)
	@./$(PUSH_SWAP)

NUM = -cv -56464 684 84 -86 15465 654 349682 0 -1 2147483647 3158 1 16 684 135 864 654 64 526 5945 -156 +48584 1564 684 684 861 16584768 38768 849746364 49764 4888848 68463641 4864651 68476351 -445541 -5415 -1545 -1584

goc:
	@clear
	@make clean_C
	@make $(CHECKER)
	@./$(CHECKER)

gops:
	@clear
#	@make clean_PS
	@make $(PUSH_SWAP)
	time ./push_swap $(NUM)
#	@echo "\n"
#	./push_swap $(NUM)

.PHONY: all re fclean clean 
