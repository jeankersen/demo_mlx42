# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:39:11 by anshimiy          #+#    #+#              #
#    Updated: 2023/07/18 11:26:21 by alexnshimiy      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

SRCDIR = src/
PARSE = parse/
UTILS = utils/
RAYCAST = raycasting/

MLXDIR = ./includes/MLX42/
MYLIB_DIR = ./includes/my_lib/

SRCS =  $(SRCDIR)main.c	$(SRCDIR)cub3d.c																								\
		$(SRCDIR)$(UTILS)errors.c $(SRCDIR)$(UTILS)map_position.c $(SRCDIR)$(UTILS)ft_split_set.c $(SRCDIR)$(UTILS)init_draw.c		\
		$(SRCDIR)$(UTILS)draw.c $(SRCDIR)$(UTILS)math.c $(SRCDIR)$(UTILS)mlx.c $(SRCDIR)$(UTILS)minimap.c 		\
		$(SRCDIR)$(PARSE)color.c $(SRCDIR)$(PARSE)init.c $(SRCDIR)$(PARSE)parse.c $(SRCDIR)$(PARSE)texture_parsing.c					\
		$(SRCDIR)$(PARSE)map.c $(SRCDIR)$(PARSE)dimentions.c																			\
		$(SRCDIR)$(RAYCAST)raycaster.c $(SRCDIR)$(RAYCAST)movements.c $(SRCDIR)$(RAYCAST)init.c $(SRCDIR)$(RAYCAST)walls.c 				\
		
CC = gcc
CFLAGS = -Wno-unused-variable # -Wall -Wextra -Werror 
LINKS	= 
MLXFLAGS = -lglfw -L$(shell brew --prefix glfw)/lib -framework Cocoa -framework OpenGL -framework IOKit
MLXLIB = $(MLXDIR)build/libmlx42.a
MYLIB = ./includes/my_lib/mylib.a
RM = rm -rf

# .o files in bin
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: $(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(HIDE) make -C ./includes/my_lib
	$(HIDE) @$(CC) $(MLXLIB) $(MYLIB) $(MLXFLAGS) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME) 
	@echo "$(GREEN)$(NAME) compiled!$(CEND)"

$(MLXLIB):
	@echo "$(CYAN)Compiling MLX42 library...$(CEND)"
	@cmake -S $(MLXDIR) -B $(MLXDIR)build
	$(HIDE) @make -C $(MLXDIR)build
	@echo "$(GREEN)MLX42 compiled.$(CEND)"

$(MYLIB):
	@echo "$(CYAN)Compiling my_lib...$(CEND)"
	$(HIDE) make -C ./includes/my_lib
	@echo "$(GREEN)My_lib compiled.$(CEND)"


# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c| $(OBJDIR)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE) mkdir -p $@ $(OBJDIR)$(PARSE) $(OBJDIR)$(UTILS)

clean: 
	$(HIDE) $(MAKE) -C ./includes/my_lib clean
	$(HIDE) $(RM) $(OBJS)
	@echo "$(YELLOW)$(NAME) cleaned!$(CEND)"
	@echo "$(RED)  _.,-----/=\-----,._"
	@echo " (__ ~~~.......~~~ __)"
	@echo "  | ~~~.........~~~ |"
	@echo "  | |  ; ,   , ;  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  | |  | |   | |  | |"
	@echo "  |. \_| |   | |_/ .|"
	@echo "   °-,.__ ~~~ __.,-°$(CEND)"
	
fclean: clean
	$(HIDE) $(MAKE) -C ./includes/my_lib fclean
	$(HIDE) $(RM) $(NAME)

re: fclean all

git:
	@git add .
	@read -p "Insert the commit message: " TAG && git commit -m "$$TAG"
	@git push
	@echo "$(PURPLE)$(CBOLD) .      .      .      .      .      .      .      .      .      .      ."
	@echo ".  $(PURPLE)$(NAME) is entering the git world$(CEND)$(PURPLE)$(CBOLD)  .       .       .       .    . "
	@echo "   .        .        .        .        .        .        .        .        ."
	@echo "     .         .         .        _......____._        .         ."
	@echo "   .          .          . ..--°¨¨ .           ¨¨¨¨¨¨---...          ."
	@echo "                   _...--¨¨        ................       °-.              ."
	@echo "                .-°        ...:°::::;:::%:.::::::_;;:...     °-."
	@echo "             .-°       ..::::°°°°°   _...---°¨¨¨¨:::+;_::.      °.      ."
	@echo "  .        .° .    ..::::°      _.-¨¨               :::)::.       °."
	@echo "         .      ..;:::°     _.-°         .             f::°::    o  $(GREEN)_$(CEND)$(PURPLE)$(CBOLD)"
	@echo "        /     .:::%°  .  .-¨                        $(BLUE).-.$(CEND)$(PURPLE)$(CBOLD)  ::;;:.   $(GREEN)/¨ ¨x$(CEND)$(PURPLE)$(CBOLD)"
	@echo "  .   .°  ¨¨::.::°    .-¨     _.--°¨¨¨-.           $(BLUE)(   )$(CEND)$(PURPLE)$(CBOLD)  ::.::  $(GREEN)|_.-° |$(CEND)$(PURPLE)$(CBOLD)"
	@echo "     .°    ::;:°    .°     .-¨ $(YELLOW).d@@b.$(CEND)$(PURPLE)$(CBOLD)   \    .    . $(BLUE)°-°$(CEND)$(PURPLE)$(CBOLD)   ::%::   $(GREEN)\_ _/$(CEND)$(PURPLE)$(CBOLD)    ."
	@echo "    .°    :,::°    /   . _°    $(YELLOW)8@@@@8$(CEND)$(PURPLE)$(CBOLD)   j      .-°       :::::      $(GREEN)¨$(CEND)$(PURPLE)$(CBOLD) o"
	@echo "    | .  :.%:° .  j     $(RED)(_)$(CEND)$(PURPLE)$(CBOLD)    $(YELLOW)°@@@P°$(CEND)$(PURPLE)$(CBOLD)  .°   .-¨         ::.::    .  f"
	@echo "    |    ::::     (        -..____...-°  .-¨          .::::°       /"
	@echo ".   |    °:°::    °.                ..--°        .  .::°::   .    /"
	@echo "    j     °:::::    °-._____...---¨¨             .::%:::°       .°  ."
	@echo "     \      ::.:%..             .       .    ...:,::::°       .°"
	@echo " .    \       °:::°:..                ....::::.::::°       .-°          ."
	@echo "       \    .   °°:::%::°::.......:::::%::.::::°°       .-°"
	@echo "      . °.        . °°::::::%::::.::;;:::::°°°      _.-°          ."
	@echo "  .       °-..     .    .   °°°°°°°°°         . _.-°     .          ."
	@echo "         .    ¨¨--...____    .   ______......--° .         .         ."
	@echo "  .        .        .    ¨¨¨¨¨¨¨¨     .        .        .        .        ."
	@echo " .       .       .       .       .       .       .       .       ."
	@echo "     .      .      .      .      .      .      .      .      .      .      .$(CEND)"
	@echo "\n$(YELLOW)$(NAME) committed sucessfully$(CEND)"

norm:
	@norminette $(SRC) ./includes/*.h ./includes/my_lib/

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[0;36m
CEND = \033[0m
CBOLD     = \033[1m
.PHONY: all clean fclean re 