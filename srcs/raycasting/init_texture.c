/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:38:49 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 01:49:17 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_texture(t_engine *eng)
{
	int	i;
	int	j;

	eng->mlx_data->texture = (int **)ft_malloc(sizeof(int *)
			* 4, eng->garbage_coll);
	if (!(eng->mlx_data->texture))
		quit_error(MALLOC_ERROR, eng->garbage_coll);
	i = -1;
	while (++i < 4)
	{
		eng->mlx_data->texture[i] = (int *)ft_malloc(sizeof(int) * (TEX_HEIGHT
					* TEX_WIDTH), eng->garbage_coll);
		if (!eng->mlx_data->texture[i])
			quit_error(MALLOC_ERROR, eng->garbage_coll);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			eng->mlx_data->texture[i][j] = 0;
	}
}