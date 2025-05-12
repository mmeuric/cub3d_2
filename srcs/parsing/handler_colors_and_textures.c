/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:20:12 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/16 19:26:13 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_path = texture path
static void	get_texture_path_from_line(char **t_path, t_engine *eng, char *line)
{
	*t_path = ft_strtrim(line + 2, " \t");									// Trim the input line starting from the third character, removing spaces and tabs.
	ft_lstadd_back(&eng->garbage_coll, ft_lstnew(*t_path)); 				// Add the trimmed string to the garbage collector list for memory management.
}

// This function checks if a texture has already been set. For exemples in the file we found more than 1 time the assignation of a texture to a N,W,S,E
// If the texture is already set, it marks the map data as having a duplicate texture.
static bool	is_texture_duplicated(char *cardinal_texture, t_map_data *m_data)
{
	if (cardinal_texture) 													// If the texture is already set (not NULL)...
	{
		m_data->has_duplicated_texture = true; 				// Mark the map data as having a duplicate texture.
		return (true);
	}
	return (false); 														// Always return 1 (indicating a doublon was found).
}

// This function processes a line of input to extract and store texture or color data for the map.
// It checks the prefix of the line to determine the type of data and handles it accordingly.
//! init_textures_colors
static void	init_colors_and_textures(t_engine *eng, char *line)
{
	if (!ft_strncmp((const char *) line, "NO ", 3) && !is_texture_duplicated(eng->map_data->n_texture, eng->map_data))
		get_texture_path_from_line(&eng->map_data->n_texture, eng, line);													 	// If the line starts with "NO " and the north texture is not already set, trim and store the north texture path.

	else if (!ft_strncmp((const char *) line, "SO ", 3) && !is_texture_duplicated(eng->map_data->s_texture, eng->map_data))
		get_texture_path_from_line(&eng->map_data->s_texture, eng, line);

	else if (!ft_strncmp((const char *) line, "WE ", 3) && !is_texture_duplicated(eng->map_data->w_texture, eng->map_data))
		get_texture_path_from_line(&eng->map_data->w_texture, eng, line);

	else if (!ft_strncmp((const char *) line, "EA ", 3) && !is_texture_duplicated(eng->map_data->e_texture, eng->map_data))
		get_texture_path_from_line(&eng->map_data->e_texture, eng, line);

	else if (eng->map_data->has_duplicated_texture == true)
		quit_error("Init_c&t : Textures are duplicated", eng->garbage_coll);
	else if (!ft_strncmp((const char *) line, "C ", 2))
		init_color(eng, line, &eng->map_data->ceiling_rgb);																		// If the line starts with "C ", initialize the ceiling color using the line.

	else if (!ft_strncmp((const char *) line, "F ", 2))
		init_color(eng, line, &eng->map_data->floor_rgb);																		// If the line starts with "F ", initialize the floor color using the line.

}

/*
	Will :
	- split line to init textures or colors.
	- parse textures.
	- parse colors.
	- error handling.
*/
// TODO error handling in duplicated txtures & colors.
void	handler_colors_and_textures(t_engine *eng)
{
	int	i;

	i = 0;
	while (eng->file_raw_data[i])
	{
		init_colors_and_textures(eng, eng->file_raw_data[i]);
		if (eng->map_data->has_duplicated_texture == true)
			quit_error("Init_c&t : Textures are duplicated", eng->garbage_coll);
		i++;
	}
	if (eng->map_data->ceiling_rgb.is_inited == false || eng->map_data->floor_rgb.is_inited == false)					//	TODO check what is init
		quit_error("H_C&T : err in colors", eng->garbage_coll);
	handler_parse_textures(eng);																	// 100% Parsing : Will open test textures to see if they are correct or not	
}
