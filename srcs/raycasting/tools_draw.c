/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:06 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:08 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Draws a vertical line on screen using texture mapping based
// on the raycasting result.
void	paint_wall_segment(t_game *game, int x, int y, int z)
{
	int	i;
	int	color;

	i = y;
	while (i < z)
	{
		game->cal->texture_y
			= (int)game->cal->texture_coor & (TEXTURE_H - 1);
		game->cal->texture_coor += game->cal->texture_step;
		color = game->mlx_data->texture[game->cal->texture_id]
		[TEXTURE_H * game->cal->texture_y + game->cal->texture_x];
		calcul_wall_color_sn(game, &color);
		calcul_wall_color_ew(game, &color);
		game->mlx_data->buf[i][x] = color;
		game->mlx_data->flag_buf = true;
		i++;
	}
}

// Copies the buffer content to the screen and displays the final image.
void	draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			game->mlx_data->data.data[y * SCREEN_W + x]
				= game->mlx_data->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->mlx_sreen,
		game->mlx_data->data.img, 0, 0);
}

// Fills the buffer with ceiling or floor color based
//  on the 'j' flag (0 = ceiling, 1 = floor).
void	render_ceiling_floor(t_game *game, int x, int j)
{
	int	i;
	int	y;

	i = 0;
	if (j == 0)
	{
		while (i < game->cal->draw_start)
		{
			game->mlx_data->buf[i][x]
				= game->map_data->ceiling_color.output_color;
			game->mlx_data->flag_buf = true;
			i++;
		}
	}
	else
	{
		y = game->cal->draw_end;
		while (y < SCREEN_H)
		{
			game->mlx_data->buf[y]
			[x] = game->map_data->floor_color.output_color;
			game->mlx_data->flag_buf = true;
			y++;
		}
	}
}
