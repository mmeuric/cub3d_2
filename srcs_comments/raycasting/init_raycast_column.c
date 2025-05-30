/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_column.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:35:55 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/15 15:11:20 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes raycasting parameters for a screen column,
// setting ray direction and distance calculations.
void	init_raycast_column(t_game *game, int x)
{
	(void)x;
	game->cal->screen_ray_pos = 2 * x / (double)SCREEN_W - 1;
	game->cal->ray_dir_x = game->map_data->player.next_coor_x
		+ game->map_data->player.cur_plane_x * game->cal->screen_ray_pos;
	game->cal->ray_dir_y = game->map_data->player.next_coor_y
		+ game->map_data->player.cur_plane_y * game->cal->screen_ray_pos;
	game->cal->tile_x = (int)game->map_data->player.coor_x;
	game->cal->tile_y = (int)game->map_data->player.coor_y;
	game->cal->delta_dist_x = fabs(1 / game->cal->ray_dir_x);
	game->cal->delta_dist_y = fabs(1 / game->cal->ray_dir_y);
	game->cal->wall_strike = 0;
}