/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:39:34 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 02:24:21 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_engine(t_engine *engine)
{
	ft_destroy_mlx(engine->mlx_data);
	clear(engine->garbage_coll);
	exit(0);
}

/**
 * @brief High-level function to initialize and start the game.
 */
void	play(t_engine *eng)
{
	init_engine2(eng);
	start_game_loop(eng);
}