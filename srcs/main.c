/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:20 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/19 19:23:19 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_engine eng;
    char *first;

    handler_pre_parsing(ac, av);		// Pre-parsing of first inputed data in the program. 
	init_engine(&eng, av, &first);		// First init of every struct necesary for the game.
	handler_input_file(&eng, av);		// Will handle, init_map, textures and complet parsing while initing.
	play(&eng);							// Raycasting, game loop, key-events, handling textures. 
	if (eng.garbage_coll)
		clear(eng.garbage_coll);		// Last free + exit game. 
	return (0);
}