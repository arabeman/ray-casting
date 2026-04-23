# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 16:58:24 by mrabenja          #+#    #+#              #
#    Updated: 2025/03/07 11:05:35 by mrabenja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
Color_Off=\033[0m

# Regular Colors
Black = \e[0;30m
Red = \e[0;31m
Green = \e[0;32m
Yellow = \e[0;33m
Blue = \e[0;34m
Purple = \e[0;35m
Cyan = \e[0;36m
White = \e[0;37m

# Bold
BBlack = \e[1;30m
BRed = \e[1;31m
BGreen = \e[1;32m
BYellow = \e[1;33m
BBlue = \e[1;34m
BPurple = \e[1;35m
BCyan = \e[1;36m
BWhite = \e[1;37m

# Background
On_Black = \e[40m
On_Red = \e[41m
On_Green = \e[42m
On_Yellow = \e[43m
On_Blue = \e[44m
On_Purple = \e[45m
On_Cyan = \e[46m
On_White = \e[47m

define GP_NAME
 ▄▄▄  ■  ▗▞▀▜▌▗▞▀▘█  ▄     █  ▐▌▄▄▄▄     ▐▌▗▞▀▚▖ ▄▄▄ ▗▞▀▀▘█  ▄▄▄  ▄   ▄ 
▀▄▄▗▄▟▙▄▖▝▚▄▟▌▝▚▄▖█▄▀      ▀▄▄▞▘█   █    ▐▌▐▛▀▀▘█    ▐▌   █ █   █ █ ▄ █ 
▄▄▄▀ ▐▌           █ ▀▄          █   █ ▗▞▀▜▌▝▚▄▄▖█    ▐▛▀▘ █ ▀▄▄▄▀ █▄█▄█ 
     ▐▌           █  █                ▝▚▄▟▌          ▐▌   █             
     ▐▌                                                                 
                                                                        
                                                                        
endef	
export GP_NAME
																 
define WIPE_O
 ▄▄▄  ▗▖      ▗▖    ▄   ▄ ▄ ▄▄▄▄  ▗▞▀▚▖   ▐▌
█   █ ▐▌      ▗▖    █ ▄ █ ▄ █   █ ▐▛▀▀▘   ▐▌
▀▄▄▄▀ ▐▛▀▚▖▄  ▐▌    █▄█▄█ █ █▄▄▄▀ ▝▚▄▄▖▗▞▀▜▌
      ▐▙▄▞▘▀▄▄▞▘          █ █          ▝▚▄▟▌
                            ▀               
                                            
                                             
endef
export WIPE_O

define WIPE_ALL
▄▄▄▄     ▗▖   ■      ▄   ▄ ▄ ▄▄▄▄  ▗▞▀▚▖   ▐▌
█   █    ▗▖▗▄▟▙▄▖    █ ▄ █ ▄ █   █ ▐▛▀▀▘   ▐▌
█▄▄▄▀ ▄  ▐▌  ▐▌      █▄█▄█ █ █▄▄▄▀ ▝▚▄▄▖▗▞▀▜▌
█     ▀▄▄▞▘  ▐▌            █ █          ▝▚▄▟▌
▀            ▐▌              ▀               
                                             
                                                 
endef
export WIPE_ALL

define	WIPE_MAX
▗▖ ▗▖▄ ▄▄▄▄  ▄ ▄▄▄▄        ▗▞▀▚▖▄   ▄ ▗▞▀▚▖ ▄▄▄ ▄   ▄    ■  ▐▌   ▄ ▄▄▄▄    
▐▌ ▐▌▄ █   █ ▄ █   █       ▐▛▀▀▘█   █ ▐▛▀▀▘█    █   █ ▗▄▟▙▄▖▐▌   ▄ █   █   
▐▌ ▐▌█ █▄▄▄▀ █ █   █       ▝▚▄▄▖ ▀▄▀  ▝▚▄▄▖█     ▀▀▀█   ▐▌  ▐▛▀▚▖█ █   █   
▐▙█▟▌█ █     █     ▗▄▖                          ▄   █   ▐▌  ▐▌ ▐▌█     ▗▄▖ 
       ▀          ▐▌ ▐▌                          ▀▀▀    ▐▌            ▐▌ ▐▌
                   ▝▀▜▌                                                ▝▀▜▌
                  ▐▙▄▞▘                                               ▐▙▄▞▘
endef
export WIPE_MAX                                                                             

NAME = cub3D
NAMEBONUS = cub3D_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

DIRSRC = src
DIRBONUS = bonus
DIROBJ = tmp
DIRSPIN = tmp2
DIROBJBONUS = tmp_bonus

MAIN = $(DIRSRC)/main.c

#* Update $(DIROBJ) when adding new source files
#* Source directory inclusion not required (src)
SRC = main.c \
	parsing/ft_split_wsp.c parsing/parsing_utils.c \
	parsing/parsing1a.c parsing/parsing1b.c \
	parsing/parsing2a.c parsing/parsing2b.c \
	window/window.c \
	window/integer.c \
	key/key.c \
	raycasting/angle.c raycasting/frame.c \
	raycasting/move.c raycasting/raycasting.c \
	raycasting/solid_wall.c raycasting/texture_wall.c\
	raycasting/background.c \
	raycasting/texture.c \
	raycasting/has_wall_at.c \

SRCREUSE = parsing/ft_split_wsp.c parsing/parsing_utils.c \
	key/key.c \
	raycasting/angle.c \
	raycasting/move.c \
	raycasting/solid_wall.c \
	raycasting/has_wall_at.c \

SRC_BONUS = main_bonus.c \
	parsing/free_map_config_bonus.c \
	parsing/parsing1a_bonus.c parsing/parsing1b_bonus.c \
	parsing/parsing1c_bonus.c \
	parsing/parsing2a_bonus.c parsing/parsing2b_bonus.c \
	raycasting/texture_bonus.c raycasting/texture_wall_bonus.c \
	raycasting/texture2_bonus.c raycasting/raycasting_bonus.c \
	vertical_projection/floor_ceiling_bonus.c \
	vertical_projection/frame_bonus.c \
	minimap/minimap.c minimap/move.c \
	minimap/player.c minimap/render_minimap.c \
	minimap/wall.c minimap/draw_border.c \
	window/window_bonus.c \
	window/mouse.c \
	fog/fog_color.c \
	animation/door_bonus.c animation/player_render_bonus.c \
	animation/bool.c animation/effect_movement.c \
	animation/integer.c \
	animation/data.c \
	viewmodel/viewmodel.c \
	# add some for later

OBJ_REUSE = $(addprefix $(DIROBJBONUS)/, $(SRCREUSE:.c=.o))
OBJ_BONUS = $(addprefix $(DIROBJBONUS)/, $(SRC_BONUS:.c=.o))
OBJBONUS = $(OBJ_REUSE) $(OBJ_BONUS)

OBJ = $(addprefix $(DIROBJ)/, $(SRC:.c=.o))
LIBFT = libft/libft.a
MINILIBX = ./minilibx-linux
LIBMLX = $(MINILIBX)/libmlx.a

LINKING_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

SPINNER = tmp2/spinner.sh
✔ = \033[0;32m✔\033[0m

all: $(NAME)

bonus: $(NAMEBONUS)

$(DIROBJ):
	@mkdir -p $(DIROBJ)
	@mkdir -p $(DIROBJ)/parsing
	@mkdir -p $(DIROBJ)/window
	@mkdir -p $(DIROBJ)/key
	@mkdir -p $(DIROBJ)/raycasting

$(DIROBJBONUS):
	@mkdir -p $(DIROBJBONUS)
	@mkdir -p $(DIROBJBONUS)/parsing
	@mkdir -p $(DIROBJBONUS)/raycasting
	@mkdir -p $(DIROBJBONUS)/vertical_projection
	@mkdir -p $(DIROBJBONUS)/window
	@mkdir -p $(DIROBJBONUS)/key
	@mkdir -p $(DIROBJBONUS)/minimap
	@mkdir -p $(DIROBJBONUS)/fog
	@mkdir -p $(DIROBJBONUS)/animation
	@mkdir -p $(DIROBJBONUS)/viewmodel

$(MINILIBX):
	@echo "Cloning MinilibX..."
	@git clone https://github.com/42Paris/minilibx-linux.git
	@echo "$(✔) MinilibX cloned successfully"

# Rule for mandatory
$(DIROBJ)/%.o: $(DIRSRC)/%.c | $(DIROBJ) $(MINILIBX)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Rule for bonus files from src directory (reused files)
$(DIROBJBONUS)/%.o: $(DIRSRC)/%.c | $(DIROBJBONUS) $(MINILIBX)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Rule for bonus files from bonus directory
$(DIROBJBONUS)/%.o: $(DIRBONUS)/%.c | $(DIROBJBONUS) $(MINILIBX)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Add pattern-specific variable to handle source paths
$(DIROBJBONUS)/vertical_projection/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/parsing/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/raycasting/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/minimap/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/fog/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/animation/%.o: SOURCEDIR=$(DIRBONUS)
$(DIROBJBONUS)/viewmodel/%.o: SOURCEDIR=$(DIRBONUS)

$(SPINNER):
	@mkdir -p $(DIRSPIN)
	@touch $@
	@chmod +x $@
	@echo '#!/bin/bash' > $@
	@echo "trap 'tput cnorm' EXIT" >> $@
	@echo "cursorBack() {" >> $@
	@echo '  echo -en "\\033[$$1D"' >> $@
	@echo "}" >> $@
	@echo "spinner() {" >> $@
	@echo '  local pid=$$1' >> $@
	@echo '  local message="Loading"' >> $@
	@echo '  local spin="⠁⠂⠄⡀⢀⠠⠐⠈"' >> $@
	@echo '  local charwidth=$${#message}' >> $@
	@echo '  tput civis' >> $@
	@echo '  while kill -0 $$pid 2>/dev/null; do' >> $@
	@echo '    for ((i = 0; i < $${#spin}; i++)); do' >> $@
	@echo '      echo -n "$${spin:i:1} $$message"' >> $@
	@echo '      cursorBack $$((charwidth + 2))' >> $@
	@echo '      sleep 0.065' >> $@
	@echo '    done' >> $@
	@echo '  done' >> $@
	@echo '  tput cnorm' >> $@
	@echo '  wait $$pid' >> $@
	@echo '}' >> $@
	@echo '("$$@") & spinner $$!' >> $@

$(LIBFT): $(SPINNER)
	@$(SPINNER) make  -s -C libft --no-print-directory 

$(LIBMLX): $(SPINNER) $(MINILIBX)
	@$(SPINNER) make -s -C $(MINILIBX) 2> /dev/null
	@echo "$(✔) Minilibx compiled successfully"

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	@clear
	@echo "$(BYellow)"
	@echo "$$GP_NAME"
	@echo "$(Color_Off)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAME) -lm 
	@echo "$(✔) Project successfully compiled"

$(NAMEBONUS) : $(OBJBONUS) $(LIBMLX) $(LIBFT)
	@clear
	@echo "$(BYellow)"
	@echo "$$GP_NAME"
	@echo "$(Color_Off)"
	$(CC) $(CFLAGS) $(OBJBONUS) $(LIBFT) $(LIBMLX) $(LINKING_FLAGS) -o $(NAMEBONUS) -lm
	@echo "$(✔) Bonus project successfully compiled"

clean: $(SPINNER)
	@clear
	@echo "$(Purple)"
	@echo "$$CLEAR$$WIPE_O"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -rf libft/obj
	@rm -rf $(DIROBJ) $(DIROBJBONUS)
	@echo "$(✔) Object files successfully cleaned"

fclean: clean $(SPINNER)
	@clear
	@echo "$(BPurple)"
	@echo "$$WIPE_ALL"
	@echo "$(Color_Off)"
	@$(SPINNER) sleep 0.7
	@rm -rf $(DIRSPIN)
	@rm -f $(LIBFT)
	@rm -f $(NAME) $(NAMEBONUS)
	@echo "$(✔) Project successfully cleaned"

wipe_all: fclean 
	@clear
	@echo "$(BRed)"
	@echo "$$WIPE_MAX"
	@echo "$(Color_Off)"
	@rm -rf $(MINILIBX)
	@echo "$(✔) Minilibx removed successfully"
	@echo "$(✔) Everything wiped out"
	

re: 
	@${MAKE} fclean 
	@${MAKE} all

.PHONY: all clean fclean re wipe_all