/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:42:28 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:05:36 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculates texture number and X coordinate for texture mapping based on wall hit position.
void	calcul_text(t_engine *eng)
{
	eng->cal->tex_num = eng->map_data->map[eng->cal->map_y][eng->cal->map_x]
		- 48;
	eng->cal->tex_x = (int)(eng->cal->wall_x * (double)TEX_WIDTH);
	if (eng->cal->side == 0 && eng->cal->ray_dir_x > 0)
		eng->cal->tex_x = TEX_WIDTH - eng->cal->tex_x - 1;
	if (eng->cal->side == 1 && eng->cal->ray_dir_y < 0)
		eng->cal->tex_y = TEX_WIDTH - eng->cal->tex_x - 1;
}
