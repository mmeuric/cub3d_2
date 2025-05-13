/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:40:46 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:31:38 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Clears the screen buffer and loads textures into memory.
void	exec_load(t_engine *eng)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			eng->mlx_data->buf[i][j] = 0;
	}
	malloc_texture(eng);
	load_texture(eng);
}