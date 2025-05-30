/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:19:32 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 16:29:15 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_perso_bis(t_game *game, int i, int j)
{
	game->map_data->player.coor_x = j + 0.5;
	game->map_data->player.coor_y = i + 0.5;
	if (game->map_data->map[i][j] == 'W')
	{
		game->map_data->player.next_coor_x = -1;
		game->map_data->player.next_coor_y = 0;
	}
	else if (game->map_data->map[i][j] == 'E')
	{
		game->map_data->player.next_coor_x = 1;
		game->map_data->player.next_coor_y = 0;
	}
	else if (game->map_data->map[i][j] == 'N')
	{
		game->map_data->player.next_coor_x = 0;
		game->map_data->player.next_coor_y = -1;
	}
	else if (game->map_data->map[i][j] == 'S')
	{
		game->map_data->player.next_coor_x = 0;
		game->map_data->player.next_coor_y = 1;
	}
}

void	init_perso(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_data->map[i])
	{
		j = 0;
		while (game->map_data->map[i][j])
		{
			if (is_cardinal_player(game->map_data->map[i][j]))
			{
				init_perso_bis(game, i, j);
			}
			j++;
		}
		i++;
	}
	game->map_data->player.cur_plane_x = (0.66 * (-1 * game->map_data->player.next_coor_y));
	game->map_data->player.cur_plane_y = (0.66 * (game->map_data->player.next_coor_x));
	game->map_data->player.move_speed = PLAYER_MOVE_SPEED;
	game->map_data->player.rot_speed = PLAYER_ROT_SPEED;
}
