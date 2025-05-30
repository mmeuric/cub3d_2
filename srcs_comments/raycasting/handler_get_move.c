/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_get_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:11 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 14:04:20 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handles all player movement and perspective updates, 
// Then performs raycasting and draws the frame.
int	poll_movement_input(t_game *game)
{
	move_right(game);
	move_left(game);
	move_up(game);
	move_down(game);
	rotate_view_right(game);
	rotate_view_left(game);
	compute_projection(game, 0);
	draw(game);
	return (0);
}
