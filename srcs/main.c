/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:20 by abahmani          #+#    #+#             */
/*   Updated: 2025/05/20 12:01:33 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*first;

	handler_pre_parsing(ac, av);
	init_game(&game, av, &first);
	handler_input_file(&game, av);
	start_gameplay(&game);
	if (game.garbage_coll)
		free_garbage_collector(game.garbage_coll);
	return (0);
}
