# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/04/05 04:33:33 by dlavaury         ###   ########.fr        #
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
					push.c \
					calibrate_rot.c

SOURCES_C		= $(SOURCES) \
					c_main.c

SOURCES_PS		= $(SOURCES) \
					ps_main.c \
					crack_that_shit.c \
					push_swap_crack.c \
					push_swap.c \
					first_step.c \
					second_step.c \
					value_insert.c \
					nearest_dif.c \
					nearest_checker.c \
					last_step.c \
					sort.c

OBJ_C			= $(addprefix sources/,$(SOURCES_C:.c=.o))
OBJ_PS			= $(addprefix sources/,$(SOURCES_PS:.c=.o))

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

NUM1 = "-cv 1 5 4 3 2"

NUM2 = "-cv 4 5 6 25 31 8 7 30 9 -5 -4 -3 -2 -1 0 1 2 53 3 42"

NUM3 = "-cv 585 330000000 587 588 231 4865 2586 -4563 84651 9452 -41815 484151 415815 0 -5 -4813 187456 -89452 3241 -48540001 -48552 -45125 9745265 -932 63658 24874 157465 -3545 7825 78 9851 -4561 3874 154865 -15489 12584 3484 94621 487 52 15874 34 16 84 -79 94 85 62 42 54"

NUM4 = "-cv 72 27 30 98 87 70 21 6 32 94 80 39 17 63 68 58 83 4 51 59 64 34 41 73 99 88 49 15 95 92 22 75 56 42 35 45 26 16 61 3 38 78 29 43 57 69 12 2 25 13 60 19 93 28 74 86 90 5 97 89 54 23 33 77 48 96 66 18 40 91 20 8 47 84 53 46 37 62 67 79 85 0 100 50 36 44 11 82 7 10 9 76 81 1 31 65 55 14 24 52 71"

NUM5 = "-cv 15 195 5 292 355 175 56 18 296 327 212 492 300 470 224 43 202 205 436 132 223 400 447 423 417 473 290 491 209 74 462 233 47 104 146 249 257 39 4 497 452 126 76 347 137 418 446 368 127 216 314 183 305 20 336 364 315 288 41 444 339 480 199 334 165 344 265 264 116 203 439 380 429 138 225 255 147 187 108 401 60 466 422 167 54 477 291 88 154 36 298 13 30 498 49 287 73 236 155 219 479 451 243 286 469 143 283 284 383 407 58 395 133 459 78 161 464 24 16 248 160 111 75 64 94 367 267 89 240 253 475 374 375 457 500 420 385 456 232 1 55 455 377 281 9 425 299 471 210 101 194 84 103 201 85 319 141 62 346 150 131 474 23 176 82 65 438 483 122 285 403 53 182 166 179 365 307 461 27 113 220 428 430 93 115 345 193 251 230 426 279 415 256 392 388 134 83 453 432 151 369 302 262 297 214 486 476 406 142 91 356 8 204 268 32 332 50 409 306 434 244 157 109 266 318 34 485 343 35 208 481 239 427 361 270 40 295 197 117 184 293 371 63 235 342 31 46 107 349 100 386 80 413 247 390 177 156 33 382 329 128 378 441 207 174 351 353 325 354 246 110 38 478 119 222 211 189 168 44 391 379 12 241 29 261 242 412 105 381 258 282 421 348 10 357 394 162 399 488 227 59 140 173 14 449 419 130 172 313 221 186 124 99 437 337 272 26 490 328 445 431 340 433 280 234 48 200 61 37 92 359 185 118 324 52 389 145 414 171 22 190 213 196 358 181 87 294 404 95 489 463 408 25 370 303 114 411 330 499 7 393 11 254 77 405 467 273 139 123 435 350 178 494 153 387 215 188 163 373 106 228 308 97 450 68 3 376 125 317 144 81 366 136 159 129 335 2 274 192 191 363 245 443 465 252 21 148 321 67 311 396 484 271 360 312 316 487 352 17 289 398 276 472 135 170 326 482 263 57 259 102 6 468 416 45 410 69 72 164 237 320 496 98 90 121 238 322 384 402 338 309 372 231 86 341 206 218 19 217 180 331 442 269 275 152 440 66 28 149 397 304 333 260 120 158 79 198 310 301 460 362 71 112 495 277 250 169 493 96 323 278 42 454 458 448 424 229 51 226 70"

goc:
	@clear
	@make clean_C
	@make $(CHECKER)
	@./$(CHECKER)

gops1:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM1)

gops2:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM2)

gops3:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM3)

gops4:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM4)

gops5:
	@clear
	@make clean_PS
	@make $(PUSH_SWAP)
#	@time ./push_swap $(NUM3)
	./push_swap $(NUM5)

gof1:
	@clear
	@make clean_PS
	@make clean_C
	@make
	@./push_swap $(NUM2) | ./checker $(NUM2)

gof2:
	@clear
	@make clean_PS
	@make clean_C
	@make
	@./push_swap $(NUM3) | ./checker $(NUM3)

gof3:
	@clear
	@make clean_PS
	@make clean_C
	@make
	@./push_swap $(NUM4) | ./checker $(NUM4)

gof4:
	@clear
	@make clean_PS
	@make clean_C
	@make
	@./push_swap $(NUM5) | ./checker $(NUM5)

gof5:
	@clear
	@make clean_PS
	@make clean_C
	@make
	@./push_swap $(NUM1) | ./checker $(NUM1)


.PHONY: all re fclean clean
