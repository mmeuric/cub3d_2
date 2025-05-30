/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:17:31 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:17:35 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initializes the engine components: MLX, player, map, image buffer, flags.
void	init_mlx_data(t_game *game)
{
	game->mlx_data->mlx = mlx_init();
	init_player(game);
	game->map_data->map[(int)game->map_data->player.coor_y]
	[(int)game->map_data->player.coor_x] = '0';
	run_asset_loader(game);
	game->mlx_data->flag_buf = false;
	game->mlx_data->mlx_sreen = mlx_new_window(game->mlx_data->mlx,
			SCREEN_W, SCREEN_H, "cub3d");
	game->mlx_data->data.img = mlx_new_image(game->mlx_data->mlx,
			SCREEN_W, SCREEN_H);
	game->mlx_data->data.data = (int *)mlx_get_data_addr(
			game->mlx_data->data.img,
			&game->mlx_data->data.bits_per_pixel, &game->mlx_data->data.line_l,
			&game->mlx_data->data.endian);
	game->mlx_data->k_up = 0;
	game->mlx_data->k_down = 0;
	game->mlx_data->rot_r = 0;
	game->mlx_data->rot_l = 0;
	game->mlx_data->k_left = 0;
	game->mlx_data->k_right = 0;
}

// Sets up event hooks and starts the main rendering loop.
void	start_game_loop(t_game *game)
{
	mlx_hook(game->mlx_data->mlx_sreen, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx_data->mlx_sreen, 3, 1L << 1, &key_release, game);
	mlx_hook(game->mlx_data->mlx_sreen, 17, 0, &close_engine, game);
	mlx_loop_hook(game->mlx_data->mlx, &poll_movement_input, game);
	mlx_loop(game->mlx_data->mlx);
}
