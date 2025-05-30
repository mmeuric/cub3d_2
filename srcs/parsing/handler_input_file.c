/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:21 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:16:23 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will init all data realated to the map to NULL / 0
static void	init_map_data_null(t_game *game)
{
	game->map_data->n_texture = NULL;
	game->map_data->s_texture = NULL;
	game->map_data->w_texture = NULL;
	game->map_data->e_texture = NULL;
	game->map_data->ceiling_color.is_inited = false;
	game->map_data->floor_color.is_inited = false;
	game->map_data->has_duplicated_texture = false;
}

// Will scrap from the inputed file and create a copy into
// char** game->file_raw_data.
static void	extract_file_raw_data(t_game *game, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		err_msg_free_gc_exit("EFRD : err opening fd", game->garbage_coll);
	i = 0;
	while (i < game->file_len)
	{
		get_next_line(fd, &line);
		ft_lstadd_back(&game->garbage_coll, ft_lstnew(line));
		game->file_raw_data[i++] = line;
	}
	game->file_raw_data[i] = NULL;
	close(fd);
}

// ***** Main parsing handler. ******
/* 
	handler_input_file will: 
		- init data to null, 
		- extract raw_data:  from the inputed file to 
			game->(char **)file_raw_data, 
		- pre clean raw_file_data
		- will init and check textures(N,W,S,E) and colors(C,F),
		- parse the inputed file, 
		- init the (char **)map.
		- parse map.
*/
void	handler_input_file(t_game *game, char **av)
{
	init_map_data_null(game);
	extract_file_raw_data(game, av[1]);
	handler_pre_clean_file(game);
	handler_colors_and_textures(game, game->map_data);
	if (!handler_map(game))
		err_msg_free_gc_exit("HM : Error parsing", game->garbage_coll);
}
