/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:39:34 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:25:45 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// High-level function to initialize and start the game.
void	play(t_engine *eng)
{
	init_engine2(eng);
	start_game_loop(eng);
}

// Properly closes the engine by freeing all resources and exiting the program.
int	close_engine(t_engine *engine)
{
	ft_destroy_mlx(engine->mlx_data);
	clear(engine->garbage_coll);
	exit(0);
}
