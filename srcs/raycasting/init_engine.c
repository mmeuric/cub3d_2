/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:21:38 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 02:56:12 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes the engine components: MLX, player, map, image buffer, flags.
void	init_engine2(t_engine *eng)
{
	eng->mlx_data->mlx = mlx_init();
	init_perso(eng); // Init player from parsed data

	// Clear player start cell to avoid collision
	eng->map_data->map[(int)eng->map_data->player.pos_y]
	[(int)eng->map_data->player.pos_x] = '0';

	exec_load(eng); // Load textures and other assets
	eng->mlx_data->re_buf = 0;

	// Create window and image
	eng->mlx_data->mlx_win = mlx_new_window(eng->mlx_data->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	eng->mlx_data->data.img = mlx_new_image(eng->mlx_data->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	eng->mlx_data->data.data = (int *)mlx_get_data_addr(eng->mlx_data->data.img,
			&eng->mlx_data->data.bpp, &eng->mlx_data->data.line_length,
			&eng->mlx_data->data.endian);

	// Initialize movement flags
	eng->mlx_data->up = 0;
	eng->mlx_data->down = 0;
	eng->mlx_data->right_pers = 0;
	eng->mlx_data->left_pers = 0;
	eng->mlx_data->left = 0;
	eng->mlx_data->right = 0;
}

// Sets up event hooks and starts the main rendering loop.
void	start_game_loop(t_engine *eng)
{
	// Keyboard and window event hooks
	mlx_hook(eng->mlx_data->mlx_win, 2, 1L << 0, &key_press, eng);
	mlx_hook(eng->mlx_data->mlx_win, 3, 1L << 1, &key_release, eng);
	mlx_hook(eng->mlx_data->mlx_win, 17, 0, &close_engine, eng);

	// Game logic/rendering loop hook
	mlx_loop_hook(eng->mlx_data->mlx, &get_move, eng);
	mlx_loop(eng->mlx_data->mlx);
}