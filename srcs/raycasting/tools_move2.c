/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 03:27:41 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:34:54 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Moves the player to the right (strafing), if no wall is in the way.
void	right_pers(t_engine *eng)
{
	if (eng->mlx_data->right_pers)
	{
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y)]
			[(int)(eng->map_data->player.pos_x + eng->map_data->player.dir_y
			* eng->map_data->player.move_speed)] == '0')
			eng->map_data->player.pos_x += eng->map_data->player.dir_y
				* eng->map_data->player.move_speed;
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y
				- eng->map_data->player.dir_x
				* eng->map_data->player.move_speed)]
			[(int)(eng->map_data->player.pos_x)] == '0')
				eng->map_data->player.pos_y -= eng->map_data->player.dir_x
				* eng->map_data->player.move_speed;
	}
}

// Moves the player to the left (strafing), if no wall is in the way.
void	left_pers(t_engine *eng)
{
	if (eng->mlx_data->left_pers)
	{
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y)]
			[(int)(eng->map_data->player.pos_x - eng->map_data->player.dir_y
			* eng->map_data->player.move_speed)] == '0')
				eng->map_data->player.pos_x -= eng->map_data->player.dir_y
				* eng->map_data->player.move_speed;
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y
				+ eng->map_data->player.dir_x
				* eng->map_data->player.move_speed)]
			[(int)(eng->map_data->player.pos_x)] == '0')
				eng->map_data->player.pos_y += eng->map_data->player.dir_x
				* eng->map_data->player.move_speed;
	}
}
