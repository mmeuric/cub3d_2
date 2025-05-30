/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:17:51 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:17:53 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Allocates memory for textures and initializes them to zero.
void	alloc_texture_buffer(t_game *game)
{
	int	i;
	int	j;

	game->mlx_data->texture = (int **)malloc_gc(sizeof(int *)
			* 4, game->garbage_coll);
	if (!(game->mlx_data->texture))
		err_msg_free_gc_exit("ATB : err malloc", game->garbage_coll);
	i = -1;
	while (++i < 4)
	{
		game->mlx_data->texture[i] = (int *)malloc_gc(sizeof(int) * (TEXTURE_H
					* TEXTURE_W), game->garbage_coll);
		if (!game->mlx_data->texture[i])
			err_msg_free_gc_exit("ATB : err malloc", game->garbage_coll);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEXTURE_H * TEXTURE_W)
			game->mlx_data->texture[i][j] = 0;
	}
}
