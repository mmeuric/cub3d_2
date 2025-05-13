/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_get_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:11 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 01:56:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_move(t_engine *eng)
{
	move_up(eng);
	move_down(eng);
	move_right(eng);
	move_left(eng);
	right_pers(eng);
	left_pers(eng);
	calcul(eng, 0);
	draw(eng);
	return (0);
}

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