/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_texture_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:44:04 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:16:43 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Loads an image from file and copies its pixel data into the provided texture array.
void	load_image(t_engine *eng, int *texture, char *path, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->img = mlx_xpm_file_to_image(eng->mlx_data->mlx, path,
			&data->img_width, &data->img_height);
	data->data = (int *)mlx_get_data_addr(data->img, &data->bpp,
			&data->size_l, &data->endian);
	while (y < data->img_height)
	{
		x = 0;
		while (x < data->img_width)
		{
			texture[data->img_width * y + x] = data->data[data->img_width
				* y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(eng->mlx_data->mlx, data->img);
}

// Loads all four wall textures (north, south, east, west) using load_image().
void	load_texture(t_engine *eng)
{
	t_data	img;

	load_image(eng, eng->mlx_data->texture[0], eng->map_data->north_text, &img);
	load_image(eng, eng->mlx_data->texture[1], eng->map_data->south_text, &img);
	load_image(eng, eng->mlx_data->texture[2], eng->map_data->east_text, &img);
	load_image(eng, eng->mlx_data->texture[3], eng->map_data->west_text, &img);
}