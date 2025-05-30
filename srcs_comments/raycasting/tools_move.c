/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:44 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 16:29:15 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Moves the player forward based on the current direction, if no wall is in the way.
void	move_up(t_game *game)
{
	if (game->mlx_data->k_up)
	{
		if (game->map_data->map[(int)(game->map_data->player.coor_y)]
			[(int)(game->map_data->player.coor_x + game->map_data->player.next_coor_x
			* game->map_data->player.move_speed)] == '0')
			game->map_data->player.coor_x += game->map_data->player.next_coor_x
				* game->map_data->player.move_speed;
		if (game->map_data->map[(int)(game->map_data->player.coor_y
				+ game->map_data->player.next_coor_y
				* game->map_data->player.move_speed)]
			[(int)(game->map_data->player.coor_x)] == '0')
			game->map_data->player.coor_y += game->map_data->player.next_coor_y
				* game->map_data->player.move_speed;
	}
}

// Moves the player backward based on the current direction, if no wall is in the way.
void	move_down(t_game *game)
{
	if (game->mlx_data->k_down)
	{
		if (game->map_data->map[(int)(game->map_data->player.coor_y)]
		[(int)(game->map_data->player.coor_x - game->map_data->player.next_coor_x
		* game->map_data->player.move_speed)] == '0')
			game->map_data->player.coor_x -= game->map_data->player.next_coor_x
				* game->map_data->player.move_speed;
		if (game->map_data->map[(int)(game->map_data->player.coor_y
				- game->map_data->player.next_coor_y
				* game->map_data->player.move_speed)]
			[(int)(game->map_data->player.coor_x)] == '0')
			game->map_data->player.coor_y -= game->map_data->player.next_coor_y
				* game->map_data->player.move_speed;
	}
}

// Rotates the player's view to the left by updating direction and camera plane vectors.
void	move_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->mlx_data->k_left)
	{
		old_dir_x = game->map_data->player.next_coor_x;
		game->map_data->player.next_coor_x = game->map_data->player.next_coor_x
			* cos(game->map_data->player.rot_speed) - game->map_data->player.next_coor_y
			* sin(game->map_data->player.rot_speed);
			game->map_data->player.next_coor_y = old_dir_x
			* sin(game->map_data->player.rot_speed) + game->map_data->player.next_coor_y
			* cos(game->map_data->player.rot_speed);
				old_plane_x = game->map_data->player.cur_plane_x;
		game->map_data->player.cur_plane_x = game->map_data->player.cur_plane_x
			* cos(game->map_data->player.rot_speed)
			- game->map_data->player.cur_plane_y
			* sin(game->map_data->player.rot_speed);
			game->map_data->player.cur_plane_y = old_plane_x
			* sin(game->map_data->player.rot_speed)
			+ game->map_data->player.cur_plane_y
			* cos(game->map_data->player.rot_speed);
	}
}

// Rotates the player's view to the right by updating direction and camera plane vectors.
void	move_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->mlx_data->k_right)
	{
		old_dir_x = game->map_data->player.next_coor_x;
		game->map_data->player.next_coor_x = game->map_data->player.next_coor_x
			* cos(-game->map_data->player.rot_speed)
			- game->map_data->player.next_coor_y
			* sin(-game->map_data->player.rot_speed);
				game->map_data->player.next_coor_y = old_dir_x
			* sin(-game->map_data->player.rot_speed)
			+ game->map_data->player.next_coor_y
			* cos(-game->map_data->player.rot_speed);
		old_plane_x = game->map_data->player.cur_plane_x;
		game->map_data->player.cur_plane_x = game->map_data->player.cur_plane_x
			* cos(-game->map_data->player.rot_speed)
			- game->map_data->player.cur_plane_y
			* sin(-game->map_data->player.rot_speed);
		game->map_data->player.cur_plane_y = old_plane_x
			* sin(-game->map_data->player.rot_speed)
			+ game->map_data->player.cur_plane_y
			* cos(-game->map_data->player.rot_speed);
	}
}