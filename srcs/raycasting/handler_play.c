/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:17:26 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:17:28 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// High-level function to initialize and start the game.
void	start_gameplay(t_game *game)
{
	init_mlx_data(game);
	start_game_loop(game);
}

// Properly closes the engine by freeing all resources and exiting the program.
int	close_engine(t_game *game)
{
	ft_destroy_mlx(game->mlx_data);
	free_garbage_collector(game->garbage_coll);
	exit(0);
}
