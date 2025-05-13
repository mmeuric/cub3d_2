/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_get_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:41:11 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/13 03:28:56 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Handles all player movement and perspective updates, 
// Then performs raycasting and draws the frame.
int	get_move(t_engine *eng)
{
	move_up(eng);
	move_down(eng);
	move_right(eng);
	move_left(eng);
	right_pers(eng);
	left_pers(eng);
	calcul(eng, 0);
	draw(eng);
	return (0);
}
