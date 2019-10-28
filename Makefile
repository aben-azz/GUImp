# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 09:24:41 by aben-azz          #+#    #+#              #
#    Updated: 2019/10/28 13:34:00 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GUImp
lft_name = libft.a
lui_name = libui.a
sdl_zip_name = SDL2-2.0.8.zip

lft_dir = ./libft/
lui_dir = ./libui/
src_dir = ./srcs/
inc_dir = ./includes/
lft_inc_dir = $(lft_dir)includes/
lui_inc_dir = $(lui_dir)includes/
sdl_dir = ./SDL2-2.0.8/
sdl_inc_dir = $(sdl_dir)include
sdl_lib_dir = $(sdl_dir)lib
obj_dir = ./obj/

sdl_link = `$(sdl_dir)sdl2-config --cflags --libs`

lft_lib = $(lft_dir)$(lft_name)
lui_lib = $(lui_dir)$(lui_name)

HEADER_FILES = $(inc_dir)guimp.h
LIBHEAD = $(lft_inc_dir)libft.h $(lui_inc_dir)libui.h

src_files = main.c


SRC = $(addprefix $(src_dir), $(src_files))
OBJ = $(addprefix $(obj_dir), $(src_files:.c=.o))
MSG				=	$(_BOLD)$(_BLUE)Compiling $(NAME):$(_END)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
INC = -I $(inc_dir) -I $(lft_inc_dir) -I $(lui_inc_dir) -I $(sdl_inc_dir)
LONGEST			=	$(shell echo $(notdir $(SRC)) | tr " " "\n" | awk ' { if (\
				length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)
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
_MAGENTA		=	\x1b[35m

all: $(lft_name) $(lui_name) $(NAME)

$(NAME): $(OBJ) $(LIBHEAD)
	@$(CC) $(OBJ) $(lft_lib) $(lui_lib) $(sdl_link) -o $(NAME)
	@printf "\r\033[K$(_BOLD)$(_RED)./$(NAME) is ready for use\n$(_END)"

$(lft_name):
	@test -f $(lft_lib) || make -C $(lft_dir)
	@#printf "$(NAME):  %-25s$(_GREEN)[done]$(_END)\n" $(lft_lib)
	@printf "\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)\n" $(notdir $(lft_lib))
$(lui_name):
	@test -f $(lui_lib) || make -C $(lui_dir)
	@#printf "$(NAME):  %-25s$(_GREEN)[done]$(_END)\n" $(lui_lib)
	@printf "\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)\n" $(notdir $(lui_lib))

$(obj_dir)%.o: $(src_dir)%.c $(HEADER_FILES)
	@mkdir -p $(obj_dir)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

clean:
	@rm -rf $(obj_dir)
	@make -C $(lft_dir) clean
	@make -C $(lui_dir) clean
	@echo "$(_BOLD)$(_RED)Successfuly removed all objects from $(NAME)$(_END)"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(lft_dir) fclean
	@make -C $(lui_dir) fclean
	@echo "$(_BOLD)$(_RED)Successfuly removed ${NAME} from $(NAME)$(_END)"

re: fclean all

norm: clean
	@norminette $(src_dir) $(inc_dir)

allnorm: norm
	@norminette $(lft_dir)
	@norminette $(lui_dir)
