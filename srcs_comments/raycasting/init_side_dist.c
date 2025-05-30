/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_side_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:37:53 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/15 15:11:20 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes horizontal step direction and initial side distance based on ray X direction.
void	init_side_dist_x(t_game *game)
{
	if (game->cal->ray_dir_x < 0)
	{
		game->cal->step_x = -1;
		game->cal->side_dist_x = (game->map_data->player.coor_x - game->cal->tile_x)
			* game->cal->delta_dist_x;
	}
	else
	{
		game->cal->step_x = 1;
		game->cal->side_dist_x = (game->cal->tile_x + 1.0
				- game->map_data->player.coor_x) * game->cal->delta_dist_x;
	}
}

// Initializes vertical step direction and initial side distance based on ray Y direction.
void	init_side_dist_y(t_game *game)
{
	if (game->cal->ray_dir_y < 0)
	{
		game->cal->step_y = -1;
		game->cal->side_dist_y = (game->map_data->player.coor_y - game->cal->tile_y)
			* game->cal->delta_dist_y;
	}
	else
	{
		game->cal->step_y = 1;
		game->cal->side_dist_y = (game->cal->tile_y + 1.0
				- game->map_data->player.coor_y) * game->cal->delta_dist_y;
	}
}

// Combines horizontal and vertical side distance initialization and starts wall detection.
void	init_side_dist(t_game *game)
{
	init_side_dist_x(game);
	init_side_dist_y(game);
	wall_detect(game);
}