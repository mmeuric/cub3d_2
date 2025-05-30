/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_calcul_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:42:28 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/15 15:11:20 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculates texture number and X coordinate for texture mapping based on wall hit position.
void	map_texture_coords(t_game *game)
{
	game->cal->texture_id = game->map_data->map[game->cal->tile_y][game->cal->tile_x]
		- 48;
	game->cal->texture_x = (int)(game->cal->wall_strike_pos * (double)TEXTURE_W);
	if (game->cal->side == 0 && game->cal->ray_dir_x > 0)
		game->cal->texture_x = TEXTURE_W - game->cal->texture_x - 1;
	if (game->cal->side == 1 && game->cal->ray_dir_y < 0)
		game->cal->texture_y = TEXTURE_W - game->cal->texture_x - 1;
}
