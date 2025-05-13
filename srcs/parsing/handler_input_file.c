/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:19:44 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/07 11:19:44 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will init all data realated to the map to NULL / 0
static void	init_map_data_null(t_engine *eng)
{
	eng->map_data->n_texture = NULL;
	eng->map_data->s_texture = NULL;
	eng->map_data->w_texture = NULL;
	eng->map_data->e_texture = NULL;
	eng->map_data->ceiling_rgb.is_inited = false;
	eng->map_data->floor_rgb.is_inited = false;
	eng->map_data->has_duplicated_texture = false;
}

// Will scrap from the inputed file and create a copy into char** eng->file_raw_data.
static void	extract_file_raw_data(t_engine *eng, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		quit_error(FD_ERROR, eng->garbage_coll);
	i = 0;
	while (i < eng->size_file_content)
	{
		get_next_line(fd, &line);
		ft_lstadd_back(&eng->garbage_coll, ft_lstnew(line));
		eng->file_raw_data[i++] = line;
	}
	eng->file_raw_data[i] = NULL;
	close(fd);
}


/*
	handler_input_file will: 
	- init data to null, 
	- extract raw_data:  from the inputed file to eng->(char **)file_raw_data, 
    - pre clean raw_file_data
	- will init and check textures(N,W,S,E) and colors(C,F),
	- parse the inputed file, 
	- init the (char **)map.
	- parse map.
*/
void	handler_input_file(t_engine *eng, char **av)
{
	init_map_data_null(eng);
	extract_file_raw_data(eng, av[1]);										// Will extract the data from the inputed file to eng->(char **)file_raw_data
    
	handler_pre_clean_file(eng);                                 // Pre-clean texture and color lines
	//print_file_raw_data(eng); 											//* debug 

	handler_colors_and_textures(eng, eng->map_data); 						// Will init / parse textures & colors //* 50% textures 50% colors 
	find_map(eng);															//	init_map
	if (!check_map(eng->map_data->map))										//! 100% Parsing.
		quit_error(MAP_ERROR, eng->garbage_coll);							// free error in case init_map fails
}

// TODO create a handler_map that will init_map + handler_parse_map.
// TODO bring from play() init_perso() because i think is : 50% init 50% parsing.