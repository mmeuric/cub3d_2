/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 03:05:15 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/15 15:14:01 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Main raycasting loop that calculates wall distances, 
// texture mapping, and draws each vertical slice.
int	compute_projection(t_game *game, int x)
{	
	while (x < SCREEN_W)
	{
		init_raycast_column(game, x);
		init_side_dist(game);
		game->cal->slice_h = (int)(SCREEN_H / game->cal->wall_distance);
		game->cal->draw_start = -(game->cal->slice_h) / 2 + SCREEN_H / 2;
		if (game->cal->draw_start < 0)
			game->cal->draw_start = 0;
		game->cal->draw_end = game->cal->slice_h / 2 + SCREEN_H / 2;
		if (game->cal->draw_end >= SCREEN_H)
			game->cal->draw_end = SCREEN_H - 1;
		map_texture_coords(game);
		game->cal->texture_step = 1.0 * TEXTURE_H / game->cal->slice_h;
		game->cal->texture_coor = (game->cal->draw_start - SCREEN_H / 2
				+ game->cal->slice_h / 2) * game->cal->texture_step;
		render_ceiling_floor(game, x, 0);
		render_ceiling_floor(game, x, 1);
		paint_wall_segment(game, x, game->cal->draw_start, game->cal->draw_end);
		x++;
	}
	return (0);
}