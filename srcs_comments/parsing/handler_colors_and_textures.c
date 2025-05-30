/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_colors_and_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:18:58 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:03:08 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_path = texture path
static void	init_texture_path_from_line(char **t_path, t_game *game, char *line)
{
	*t_path = ft_strtrim(line + 2, " \t");									// Trim the input line starting from the third character, removing spaces and tabs.
	ft_lstadd_back(&game->garbage_coll, ft_lstnew(*t_path)); 				// Add the trimmed string to the garbage collector list for memory management.
}

// This function checks if a texture has already been set. For exemples in the file we found more than 1 time the assignation of a texture to a N,W,S,E
// If the texture is already set, it marks the map data as having a duplicate texture.
static bool	is_texture_duplicated(char *cardinal_texture, t_map *d_map)
{
	if (cardinal_texture) 													// If the texture is already set (not NULL)...
	{
		d_map->has_duplicated_texture = true; 								// Mark the map data as having a duplicate texture.
		return (true);
	}
	return (false); 														// Always return 1 (indicating a doublon was found).
}

// This function processes a line of input to extract and store color data for the map.
// It checks the prefix of the line to determine the type of data and handles it accordingly.
static void	handle_colors(t_game *game, t_map *d_map, char *line)
{
	if (!ft_strncmp((const char *) line, "C ", 2))
		handler_init_parse_colors(game, line, &d_map->ceiling_color);														// If the line starts with "C ", initialize the ceiling color using the line.

	else if (!ft_strncmp((const char *) line, "F ", 2))
		handler_init_parse_colors(game, line, &d_map->floor_color);
}

static void	handle_path_textures(t_game *game, t_map *d_map, char *line)
{
	if (!ft_strncmp((const char *) line, "NO ", 3) && !is_texture_duplicated(d_map->n_texture, game->map_data))
		init_texture_path_from_line(&d_map->n_texture, game, line);													 	// If the line starts with "NO " and the north texture is not already set, trim and store the north texture path.

	else if (!ft_strncmp((const char *) line, "SO ", 3) && !is_texture_duplicated(d_map->s_texture, game->map_data))
		init_texture_path_from_line(&d_map->s_texture, game, line);

	else if (!ft_strncmp((const char *) line, "WE ", 3) && !is_texture_duplicated(d_map->w_texture, game->map_data))
		init_texture_path_from_line(&d_map->w_texture, game, line);

	else if (!ft_strncmp((const char *) line, "EA ", 3) && !is_texture_duplicated(d_map->e_texture, game->map_data))
		init_texture_path_from_line(&d_map->e_texture, game, line);
}
/*
	Will :
	- scrap the (char **)file_raw_data.
	- init, xs_parse textures.
	- init, full parse colors.
	- error handling.

	Reminder : 
		- d_map = data_map structure. also available from game->map_data.
*/
void	handler_colors_and_textures(t_game *game, t_map *d_map)
{
	int	i;

	i = 0;
	while (game->file_raw_data[i])
	{
		handle_path_textures(game, game->map_data, game->file_raw_data[i]);
		if (game->map_data->has_duplicated_texture == true)
			err_msg_free_gc_exit("HC&T : Textures are duplicated", game->garbage_coll);
		i++;
	}
	handler_parse_textures(game, game->map_data);

	i = 0;
	while (game->file_raw_data[i])
	{
		handle_colors(game, game->map_data, game->file_raw_data[i]);
		i++;
	}		
	if (d_map->ceiling_color.is_inited == false || d_map->floor_color.is_inited == false)
		err_msg_free_gc_exit("HC&T : error parser", game->garbage_coll);
}
