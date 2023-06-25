# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:58:58 by anrodri2          #+#    #+#              #
#    Updated: 2023/03/15 00:38:24 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### FINAL COMPILATION FILE ###
NAME = wordle

#### DIRECTORIES ####
SRC_DIR = src/

OBJS_DIR = .objs/

INC_DIR = incl/

#### SOURCE FILES ####
SRCS =	main.c \
		parsing/parsing_dictionnary.c \
		game/game.c \
		game/input.c \
		game/utils.c \

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

#### SYSTEM ####
CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g3 

DFLAGS = -MMD -MP

IFLAGS = -I $(INC_DIR)

#### RULES ####
all:		$(NAME)

-include	$(DEPS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $@

$(OBJS_DIR)%.o:		$(SRC_DIR)%.c
					mkdir -p $(shell dirname $@)
					$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS_DIR) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re FORCE
