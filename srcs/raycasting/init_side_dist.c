/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_side_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:37:53 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:00:42 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes horizontal step direction and initial side distance based on ray X direction.
void	init_side_dist_x(t_engine *eng)
{
	if (eng->cal->ray_dir_x < 0)
	{
		eng->cal->step_x = -1;
		eng->cal->side_dist_x = (eng->map_data->player.pos_x - eng->cal->map_x)
			* eng->cal->delta_dist_x;
	}
	else
	{
		eng->cal->step_x = 1;
		eng->cal->side_dist_x = (eng->cal->map_x + 1.0
				- eng->map_data->player.pos_x) * eng->cal->delta_dist_x;
	}
}

// Initializes vertical step direction and initial side distance based on ray Y direction.
void	init_side_dist_y(t_engine *eng)
{
	if (eng->cal->ray_dir_y < 0)
	{
		eng->cal->step_y = -1;
		eng->cal->side_dist_y = (eng->map_data->player.pos_y - eng->cal->map_y)
			* eng->cal->delta_dist_y;
	}
	else
	{
		eng->cal->step_y = 1;
		eng->cal->side_dist_y = (eng->cal->map_y + 1.0
				- eng->map_data->player.pos_y) * eng->cal->delta_dist_y;
	}
}

// Combines horizontal and vertical side distance initialization and starts wall detection.
void	init_side_dist(t_engine *eng)
{
	init_side_dist_x(eng);
	init_side_dist_y(eng);
	wall_detect(eng);
}