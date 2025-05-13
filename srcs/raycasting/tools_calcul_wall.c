/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_calcul_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:42:42 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:22:45 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculates the perpendicular distance from the player to the wall and exact wall hit position.
void	calcul_dist_wall(t_engine *eng)
{
	if (eng->cal->side == 0)
	{
		eng->cal->perp_wall_dist = (eng->cal->map_x
				- eng->map_data->player.pos_x + (1 - eng->cal->step_x) / 2)
			/ eng->cal->ray_dir_x;
	}
	else
	{
		eng->cal->perp_wall_dist = (eng->cal->map_y
				- eng->map_data->player.pos_y + (1 - eng->cal->step_y) / 2)
			/ eng->cal->ray_dir_y;
	}
	if (eng->cal->side == 0)
	{
		eng->cal->wall_x = eng->map_data->player.pos_y
			+ eng->cal->perp_wall_dist * eng->cal->ray_dir_y;
	}
	else
	{
		eng->cal->wall_x = eng->map_data->player.pos_x
			+ eng->cal->perp_wall_dist * eng->cal->ray_dir_x;
	}
	eng->cal->wall_x -= floor(eng->cal->wall_x);
}

// Performs DDA algorithm to detect a wall hit and sets raycasting side; calls distance calculation.
void	wall_detect(t_engine *eng)
{
	while (eng->cal->hit == 0)
	{
		if (eng->cal->side_dist_x < eng->cal->side_dist_y)
		{
			eng->cal->side_dist_x += eng->cal->delta_dist_x;
			eng->cal->map_x += eng->cal->step_x;
			eng->cal->side = 0;
		}
		else
		{
			eng->cal->side_dist_y += eng->cal->delta_dist_y;
			eng->cal->map_y += eng->cal->step_y;
			eng->cal->side = 1;
		}
		if (eng->map_data->map[eng->cal->map_y][eng->cal->map_x] > 48)
			eng->cal->hit = 1;
	}
	calcul_dist_wall(eng);
}

// Chooses the correct wall texture color for east/west facing walls.
void	calcul_wall_color_east_west(t_engine *eng, int *color)
{
	if (eng->cal->side == 1)
	{
		if (eng->cal->map_y + (1 - eng->cal->step_y)
			/ 2 > eng->map_data->player.pos_y)
		{
			*color = eng->mlx_data->texture[0]
			[TEX_HEIGHT * eng->cal->tex_y + eng->cal->tex_x];
		}
		else
		{
			*color = eng->mlx_data->texture[1]
			[TEX_HEIGHT * eng->cal->tex_y + eng->cal->tex_x];
		}	
	}
}

// Chooses the correct wall texture color for north/south facing walls and applies shading.
void	calcul_wall_color_south_north(t_engine *eng, int *color)
{
	if (eng->cal->map_x + (1 - eng->cal->step_x)
		/ 2 > eng->map_data->player.pos_x)
	{
		*color = eng->mlx_data->texture[3]
		[TEX_HEIGHT * eng->cal->tex_y + eng->cal->tex_x];
	}
	else
	{
		*color = eng->mlx_data->texture[2]
		[TEX_HEIGHT * eng->cal->tex_y + eng->cal->tex_x];
	}
	*color = (*color >> 1) & 8355711;
}
