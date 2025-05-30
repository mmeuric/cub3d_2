/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:05:42 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 14:54:33 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handles key press events and sets movement flags; exits on ESC key.
int	key_press(int key, t_game *game)
{
	if (key == 65361)
		game->mlx_data->k_right = 1;
	if (key == 65363)
		game->mlx_data->k_left = 1;
	if (key == 119)
		game->mlx_data->k_up = 1;
	if (key == 115)
		game->mlx_data->k_down = 1;
	if (key == 100)
		game->mlx_data->rot_l = 1;
	if (key == 97)
		game->mlx_data->rot_r = 1;
	if (key == 65307)
	{
		ft_destroy_mlx(game->mlx_data);
		free_garbage_collector(game->garbage_coll);
		exit(0);
	}
	return (0);
}

// Handles key release events and resets the corresponding movement flags.
int	key_release(int key, t_game *game)
{
	if (key == 97)
		game->mlx_data->rot_r = 0;
	if (key == 65361)
		game->mlx_data->k_right = 0;
	if (key == 65363)
		game->mlx_data->k_left = 0;
	if (key == 119)
		game->mlx_data->k_up = 0;
	if (key == 115)
		game->mlx_data->k_down = 0;
	if (key == 100)
		game->mlx_data->rot_l = 0;
	return (0);
}
