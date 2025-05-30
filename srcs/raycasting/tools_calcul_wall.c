/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_calcul_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:01 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:03 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculates the perpendicular distance from the player to the wall
// and exact wall hit position.
void	measure_wall_distance(t_game *game)
{
	if (game->cal->side == 0)
	{
		game->cal->wall_distance = (game->cal->tile_x
				- game->map_data->player.coor_x + (1 - game->cal->step_x) / 2)
			/ game->cal->ray_dir_x;
	}
	else
	{
		game->cal->wall_distance = (game->cal->tile_y
				- game->map_data->player.coor_y + (1 - game->cal->step_y) / 2)
			/ game->cal->ray_dir_y;
	}
	if (game->cal->side == 0)
	{
		game->cal->wall_strike_pos = game->map_data->player.coor_y
			+ game->cal->wall_distance * game->cal->ray_dir_y;
	}
	else
	{
		game->cal->wall_strike_pos = game->map_data->player.coor_x
			+ game->cal->wall_distance * game->cal->ray_dir_x;
	}
	game->cal->wall_strike_pos -= floor(game->cal->wall_strike_pos);
}

// Performs DDA algorithm to detect a wall hit and sets raycasting
// side; calls distance calculation.
void	wall_detect(t_game *game)
{
	while (game->cal->wall_strike == 0)
	{
		if (game->cal->side_dist_x < game->cal->side_dist_y)
		{
			game->cal->side_dist_x += game->cal->delta_dist_x;
			game->cal->tile_x += game->cal->step_x;
			game->cal->side = 0;
		}
		else
		{
			game->cal->side_dist_y += game->cal->delta_dist_y;
			game->cal->tile_y += game->cal->step_y;
			game->cal->side = 1;
		}
		if (game->map_data->map[game->cal->tile_y][game->cal->tile_x] > 48)
			game->cal->wall_strike = 1;
	}
	measure_wall_distance(game);
}

// Chooses the correct wall texture color for east/west facing walls.
void	calcul_wall_color_ew(t_game *game, int *color)
{
	if (game->cal->side == 1)
	{
		if (game->cal->tile_y + (1 - game->cal->step_y)
			/ 2 > game->map_data->player.coor_y)
		{
			*color = game->mlx_data->texture[0]
			[TEXTURE_H * game->cal->texture_y + game->cal->texture_x];
		}
		else
		{
			*color = game->mlx_data->texture[1]
			[TEXTURE_H * game->cal->texture_y + game->cal->texture_x];
		}
	}
}

// Chooses the correct wall texture color for north/south
// facing walls and applies shading.
void	calcul_wall_color_sn(t_game *game, int *color)
{
	if (game->cal->tile_x + (1 - game->cal->step_x)
		/ 2 > game->map_data->player.coor_x)
	{
		*color = game->mlx_data->texture[3]
		[TEXTURE_H * game->cal->texture_y + game->cal->texture_x];
	}
	else
	{
		*color = game->mlx_data->texture[2]
		[TEXTURE_H * game->cal->texture_y + game->cal->texture_x];
	}
	*color = (*color >> 1) & 8355711;
}
