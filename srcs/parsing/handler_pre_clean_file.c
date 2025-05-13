/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:53:18 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/12 16:53:18 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char *clean_line(char *line)
{
    int i;
	int j;
    char *new_line;

	i = 0;
	j = 0;
	while (line[i] != '\0' && ft_isspace(line[i]))				// Skip leading whitespace
        i++;
    while (line[i + j] != '\0' && !ft_isspace(line[i + j]))		// Find the end of the identifier (e.g., 'C', 'F', etc.)
        j++;
    new_line = malloc(ft_strlen(line) + 1);						// Allocate memory for the new line
    if (!new_line)
        return NULL;
    ft_strncpy(new_line, line + i, j);							// Copy the identifier
    new_line[j] = '\0';
    ft_strcat(new_line, " ");									// Add a single space after the identifier
    i += j;														// Skip whitespace between the identifier and the data
    while (line[i] != '\0' && ft_isspace(line[i]))
        i++;
    ft_strcat(new_line, line + i);								// Append the rest of the data
    return new_line;
}

// Pre-clean lines related to textures and colors, stop when the map starts
static bool pre_clean_texture_color_lines(t_engine *eng)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (eng->file_raw_data[i] != NULL)
	{
		if (is_t_c_need_pre_trim(eng->file_raw_data[i]))
		{
			trimmed_line = ft_strtrim(eng->file_raw_data[i], " \t");
			if (!trimmed_line)
				return (false);
			eng->file_raw_data[i] = trimmed_line;
			ft_lstadd_back(&eng->garbage_coll, ft_lstnew(trimmed_line));
		}
		i++;
	}
	return (true);
}

// Will handle : "F     20,20,20" -> "F 20,20,20".
static bool after_color_trim(t_engine *eng)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (eng->file_raw_data[i] != NULL)
    {
        if (is_c_need_after_trim(eng->file_raw_data[i]))
		{
			trimmed_line = clean_line(eng->file_raw_data[i]);
			if (!trimmed_line)
				return (false);
			eng->file_raw_data[i] = trimmed_line;
			ft_lstadd_back(&eng->garbage_coll, ft_lstnew(trimmed_line));
		}
        i++;
	}
	return (true);
}

/*
	Will :
		- clean lines if they have whitespaces before data
			- ex:  "       Texture/color data"
			- output : "Texture/color data"
		- if in colors we have many whitespaces between flag - data
			- ex : "Texture/color            data"
			- output : "Texture/color data"
*/
void	handler_pre_clean_file(t_engine *eng)
{
	if (!pre_clean_texture_color_lines(eng))
		quit_error("HPCF : error parser", eng->garbage_coll);		// Error related trim  "       Texture/color data".

	//print_file_raw_data(eng);
	//printf("-------\n");
	if (!after_color_trim(eng))
		quit_error("HPCF : error parser", eng->garbage_coll);		// error related trim = "Texture/color            data".

	//print_file_raw_data(eng);
	//printf("-------\n");
}