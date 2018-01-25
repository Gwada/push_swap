# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/01/20 20:13:51 by dlavaury         ###   ########.fr        #
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
					quicksort.c \
					push_swap_crack.c \
					swap.c \
					rotate.c

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

#NUM = 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 -60 -59 -58 -57 -56 -55 -54 -53 -52 -51 -50 -49 -48 -47 -46 -45 -44 -43 -42 -41 -40 -39 -38 -37 -36 -35 -34 -33 -32 -31 -30 -29 -28 -27 -26 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40

NUM = -cv 2 3 1

goc:
	@clear
	@make clean_C
	@make $(CHECKER)
	@./$(CHECKER)

gops:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
	time ./push_swap $(NUM)
#	@echo "\n"
#	./push_swap $(NUM)

.PHONY: all re fclean clean 
