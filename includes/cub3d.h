/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:33 by abahmani          #+#    #+#             */
/*   Updated: 2025/05/09 15:00:07 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>				// because i love booleans (true/false)
# include <strings.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
// # include <X11/X.h>
// # include <X11/keysym.h>			// Keys handling events

/*-------------------------------ERROR DEFINE---------------------------------*/

# define MALLOC_ERROR "An error occured during the memory allocation."
# define MLX_ERROR "A mlx error occured."

// errors parsing : 
# define FD_ERROR "An error occured during the file opening."
// # define TOO_MUCH_ARG_ERROR "There is too much argument."				// TODO erase
// # define TOO_FEW_ARG_ERROR "There is too few argument."					// TODO erase
// # define INCORRECT_FILE_NAME_ERROR "The input file name is incorrect."	// TODO erase
// # define FILE_NOT_EXIST_ERROR "The input file does not exist."			// TODO erase
// # define FILE_IS_DIR_ERROR "The input file is a directory."				// TODO erase
// # define FILE_IS_SYM_LINK "The input file is a symbolic link."			// TODO erase
// # define SCREEN_ERROR "The size of the screen is incorrect."				// TODO erase
# define TEXTURE_FILE_ERROR "This texture file is not correctly filled : "
# define COLOR_ERROR "The colors from the file are not correctly written."
# define MAP_ERROR "The map from the file is incorrectly filled."
# define DOUBLON_TEXTURE_ERROR "A texture is in double."
# define TEXTURE_FILE_NAME_ERROR "Incorrect texture file name."
# define SIZE_TEXTURE_ERROR "The size of this texture is incorrect : "
# define DOUBLON_COLOR_ERROR "A color is in double."

//	------------------
//	::  Key events  ::
//	------------------

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

//	-------------------------------
//	::  texture size definition  ::
//	-------------------------------

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

//	------------------
//	::  parameters  ::
//	------------------
/*
# define mapWidth 24
# define mapHeight 24
# define width 1920
# define height 1080
*/

/*----------------------------SCREEN DATA DEFINE------------------------------*/

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

/*----------------------------PERSO CONFIG DEFINE-----------------------------*/

# define PERSO_MOVEMENT_SPEED 0.071
# define PERSO_ROTATION_SPEED 0.0351

//	------------------
//	::  Structures  ::
//	------------------

//* Data
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*data;
	int		img_width;
	int		img_height;
	int		size_l;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;


// Window
typedef struct s_win
{
	int		color;
	int		up;
	int		down;
	int		right;
	int		left;
	int		left_pers;
	int		right_pers;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		height;
	int		width;
	char	*str;
	int		size;
	int		height_map;
	int		width_map;
	int		**texture;
	int		re_buf;
	int		buf[SCREEN_HEIGHT][SCREEN_WIDTH];
	t_data	data;
}	t_win;


// Player position 
// TODO These structu is not used. I would say "to erase"
// // typedef struct s_pos_int
// // {
// // 	int	x;
// // 	int	y;
// // }	t_pos_int;

// Player
typedef struct s_perso
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_perso;

// Colors
typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
	int	color;
	bool	is_inited;								//? for waht is init ? i think is a kind of flag.
}	t_rgb;

// Map data + important information and calls to others sctrucs
typedef struct s_map_data
{
	char	**map;
	char	*n_texture;						// noth texture path
	char	*s_texture;						// south texture path
	char	*e_texture;						// east texture path
	char	*w_texture;						// west texture path
	bool	has_duplicated_texture;			// flag to check if in the file has multiple calls to the same direction.
	t_rgb	floor_rgb;
	t_rgb	ceiling_rgb;
	t_perso	player;
}	t_map_data;

// [First guess] Struct for ray casting.
typedef struct s_calcul_data
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	wall_x;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
}	t_calcul_data;

// Global struct that call almost all other structurs
typedef struct s_engine				// [F] [Proposal name] Could be named s_game 
{
	t_map_data		*map_data;
	t_win			*mlx_data;
	t_calcul_data	*cal;
	t_list			*garbage_coll;
	char			**file_raw_data;
	int				size_file_content;
}	t_engine;

