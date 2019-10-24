# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 12:43:35 by aben-azz          #+#    #+#              #
#    Updated: 2019/10/24 12:20:27 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a
SRC = ft_test.c

_END			=	\x1b[0m
_BOLD			=	\x1b[1m
_UNDER			=	\x1b[4m
_REV			=	\x1b[7m
_GREY			=	\x1b[30m
_RED			=	\x1b[31m
_GREEN			=	\x1b[32m
_YELLOW			=	\x1b[33m
_BLUE			=	\x1b[34m
_PURPLE			=	\x1b[35m
_CYAN			=	\x1b[36m
_WHITE			=	\x1b[37m
_IGREY			=	\x1b[40m
_IRED			=	\x1b[41m
_IGREEN			=	\x1b[42m
_IYELLOW		=	\x1b[43m
_IBLUE			=	\x1b[44m
_IPURPLE		=	\x1b[45m
_ICYAN			=	\x1b[46m
_IWHITE			=	\x1b[47m
MSG				= $(_BOLD)$(_BLUE)Compiling the $(NAME):$(_END)

OBJPATH			= .obj/
SRCPATH			=	srcs/

SRCS			:= $(SRC:%=$(SRCPATH)%)
OBJ				:= $(SRC:%.c=$(OBJPATH)%.o)

COMP		= gcc
CFLAGS		= -Wall -Wextra -Werror -I./includes -c #-g -v#-fsanitize=address
AR			= ar rcs

LONGEST		?=	$(shell echo $(notdir $(SRCS)) | tr " " "\n" | awk ' { if (\
			length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\r\033[K$(_BOLD)$(_PURPLE)Making ${NAME}...$(_END)"
	@$(AR) $(NAME) $(OBJ)
	@echo "\r\033[K$(_BOLD)$(_GREEN)${NAME} is ready for use$(_END)"

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c
	@mkdir -p $(OBJPATH)
	@$(COMP) $(CFLAGS) -o $@ $<
	@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

clean:
	@rm -rf $(OBJPATH)
	@echo "$(_BOLD)$(_RED)Successfully removed all objects from the $(NAME)\
	$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_BOLD)$(_RED)Successfully removed ${NAME} from the $(NAME)$(_END)"

re: fclean all

.PHONY: all clean fclean re
