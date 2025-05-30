/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:21 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:26 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Moves the player to the right (strafing), if no wall is in the way.
void	rotate_view_right(t_game *game)
{
	if (game->mlx_data->rot_r)
	{
		if (game->map_data->map[(int)(game->map_data->player.coor_y)]
			[(int)(game->map_data->player.coor_x
				+ game->map_data->player.next_coor_y
				* game->map_data->player.move_speed)] == '0')
			game->map_data->player.coor_x
				+= game->map_data->player.next_coor_y
				* game->map_data->player.move_speed;
		if (game->map_data->map[(int)(game->map_data->player.coor_y
				- game->map_data->player.next_coor_x
				* game->map_data->player.move_speed)]
			[(int)(game->map_data->player.coor_x)] == '0')
			game->map_data->player.coor_y
				-= game->map_data->player.next_coor_x
				* game->map_data->player.move_speed;
	}
}

// Moves the player to the left (strafing), if no wall is in the way.
void	rotate_view_left(t_game *game)
{
	if (game->mlx_data->rot_l)
	{
		if (game->map_data->map[(int)(game->map_data->player.coor_y)]
			[(int)(game->map_data->player.coor_x
				- game->map_data->player.next_coor_y
				* game->map_data->player.move_speed)] == '0')
			game->map_data->player.coor_x
				-= game->map_data->player.next_coor_y
				* game->map_data->player.move_speed;
		if (game->map_data->map[(int)(game->map_data->player.coor_y
				+ game->map_data->player.next_coor_x
				* game->map_data->player.move_speed)]
			[(int)(game->map_data->player.coor_x)] == '0')
			game->map_data->player.coor_y
				+= game->map_data->player.next_coor_x
				* game->map_data->player.move_speed;
	}
}