/*-------------------------------GET NEXT LINE--------------------------------*/

int		get_next_line(int fd, char **line);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int f);
char	*ft_strjoin_gnl(char *s1, char *s2);

/*-------------------------------ERROR CHECKING-------------------------------*/

void	print_error(char *msg);
void	quit_error(char *msg, t_list *garb_c);
void	quit_error_no_free(char *msg);

// int		check_number_player(char **map);										// TODO erase
// void	check_data_error(t_engine *eng);											// TODO erase static in handler_colors_and_textures.c
int		check_map(char **map);

/*-----------------------------GARBAGE COLLECTOR------------------------------*/

void	*ft_malloc(size_t size, t_list *garb_coll);
void	clear(t_list *garbage_collector);


//*		--------------------------
//*			-------------------
//*			::    Parsing    ::
//*			-------------------
//*		--------------------------

//	-------------------
//	::  Pre Parsing  ::
//	-------------------

bool	handler_pre_parsing(int ac, char **av);
bool	handler_pre_parser_file(char *file_name);
bool	are_win_params_correct(void);


//	---------------
//	::  Parsing  ::
//	---------------

// Handlers: 
void	handler_input_file(t_engine *eng, char **av);
void	handler_colors_and_textures(t_engine *eng);
void	handler_parse_textures(t_engine *engine);

char	**get_map(int start, t_engine *eng);
void	find_map(t_engine *eng);
int		is_map_line(char *line);
// void	set_color(t_rgb *colors, char **split, t_engine *eng);	// TODO erase
// void	test_color(t_engine *eng, char **split);				// TODO erase
// void	check_trim_color(char *str, t_engine *eng);				// TODO erase
// t_rgb	get_color(char *line, t_engine *eng);				// TODO futur main handler in the color init management
// void	extract_file_raw_data(t_engine *eng, char *file_name);	// TODO erase
int		count_line_map(int start, t_engine *eng);
void	init_perso(t_engine *eng);
void	init_color(t_engine *eng, char *line, t_rgb *rgb);
int		get_line_count_in_file(char const *file_name, t_list *garb_c);

//	------------------
//	::  RAYCASTING  ::
//	------------------

int		calcul(t_engine *eng, int x);
int		key_press(int key, t_engine *engine);
int		key_release(int key, t_engine *eng);
void	play(t_engine *eng);
void	draw(t_engine *eng);
void	exec_load(t_engine *eng);
void	load_texture(t_engine *eng);
void	load_image(t_engine *eng, int *texture, char *path, t_data *data);
void	init_side_dist(t_engine *eng);
void	wall_detect(t_engine *eng);
void	calcul_dist_wall(t_engine *eng);
void	init_var(t_engine *eng, int x);
void	wall_draw(t_engine *eng, int x, int y, int z);
void	ceiling_or_floor(t_engine *eng, int x, int q);
int		get_move(t_engine *eng);
void	right_pers(t_engine *eng);
void	left_pers(t_engine *eng);
void	move_up(t_engine *eng);
void	move_down(t_engine *eng);
void	move_left(t_engine *eng);
void	move_right(t_engine *eng);

/*------------------------------------IHM-------------------------------------*/

// void	init_ihm(t_win *mlx_data); // [fede] function doesn't exist.	// TODO erase
void	ft_destroy_mlx(t_win *mlx_data);


//*		------------------------
//*			-----------------
//*			::    Utils    ::
//*			-----------------
//*		------------------------


//	---------------
//	::  Inits   ::
//	---------------
void	init_engine(t_engine *eng, char **av, char **first);


int		composed_with(char *str, const char *set);
int		is_in_set(char c, const char *set);
int		count_str(char **tab);
void	clear_str_tab(char **tab);
void	trim_split(char **tab);
char	*ft_str_dup_cub(char *str, t_list *garb_c);
bool	is_orientation_char(char c);
void	fill_map(t_map_data *data, t_list *garb_c);

#endif