# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 13:20:48 by urlooved &&       #+#    #+#              #
#    Updated: 2025/05/20 15:00:47 by urlooved &&      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------ Project specifics ---------------------------------- #
NAME        := cub3D

# --------------------------- Compiler ----------------------------------------- #
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -g3

# ---------------------------- Directories ------------------------------------- #
SRC_BASE    := srcs
INC_BASE    := includes
OBJ_DIR     := obj

LIBFT_DIR   := lib/libft
MLX_DIR     := lib/minilibx
LIB_DIRS    := $(LIBFT_DIR) $(MLX_DIR)

# ---------------------------- Source files ------------------------------------ #
SRC_DIRS    := $(shell find $(SRC_BASE) -type d)
vpath %.c $(SRC_DIRS)

SRC_FILES   :=  \
	main.c \
	get_next_line.c get_next_line_utils.c \
	handler_colors_and_textures.c garbage_collector.c \
	handler_pre_parser_file.c handler_pre_parsing.c tool_window.c \
	handler_init_parse_colors.c handler_pre_clean_file.c \
	init_engine.c handler_input_file.c \
	tools_array.c tools_file.c tools_str.c tools_str_2.c error.c \
	tools_map.c tools_parse_map.c init_player.c \
	handler_parse_textures.c handler_map.c \
	handler_exec_text.c handler_get_move.c tools_move.c \
	handler_play.c init_side_dist.c init_texture.c init_raycast_column.c \
	tools_calcul_text.c tools_draw.c tools_keys.c tools_texture_load.c \
	tools_calcul_wall.c init_mlx_data.c handler_calcul.c tools_move2.c

OBJS        := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ------------------------- Include paths -------------------------------------- #
INC_FLAGS   := -I $(INC_BASE) $(addprefix -I , $(LIB_DIRS))

# ------------------------- Linker Flags --------------------------------------- #
LIB_FLAGS   := $(addprefix -L, $(LIB_DIRS))

# --------------------------- Targets ------------------------------------------- #


all: $(NAME)

$(NAME): $(OBJS)
	@printf '\n\e[1;36m--- Linking: Creating executable \e[33m%s\e[0m ---\n' $@
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJS) -o $@ $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a -lm -lXext -lX11
	@printf '\e[1;32m🎉 Build successful: \e[4m%s\e[0m 🎉\n\n' $@
	@printf '\n'
	@printf '	 ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░                 ░▒▓███████▓▒░░▒▓███████▓▒░  \n' 
	@printf '	░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n'
	@printf '	░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n'
	@printf '	░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░                 ░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ \n'
	@printf '	░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n'
	@printf '	░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░                       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \n'
	@printf '	 ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░    ░░░░░░░░░    ░▒▓███████▓▒░░▒▓███████▓▒░  \n'
	@printf '\n'
	@printf '\n'
	@printf '\n'
	@printf '\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⣯⠿⠟⠛⠻⢶⣿⣯⣿⣿⣃⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣖⣺⡿⠿⠷⠶⠒⢶⣶⠖⠀⠉⡻⢻⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠀⣴⢻⣭⣫⣿⠁⠀⠀⠀⠀⠀⠀⠀⢀⣾⠃⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⢀⣖⡿⠋⢙⣿⠿⢿⠿⣿⡦⠄⠀⠀⠀⣠⣾⠟⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⢀⣰⣿⣴⣿⡿⠿⠿⠿⢿⣦⣄⠀⠀⠀⣠⣾⣿⠃⠀⢀⣸⡿⣳⣶⣲⡄⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⣾⣽⡿⣛⣵⠾⠿⠿⠷⣦⣌⠻⣷⣄⢰⣿⠟⠁⠀⢠⣾⠿⢡⣯⠸⠧⢽⣄⠀⠀⠀⠀⠀\n'
	@printf '				⠀⢸⡇⡟⣴⡿⢟⣽⣾⣿⣶⣌⠻⣧⣹⣿⡿⠋⠀⠀⠀⣾⠿⡇⣽⣿⣄⠀⠀⠉⠳⣄⢀⡀⠀\n'
	@printf '				⠀⢸⠇⢳⣿⢳⣿⣿⣿⣿⣿⣿⡆⢹⡇⣿⡇⠀⡆⣠⣼⡏⢰⣿⣿⣿⣿⣦⠀⠀⠀⠈⠳⣅⠀\n'
	@printf '				⠀⣸⡀⢸⣿⢸⣿⣿⣿⣿⣿⣿⡇⣸⡇⣿⡇⠀⡟⣻⢳⣷⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠘⣧\n'
	@printf '				⢰⡟⡿⡆⠹⣧⡙⢿⣿⣿⠿⡟⢡⣿⢷⣿⣧⠾⢠⣿⣾⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠘\n'
	@printf '				⠀⠻⡽⣦⠀⠈⠙⠳⢶⣦⡶⠞⢻⡟⡸⠟⠁⢠⠟⠉⠉⠙⠿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⡴\n'
	@printf '				⠀⠀⢸⣿⡇⠀⠀⣀⣠⠀⢀⡀⠸⣹⠇⠀⣰⡟⡀⠀⠈⠛⠻⢿⣻⣿⡿⠀⠀⠀⠀⠀⠀⡠⠁\n'
	@printf '				⠀⠀⢸⣿⣇⣴⢿⣿⣿⣿⣮⣿⣷⡟⠀⣰⣿⢰⠀⣀⠀⠀⠀⢀⣉⣿⡇⠀⠀⠀⠀⠀⣸⠃⠀\n'
	@printf '				⠀⠀⢸⣿⡟⣯⠸⣿⣿⣿⣿⢈⣿⡇⣼⣿⠇⣸⡦⣙⣷⣦⣴⣯⠿⠛⢷⡀⠀⠀⠀⣰⡟⠀⠀\n'
	@printf '				⠀⠀⠘⣿⣿⡸⣷⣝⠻⠟⢋⣾⣟⣰⡏⣠⣤⡟⠀⠀⠈⠉⠁⠀⠀⠀⠀⢻⣶⠀⢀⣿⠁⠀⠀\n'
	@printf '				⠀⠀⠀⢸⡿⣿⣦⣽⣛⣛⣛⣭⣾⣷⡶⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⡟⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠁⢸⢻⠁⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣤⣤⣀⣀⣀⣀⣀⣠⣤⠶⠛⠁⢀⣾⡟⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⢿⣻⣿⣿⣿⣿⣿⣿⣎⣿⡅⠀⠈⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⣼⣿⠁⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡷⠟⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⠻⢿⣿⣿⣟⣂⣀⣀⣀⣀⣀⣀⣤⠴⠋⠁⣾⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣷⣷⡄⠀⠀⠀⠉⠉⠉⠉⠉⠀⠀⠀⢀⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n'
	@printf '				⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣷⣤⣤⣤⣤⣄⣤⣤⡤⠴⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n'

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@printf '\e[1;34mCompiling \e[30;47m%-40s\e[0m -> \e[33m%s\e[0m\n' "$<" "$@"
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

re:	fclean all
	
clean:
	@printf '\e[1;31m*** Cleaning: Removing object and dependency files... ***\e[0m\n'
	@rm -rf $(OBJ_DIR)
	@printf '\e[32m✔ Object and dependency files removed successfully.\e[0m\n'

fclean: clean
	@printf '\e[1;31m*** Cleaning: Removing executable \e[33m%s\e[1;31m ... ***\e[0m\n' $(NAME)
	@rm -f $(NAME)
	@printf '\e[32m✔ Executable removed successfully.\e[0m\n'

.PHONY: all clean fclean re