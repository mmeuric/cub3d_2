/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_texture_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:31 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:35 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Loads image from file and copies its pixel data into the provided t. array.
void	decode_image_asset(t_game *game, int *texture, char *path,
	t_img_buff *data)
{
	int	y;
	int	x;

	y = 0;
	data->img = mlx_xpm_file_to_image(game->mlx_data->mlx, path,
			&data->img_w, &data->img_h);
	data->data = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->size_l, &data->endian);
	while (y < data->img_h)
	{
		x = 0;
		while (x < data->img_w)
		{
			texture[data->img_w * y + x] = data->data[data->img_w
				* y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx_data->mlx, data->img);
}

// Loads all four wall textures (north, south, east, west) using load_image().
void	import_textures(t_game *game)
{
	t_img_buff	img;

	decode_image_asset(game, game->mlx_data->texture[0],
		game->map_data->n_texture, &img);
	decode_image_asset(game, game->mlx_data->texture[1],
		game->map_data->s_texture, &img);
	decode_image_asset(game, game->mlx_data->texture[2],
		game->map_data->e_texture, &img);
	decode_image_asset(game, game->mlx_data->texture[3],
		game->map_data->w_texture, &img);
}
