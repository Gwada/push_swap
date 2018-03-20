# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/01/27 21:15:29 by dlavaury         ###   ########.fr        #
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
					quicksort.c \
					swap.c \
					rotate.c \
					push.c

SOURCES_C		= $(SOURCES) \
					c_main.c
SOURCES_PS		= $(SOURCES) \
					ps_main.c \
					crack_that_shit.c \
					push_swap_crack.c \
					push_swap.c \
					section_sort.c \
					second_step.c \
					last_value.c \
					nearest_dif.c

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
	@$(CC) $(FLAGS) $(HEADER) -o $(CHECKER) $(OBJ_C) $(LIB)/$(LIB).a
	@echo "$(_CYAN)$(CHECKER)$(_END)			: $(_GREEN)compiled$(_END)"

$(PUSH_SWAP): lib $(OBJ_PS) 
	@$(CC) $(FLAGS) $(HEADER) -o $(PUSH_SWAP) $(OBJ_PS) $(LIB)/$(LIB).a
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

NUM1 = "-cv 4 5 6 8 7 9 1 2 53 3"

NUM2 = "-cv 4 5 6 25 31 8 7 30 9 -5 -4 -3 -2 -1 0 1 2 53 3"

NUM3 = "-cv 585 584 587 588 231 4865 2586 4563 84651 9452 -41815 484151 -415815 0 -5 4813 187456 -89452 3241 -48541 -48552 -45125 -9745265 -932 -63658 24874 157465 3545 7825 78 9851 4561 3874 154865 15489 12584 3484 94621 487 52 15874 34 16 84 79 94 85 62 42 54"

goc:
	@clear
	@make clean_C
	@make $(CHECKER)
	@./$(CHECKER)

gops:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM3)


.PHONY: all re fclean clean 
