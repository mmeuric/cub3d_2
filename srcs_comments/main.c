/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:20 by abahmani          #+#    #+#             */
/*   Updated: 2025/05/14 14:11:48 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game game;
	char *first;

	handler_pre_parsing(ac, av);		// Pre-parsing of first inputed data in the program. 
	init_game(&game, av, &first);		// First init of every struct necesary for the game.
	handler_input_file(&game, av);		// Will handle, init_map, textures and complet parsing while initing.
	start_gameplay(&game);				// Raycasting, game loop, key-events, handling textures. 
	if (game.garbage_coll)
		free_garbage_collector(game.garbage_coll);		// Last free + exit game. 
	return (0);
}