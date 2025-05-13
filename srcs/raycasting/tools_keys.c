/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:05:42 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:11:42 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handles key press events and sets movement flags; exits on ESC key.
int	key_press(int key, t_engine *engine)
{
	if (key == 119)
		engine->mlx_data->up = 1;
	if (key == 115)
		engine->mlx_data->down = 1;
	if (key == 100)
		engine->mlx_data->left_pers = 1;
	if (key == 97)
		engine->mlx_data->right_pers = 1;
	if (key == 65361)
		engine->mlx_data->right = 1;
	if (key == 65363)
		engine->mlx_data->left = 1;
	if (key == 65307)
	{
		ft_destroy_mlx(engine->mlx_data);
		clear(engine->garbage_coll);
		exit(0);
	}
	return (0);
}

// Handles key release events and resets the corresponding movement flags.
int	key_release(int key, t_engine *eng)
{
	if (key == 119)
		eng->mlx_data->up = 0;
	if (key == 115)
		eng->mlx_data->down = 0;
	if (key == 100)
		eng->mlx_data->left_pers = 0;
	if (key == 97)
		eng->mlx_data->right_pers = 0;
	if (key == 65361)
		eng->mlx_data->right = 0;
	if (key == 65363)
		eng->mlx_data->left = 0;
	return (0);
}
