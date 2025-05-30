/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:21:10 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 15:02:15 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <strings.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"

//*		---------------------------------
//*			-------------------------
//*			::    Global params    ::
//*			-------------------------
//*		---------------------------------

//	----------------------
//	::       GNL        ::
//	----------------------

# define BUFFER_SIZE 20

//	----------------------
//	::  texture params  ::
//	----------------------

# define TEXTURE_W 64
# define TEXTURE_H 64

//	---------------------
//	::  Screen params  ::
//	---------------------

# define SCREEN_W 720
# define SCREEN_H 480

//	---------------------
//	::  Player params  ::
//	---------------------

# define PLAYER_MOVE_SPEED 0.071
# define PLAYER_ROT_SPEED 0.0351

//*		-------------------------------
//*			-----------------------
//*			::    Structures  ::
//*			-----------------------
//*		-------------------------------

//* Data Image Buffer
typedef struct s_img_buff
{
	int		img_w;
	int		img_h;
	int		bits_per_pixel;
	int		endian;
	int		*data;
	int		line_l;
	int		size_l;
	void	*img;
}	t_img_buff;

//** Window Screen
typedef struct s_screen
{
	int			color;
	int			k_up;
	int			k_down;
	int			k_right;
	int			k_left;
	int			rot_l;
	int			rot_r;
	void		*mlx;
	void		*mlx_sreen;
	void		*mlx_img;
	int			**texture;
	bool		flag_buf;
	int			buf[SCREEN_H][SCREEN_W];
	t_img_buff	data;
}	t_screen;

//* Player data.
typedef struct s_player
{
	double	cur_plane_x;
	double	cur_plane_y;
	double	move_speed;
	double	rot_speed;
	double	coor_x;
	double	coor_y;
	double	next_coor_x;
	double	next_coor_y;
}	t_player;

//* calculated Color data
typedef struct s_color
{
	int		output_color;
	bool	is_inited;
}	t_color;

// Map, textures, F/C colors, player data
typedef struct s_map
{
	char		**map;
	char		*n_texture;
	char		*s_texture;
	char		*e_texture;
	char		*w_texture;
	bool		has_duplicated_texture;
	t_color		floor_color;
	t_color		ceiling_color;
	t_player	player;
}	t_map;

//* Raycasting data.
typedef struct s_raycast_info
{
	int		step_x;
	int		step_y;
	int		tile_x;
	int		tile_y;
	int		wall_strike;
	int		draw_start;
	int		draw_end;
	int		side;
	int		slice_h;
	int		texture_id;
	int		texture_x;
	int		texture_y;
	double	wall_strike_pos;
	double	texture_step;
	double	screen_ray_pos;
	double	ray_dir_x;
	double	ray_dir_y;
	double	wall_distance;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	texture_coor;
}	t_raycast_info;

//* Global struct that call almost all other structurs
typedef struct s_game
{
	char			**file_raw_data;
	int				file_len;
	t_map			*map_data;
	t_list			*garbage_coll;
	t_screen		*mlx_data;
	t_raycast_info	*cal;
}	t_game;

//*		------------------------------
//*			----------------------
//*			::    Functions  ::
//*			----------------------
//*		------------------------------

//	-----------
//	::  GNL  ::
//	-----------
int		get_next_line(int fd, char **line);
int		ft_strlength(char *str);
void	ft_strncat(char *dest, char *src, int n);
void	ft_strcpy_from(char *dest, char *src, int j);
int		ft_update_line(char **line, int j, char *buffer);
int		ft_read_file(int fd, char *buffer, char *buf_remains, char **line);
int		ft_finish_buffer(char *buffer, char *buf_remains, char **line);
void	ft_empty_buffer(char *buf_remains);
char	*ft_strdup(const char *s1);

//	----------------------
//	::  Error handling  ::
//	----------------------

void	err_msg_exit(char *err_msg);
void	err_msg_free_gc_exit(char *err_msg, t_list *g_c);

//	-------------------------
//	::  Garbage collector  ::
//	-------------------------

// g_c = garbage collector 

void	free_garbage_collector(t_list *g_c);
void	*malloc_gc(size_t size, t_list *g_c);

//*		--------------------------
//*			-------------------
//*			::    Parsing    ::
//*			-------------------
//*		--------------------------

//	-------------------
//	::  Pre Parsing  ::
//	-------------------

bool	are_win_params_correct(void);
void	handler_pre_parsing(int ac, char **av);
bool	handler_pre_parser_file(char *file_name);

//	---------------
//	::  Parsing  ::
//	---------------

// Handlers: 
bool	handler_map(t_game *game);
void	handler_pre_clean_file(t_game *game);
void	handler_input_file(t_game *game, char **av);
void	handler_parse_textures(t_game *game, t_map *d_map);
void	handler_colors_and_textures(t_game *game, t_map *d_map);
void	handler_init_parse_colors(t_game *game, char *line, t_color *rgb);

// Inits:
void	init_player(t_game *game);

//	------------------
//	::  RAYCASTING  ::
//	------------------

void	draw(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	wall_detect(t_game *game);
int		close_engine(t_game *game);
void	init_mlx_data(t_game *game);
void	start_gameplay(t_game *game);
void	init_side_dist(t_game *game);
void	import_textures(t_game *game);
void	start_game_loop(t_game *game);
void	run_asset_loader(t_game *game);
void	rotate_view_left(t_game *game);
void	rotate_view_right(t_game *game);
int		key_press(int key, t_game *game);
void	map_texture_coords(t_game *game);
int		poll_movement_input(t_game *game);
int		key_release(int key, t_game *game);
void	alloc_texture_buffer(t_game *game);
void	measure_wall_distance(t_game *game);
int		compute_projection(t_game *game, int i);
void	init_raycast_column(t_game *game, int x);
void	calcul_wall_color_sn(t_game *game, int *color);
void	calcul_wall_color_ew(t_game *game, int *color);
void	render_ceiling_floor(t_game *game, int x, int i);
void	paint_wall_segment(t_game *game, int x, int y, int z);
void	decode_image_asset(t_game *game,
			int *texture, char *path, t_img_buff*data);

//	---------------
//	::  IHM   ::
//	---------------

void	ft_destroy_mlx(t_screen *mlx_data);

//*		------------------------
//*			-----------------
//*			::    Utils    ::
//*			-----------------
//*		------------------------

//	---------------
//	::  Inits   ::
//	---------------
void	init_game(t_game *game, char **av, char **first);

// tools_str :
bool	ft_isspace(char c);
bool	is_c_need_after_trim(char *line);
bool	is_t_need_after_trim(char *line);
bool	is_t_c_need_pre_trim(char *line);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
bool	is_in_char_set(char c, char *char_set);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

// tools_file : 
int		get_file_len(char *input_file, t_list *g_c);
int		get_map_amount_rows(int map_start_at, t_game *game);

// tools_parse_map : 
bool	has_map_one_player(char **map);
bool	has_map_valide_atributes(char **map);
bool	is_map_pos_context_correct(char **map);

// tools_map : 
int		array_len(char **tab);
bool	is_cardinal_player(char c);
void	map_replace_spaces_with_simbols(t_map *data, t_list *g_c);

#endif