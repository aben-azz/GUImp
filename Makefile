# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-azz <aben-azz@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 09:24:41 by aben-azz          #+#    #+#              #
#    Updated: 2019/10/24 14:52:52 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GUImp
lft_name = libft.a
lui_name = libui.a
sdl_tar_name = SDL2-2.0.8.tar.gz

lft_dir = ./libft/
lui_dir = ./libui/
src_dir = ./src/
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
LIBHEAD = $(lft_inc_dir)libft.h

src_files = main.c


#SRC = $(addprefix $(src_dir), $(src_files))
#OBJ = $(addprefix $(obj_dir), $(src_files:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
INC = -I $(inc_dir) -I $(lft_inc_dir) -I $(lui_inc_dir) -I $(sdl_inc_dir)

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(sdl_dir) $(sdl_lib_dir) $(obj_dir) $(OBJ) $(LIBHEAD)
	@make -C $(lft_dir)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "libft.a"
	@make -C $(lui_dir)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "libvec.a"
	@$(CC) $(OBJ) $(lft_lib) $(lui_lib) $(sdl_link) -o $(NAME)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(lft_name):
	@make -C $(lft_dir)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(lui_name):
	@make -C $(lui_dir)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(sdl_dir):
	@tar -xf $(sdl_tar_name)
	@printf "RTv1:  %-25s$(C_CYAN)[extracted]$(C_NONE)\n" $@

$(sdl_lib_dir):
	@mkdir $(sdl_lib_dir)
	@printf "\n$(C_CYAN)[configuring SDL]$(C_NONE)\n"
	@cd $(sdl_dir); ./configure --prefix=`pwd`/lib >/dev/null
	@printf "$(C_CYAN)[compiling SDL]$(C_NONE)\n"
	@make -C $(sdl_dir) >/dev/null
	@make -C $(sdl_dir) install >/dev/null
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(obj_dir):
	@mkdir $(obj_dir)
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(obj_dir)%.o: $(src_dir)%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(obj_dir)
	@make -C $(lft_dir) clean
	@make -C $(lui_dir) clean
	@printf "RTv1:  %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(sdl_dir)
	@make -C $(lft_dir) fclean
	@make -C $(lui_dir) fclean
	@printf "RTv1:  %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm: clean
	@norminette $(src_dir) $(inc_dir)

allnorm: norm
	@norminette $(lft_dir)
	@norminette $(lui_dir)
