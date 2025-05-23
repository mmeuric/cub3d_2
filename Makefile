NAME        	=   cub3D

CC          	=   gcc #-fsanitize=address -g3

SRC_DIR			= 	$(shell find srcs -type d) \

INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/libft -type d) \
					$(shell find lib/minilibx -type d) \


INCSDIR			=	includes

OBJ_DIR			=	obj

LIB_DIR			= lib/libft lib/minilibx

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# library -----------------------------------------------------------

SRC			= 	main.c \
				get_next_line.c get_next_line_utils.c \
\
				handler_colors_and_textures.c get_map.c garbage_collector.c  \
\
\
				handler_pre_parser_file.c handler_pre_parsing.c tool_window.c \
				handler_init_parse_colors.c handler_pre_clean_file.c\
\
\
				init_engine.c handler_input_file.c \
				tools_debug.c tools_tab.c tools_file.c tools_str.c  tools_str_2.c error.c \
				map_element.c init_perso.c \
				check_map_error.c \
				handler_parse_textures.c \
				handler_exec_text.c handler_get_move.c tools_move.c \
				handler_play.c init_side_dist.c init_texture.c init_raycast_column.c \
				tools_calcul_text.c tools_draw.c tools_keys.c tools_texture_load.c \
				tools_calcul_wall.c init_engine2.c handler_calcul.c tools_move2.c \


OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o)) \
				includes/cub3d.h

DEPS		= 	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.d))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -I ${INCSDIR}  -g3

IFLAGS		=	$(foreach dir, $(LIB_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir))

# main part ---------------------------------------------------------

all:
	@echo "\n___$(NAME) Setting___\n"
	@make  $(NAME)

install:
	@make -C lib/libft bonus
	@make -C lib/minilibx

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@make -C lib/libft fclean
	@make -C lib/minilibx clean

show:
	@echo "SRC :\n$(SRC)"
	@echo "OBJ :\n$(OBJ)"
	@echo "CFLAGS :\n$(CFLAGS)"
	@echo "IFLAGS :\n$(IFLAGS)"
	@echo "LFLAGS :\n$(LFLAGS)"
	@echo "\n-----\n"
	@echo "Compiling : \n$(CC) $(CFLAGS) $(OBJ) -o $(NAME)"

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $@ ... \c"
	make install
	@$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ ./lib/libft/libft.a ./lib/minilibx/libmlx_Linux.a -lm -lXext -lX11
	@echo "DONE\n-----"

-include	${DEPS}

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $@ ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I ${INCSDIR} $(CFLAGS) $(IFLAGS) -c $< -o $@ 
	@echo "DONE"

re:	fclean all

clean:
	@echo "Deleting Objects Directory $(OBJ_DIR) ... \c"
	@rm -rf obj/*.o
	@echo "DONE\n-----"

fclean:	clean
	@echo "Deleting Binary File $(NAME) ... \c"
	@rm -f $(NAME)
	@echo "DONE\n-----"

.PHONY: all bonus show re clean flcean install re-install fclean-install