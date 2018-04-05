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
					value_insert.c \
					nearest_dif.c \
					nearest_checker.c \
					last_step.c \

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

NUM5 = "-cv 202 314 374 313 175 50 260 346 85 482 60 48 127 437 476 224 211 292 31 453 106 145 90 207 187 481 88 371 322 152 384 159 243 337 92 190 488 279 71 6 465 103 176 401 128 500 170 12 98 235 37 288 54 122 398 199 469 107 11 299 181 217 39 439 61 79 196 447 59 63 471 74 249 9 67 255 480 277 29 146 118 220 174 232 492 270 358 438 347 356 281 3 2 344 206 94 7 262 392 410 449 484 490 416 120 477 359 318 427 102 364 188 203 352 239 320 445 463 139 328 389 87 412 368 293 450 271 72 333 52 162 101 499 348 247 96 365 33 263 264 230 8 160 419 148 254 17 297 84 317 379 360 193 479 228 435 372 366 161 310 265 443 194 487 115 415 315 312 454 78 131 376 425 70 197 495 80 324 36 382 400 215 343 142 241 229 325 362 269 470 309 369 316 234 28 108 267 4 386 411 478 157 467 189 332 458 136 169 408 468 138 493 155 272 150 302 135 462 330 81 483 46 266 66 62 119 274 32 154 381 351 125 405 290 130 377 210 431 305 95 475 291 93 51 22 200 253 121 404 474 452 237 423 396 385 285 151 58 76 498 304 165 55 353 338 424 472 77 289 486 287 407 153 44 319 342 23 112 284 14 329 321 273 335 460 238 89 180 349 186 455 354 182 399 147 306 183 489 357 192 124 140 57 49 123 19 491 185 97 295 143 256 223 133 308 158 41 214 100 177 380 275 82 205 456 378 280 294 212 225 201 283 132 26 30 496 69 248 414 68 25 327 252 116 258 417 126 406 222 388 179 208 110 184 144 53 326 426 242 191 459 27 286 236 195 336 444 218 341 21 75 167 402 251 436 361 250 397 105 42 448 373 296 432 497 311 240 149 350 35 99 383 420 13 429 473 56 367 409 422 1 40 20 38 227 16 171 278 485 64 259 226 440 403 395 276 307 301 433 113 111 221 137 209 375 441 91 355 34 114 173 390 303 156 300 24 86 391 393 268 466 339 198 47 387 163 446 323 15 45 117 231 421 204 331 457 109 43 451 461 5 418 83 345 363 246 104 261 428 334 434 168 219 298 134 213 430 340 164 129 216 257 172 178 18 141 65 442 166 233 73 244 10 413 282 394 464 370 494 245"

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
