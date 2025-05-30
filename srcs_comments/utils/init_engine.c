/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:32:58 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 13:46:21 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *game, char **av, char **first)
{
    *first = malloc(sizeof(char));
    if (!*first)
        err_msg_exit("IG : err malloc");
    game->garbage_coll = ft_lstnew(*first);
    game->map_data = malloc_gc(sizeof(t_map), game->garbage_coll);
	if (!game->map_data)
		err_msg_exit("IG : err malloc");
    game->mlx_data = malloc_gc(sizeof(t_screen), game->garbage_coll);
	if (!game->mlx_data)
		err_msg_exit("IG : err malloc");
    game->cal = malloc_gc(sizeof(t_raycast_info), game->garbage_coll);
	if (!game->cal)
		err_msg_exit("IG : err malloc");
    game->file_len = get_file_len(av[1], game->garbage_coll);
    game->file_raw_data = malloc_gc(sizeof(char *) * (game->file_len + 1), game->garbage_coll);
	if (!game->file_raw_data)
		err_msg_exit("IG : err malloc");
}