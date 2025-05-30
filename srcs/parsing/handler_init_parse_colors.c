/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_init_parse_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:16 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:16:18 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	- Will init the struct t_color.
		- init rgb.
		- parse rgb data.
		- calculate color
		- update the flag is_inited to true
*/
static bool	init_output_color(t_color *color, char **color_components)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(color_components[0]);
	green = ft_atoi(color_components[1]);
	blue = ft_atoi(color_components[2]);
	if (red < 0 || red > 255)
		return (false);
	if (green < 0 || green > 255)
		return (false);
	if (blue < 0 || blue > 255)
		return (false);
	color->output_color = (red * 65536) + (green * 256) + blue;
	color->is_inited = true;
	return (true);
}

// Will parse all given data related to rgb in (char **)c_c.
// c_c = Color Components (r=nb, g=nb, b=?)
static bool	has_valid_rgb_data(char **c_c)
{
	int	i;
	int	j;

	i = 0;
	while (c_c[i] != NULL)
	{
		j = 0;
		if (!ft_strlen(c_c[i]) || ft_strlen(c_c[i]) > 3 || c_c[i][0] == '-')
			return (false);
		while (c_c[i][j] != '\0')
		{
			if (!ft_isdigit(c_c[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

/*
	Will free a array_strings (Color Components). 
	In architectural view. These is part of a tools_free type. 
	But is only necesary for these only handler. So i will live it here.
*/
static void	free_array_strings(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/*
	After the split we need to clean the rest of 
	" " & "\t" for proper init.
	REMINDER : tmp is necesary otherwise we could have leaks.
*/
char	**trim_each_element_array(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i], " \t");
		free(tmp);
		i++;
	}
	return (tab);
}

/*
	Will : 
		- check if the color is already inited.
		- scrap de rgb data from the line.
		- parse the rgb data.
		- error handling.
		- create a new instance of t_color if necesary.
		- init the t_color with the scraped, parsed data.
		- free the temporary data stored in (char **)color_components
*/
void	handler_init_parse_colors(t_game *game, char *line, t_color *rgb)
{
	t_color	*color;
	char	**color_components;

	if (rgb && rgb->is_inited == true)
		err_msg_free_gc_exit("HIPC : parser error", game->garbage_coll);
	color_components = trim_each_element_array(ft_split(line + 2, ','));
	if (!has_valid_rgb_data(color_components))
	{
		free_array_strings(color_components);
		err_msg_free_gc_exit("HIPC : parser error", game->garbage_coll);
	}
	color = malloc(sizeof(t_color));
	if (!color)
		err_msg_free_gc_exit("HIPC : err malloc", game->garbage_coll);
	ft_lstadd_back(&game->garbage_coll, ft_lstnew(color));
	if (!init_output_color(color, color_components))
		err_msg_free_gc_exit("HIPC : parser error", game->garbage_coll);
	free_array_strings(color_components);
	*rgb = *color;
}
