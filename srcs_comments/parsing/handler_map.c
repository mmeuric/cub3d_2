/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:28:52 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:04:31 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will validate if its a map line or not.
static bool	is_map_line(char *line)
{
	int	i;

	if (!ft_strncmp((const char *)line, "NO", 2) ||
		!ft_strncmp((const char *)line, "SO", 2) ||
		!ft_strncmp((const char *)line, "EA", 2) ||
		!ft_strncmp((const char *)line, "WE", 2))
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		if (!is_in_char_set(line[i], " \t10NWES"))
			return (false);
		if (is_in_char_set(line[i], " \t10NWES"))
			return (true);
		i++;
	}
	return (false);
}

/*
	Will be used to  scrap the map from the file (raw_data) 
	and to add it to map_data->(char **)map
*/
static void init_map_data(int start, t_game *game)
{
	char	**map;
	int		i;

	map = malloc_gc(sizeof(char *) * (get_map_amount_rows(start, game) + 1), game->garbage_coll);
	i = 0;
	while (game->file_raw_data[start])
	{
		map[i] = game->file_raw_data[start];
		start++;
		i++;
	}
	map[i] = NULL;
	game->map_data->map = map;
}

/*
	Will fetch the first index line of the map in the file.
	if the index not founded will return 0 and error must be handled.
	REMINDER : map cannot be at the begining of the file.
	REMINDER : Texture lines + color lines = (min) 6. 
*/
static unsigned int	find_map_in_raw_data(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (game->file_raw_data[i])
	{
		if (is_map_line(game->file_raw_data[i]))
			return (i);
		i++;
	}
	return (0);
}

/*
	Will : 
		- find map in input raw_data
		- scrap map and save it into map_data->map
		- update spaces with a simbol
		- parse it
		- error handling will be at the handler_input_file() stage.
*/
bool	handler_map(t_game *game)
{
	unsigned int map_start_at; 

	map_start_at = find_map_in_raw_data(game);
	if (map_start_at < 5)													// there is not map in the file.
		return (false);
	init_map_data(map_start_at, game);
	map_replace_spaces_with_simbols(game->map_data, game->garbage_coll);
	// print_map_data(game);	//* debug.
	// printf("-------\n");
	if (!has_map_one_player(game->map_data->map))						// Will study if there is only 1 cardinal player in the map.
		return (false);
	if (!has_map_valide_atributes(game->map_data->map))					// Will study if only accepted attributs are in the map.
		return (false);
	if (!is_map_pos_context_correct(game->map_data->map))				// Will study the context of every "0" & cardinal player simbol. 
		return (false);
	return (true);

}
