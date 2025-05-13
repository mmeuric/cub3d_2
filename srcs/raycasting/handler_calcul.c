/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 03:05:15 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:05:45 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Main raycasting loop that calculates wall distances, 
// texture mapping, and draws each vertical slice.
int	calcul(t_engine *eng, int x)
{	
	while (x < SCREEN_WIDTH)
	{
		init_raycast_column(eng, x);
		init_side_dist(eng);
		eng->cal->line_height = (int)(SCREEN_HEIGHT / eng->cal->perp_wall_dist);
		eng->cal->draw_start = -(eng->cal->line_height) / 2 + SCREEN_HEIGHT / 2;
		if (eng->cal->draw_start < 0)
			eng->cal->draw_start = 0;
		eng->cal->draw_end = eng->cal->line_height / 2 + SCREEN_HEIGHT / 2;
		if (eng->cal->draw_end >= SCREEN_HEIGHT)
			eng->cal->draw_end = SCREEN_HEIGHT - 1;
		calcul_text(eng);
		eng->cal->step = 1.0 * TEX_HEIGHT / eng->cal->line_height;
		eng->cal->tex_pos = (eng->cal->draw_start - SCREEN_HEIGHT / 2
				+ eng->cal->line_height / 2) * eng->cal->step;
		ceiling_or_floor(eng, x, 0);
		ceiling_or_floor(eng, x, 1);
		wall_draw(eng, x, eng->cal->draw_start, eng->cal->draw_end);
		x++;
	}
	return (0);
}