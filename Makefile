# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/04/06 17:31:37 by dlavaury         ###   ########.fr        #
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

NUM5 = "-cv 168 315 450 64 449 123 264 294 25 60 235 300 325 160 186 233 283 243 8 86 135 256 104 73 213 182 40 128 471 366 133 242 499 316 276 418 173 30 486 241 33 263 1 452 433 112 103 136 16 57 431 312 271 284 346 48 120 290 27 427 302 42 72 386 226 114 474 453 229 367 2 24 32 22 15 345 406 195 269 203 124 289 4 458 150 178 98 371 493 101 377 266 21 337 67 402 357 119 326 99 443 475 465 456 496 175 478 172 46 404 485 419 200 265 36 336 445 209 335 309 492 463 467 498 423 317 287 460 383 154 278 420 245 355 285 491 37 253 198 319 238 447 216 139 339 106 360 372 68 94 165 188 143 403 109 410 148 321 446 388 71 230 439 476 322 295 113 184 20 350 90 494 394 205 126 11 480 115 442 88 470 484 118 39 162 236 461 390 279 434 248 76 38 399 179 272 430 80 334 152 193 59 424 415 305 240 417 411 221 304 260 239 111 5 351 330 412 246 13 401 210 293 459 497 227 237 318 359 215 368 252 303 432 454 268 286 66 183 116 313 224 167 343 29 149 196 164 297 392 380 247 197 9 145 307 28 361 374 74 125 363 82 344 102 194 225 83 223 320 134 161 26 332 77 185 468 488 117 469 261 174 147 244 457 473 97 141 190 436 3 232 158 169 409 201 428 422 176 477 192 51 440 448 277 93 396 12 444 347 31 155 281 311 170 157 96 61 202 255 58 191 435 100 301 291 500 414 340 451 370 328 212 481 378 400 298 251 231 274 472 54 45 342 18 358 249 53 132 421 280 331 78 108 362 356 385 391 482 329 87 426 379 129 127 382 181 282 144 70 17 7 105 6 387 259 187 55 466 407 353 375 314 204 267 310 425 121 153 397 352 354 384 333 413 35 306 495 159 218 156 487 85 131 455 142 222 323 250 296 462 180 219 262 10 171 14 110 166 299 34 92 273 50 63 177 292 43 214 429 199 254 79 62 288 369 217 23 47 228 211 373 146 52 270 91 308 75 95 69 389 81 138 206 107 393 395 479 489 349 441 137 464 122 364 416 275 341 365 208 89 405 327 437 140 41 130 189 257 338 398 151 483 490 44 408 19 376 234 56 324 381 207 84 220 258 348 65 438 163 49"

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
