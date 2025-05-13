/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:44 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 01:57:25 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_engine *eng)
{
	if (eng->mlx_data->up)
	{
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y)]
			[(int)(eng->map_data->player.pos_x + eng->map_data->player.dir_x
			* eng->map_data->player.move_speed)] == '0')
			eng->map_data->player.pos_x += eng->map_data->player.dir_x
				* eng->map_data->player.move_speed;
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y
				+ eng->map_data->player.dir_y
				* eng->map_data->player.move_speed)]
			[(int)(eng->map_data->player.pos_x)] == '0')
			eng->map_data->player.pos_y += eng->map_data->player.dir_y
				* eng->map_data->player.move_speed;
	}
}

void	move_down(t_engine *eng)
{
	if (eng->mlx_data->down)
	{
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y)]
		[(int)(eng->map_data->player.pos_x - eng->map_data->player.dir_x
		* eng->map_data->player.move_speed)] == '0')
			eng->map_data->player.pos_x -= eng->map_data->player.dir_x
				* eng->map_data->player.move_speed;
		if (eng->map_data->map[(int)(eng->map_data->player.pos_y
				- eng->map_data->player.dir_y
				* eng->map_data->player.move_speed)]
			[(int)(eng->map_data->player.pos_x)] == '0')
			eng->map_data->player.pos_y -= eng->map_data->player.dir_y
				* eng->map_data->player.move_speed;
	}
}

void	move_left(t_engine *eng)
{
	double	old_dir_x;
	double	old_plane_x;

	if (eng->mlx_data->left)
	{
		old_dir_x = eng->map_data->player.dir_x;
		eng->map_data->player.dir_x = eng->map_data->player.dir_x
			* cos(eng->map_data->player.rot_speed) - eng->map_data->player.dir_y
			* sin(eng->map_data->player.rot_speed);
			eng->map_data->player.dir_y = old_dir_x
			* sin(eng->map_data->player.rot_speed) + eng->map_data->player.dir_y
			* cos(eng->map_data->player.rot_speed);
				old_plane_x = eng->map_data->player.plane_x;
		eng->map_data->player.plane_x = eng->map_data->player.plane_x
			* cos(eng->map_data->player.rot_speed)
			- eng->map_data->player.plane_y
			* sin(eng->map_data->player.rot_speed);
			eng->map_data->player.plane_y = old_plane_x
			* sin(eng->map_data->player.rot_speed)
			+ eng->map_data->player.plane_y
			* cos(eng->map_data->player.rot_speed);
	}
}

void	move_right(t_engine *eng)
{
	double	old_dir_x;
	double	old_plane_x;

	if (eng->mlx_data->right)
	{
		old_dir_x = eng->map_data->player.dir_x;
		eng->map_data->player.dir_x = eng->map_data->player.dir_x
			* cos(-eng->map_data->player.rot_speed)
			- eng->map_data->player.dir_y
			* sin(-eng->map_data->player.rot_speed);
				eng->map_data->player.dir_y = old_dir_x
			* sin(-eng->map_data->player.rot_speed)
			+ eng->map_data->player.dir_y
			* cos(-eng->map_data->player.rot_speed);
		old_plane_x = eng->map_data->player.plane_x;
		eng->map_data->player.plane_x = eng->map_data->player.plane_x
			* cos(-eng->map_data->player.rot_speed)
			- eng->map_data->player.plane_y
			* sin(-eng->map_data->player.rot_speed);
		eng->map_data->player.plane_y = old_plane_x
			* sin(-eng->map_data->player.rot_speed)
			+ eng->map_data->player.plane_y
			* cos(-eng->map_data->player.rot_speed);
	}
}