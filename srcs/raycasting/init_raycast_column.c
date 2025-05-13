/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_column.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:35:55 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 02:33:02 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast_column(t_engine *eng, int x)
{
	(void)x;
	eng->cal->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	eng->cal->ray_dir_x = eng->map_data->player.dir_x
		+ eng->map_data->player.plane_x * eng->cal->camera_x;
	eng->cal->ray_dir_y = eng->map_data->player.dir_y
		+ eng->map_data->player.plane_y * eng->cal->camera_x;
	eng->cal->map_x = (int)eng->map_data->player.pos_x;
	eng->cal->map_y = (int)eng->map_data->player.pos_y;
	eng->cal->delta_dist_x = fabs(1 / eng->cal->ray_dir_x);
	eng->cal->delta_dist_y = fabs(1 / eng->cal->ray_dir_y);
	eng->cal->hit = 0;
}