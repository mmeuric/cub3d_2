/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:43:35 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:22:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draws a vertical line on screen using texture mapping based on the raycasting result.
void	wall_draw(t_engine *eng, int x, int y, int z)
{
	int	i;
	int	color;

	i = y;
	while (i < z)
	{
		eng->cal->tex_y = (int)eng->cal->tex_pos & (TEX_HEIGHT - 1);
		eng->cal->tex_pos += eng->cal->step;
		color = eng->mlx_data->texture[eng->cal->tex_num]
		[TEX_HEIGHT * eng->cal->tex_y + eng->cal->tex_x];
		calcul_wall_color_south_north(eng, &color);
		calcul_wall_color_east_west(eng, &color);
		eng->mlx_data->buf[i][x] = color;
		eng->mlx_data->re_buf = 1;
		i++;
	}
}

// Copies the buffer content to the screen and displays the final image.
void	draw(t_engine *eng)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			eng->mlx_data->data.data[y * SCREEN_WIDTH + x]
				= eng->mlx_data->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(eng->mlx_data->mlx, eng->mlx_data->mlx_win,
		eng->mlx_data->data.img, 0, 0);
}

// Fills the buffer with ceiling or floor color based on the 'q' flag (0 = ceiling, 1 = floor).
void	ceiling_or_floor(t_engine *eng, int x, int q)
{
	int	i;
	int	y;

	i = 0;
	if (q == 0)
	{
		while (i < eng->cal->draw_start)
		{
			eng->mlx_data->buf[i][x] = eng->map_data->ceiling_rgb.color;
			eng->mlx_data->re_buf = 1;
			i++;
		}
	}
	else
	{
		y = eng->cal->draw_end;
		while (y < SCREEN_HEIGHT)
		{
			eng->mlx_data->buf[y]
			[x] = eng->map_data->floor_rgb.color;
			eng->mlx_data->re_buf = 1;
			y++;
		}
	}
}