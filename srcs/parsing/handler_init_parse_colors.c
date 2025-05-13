/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:45:40 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/19 17:04:03 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	- Will init the struct t_rgb.
		- init rgb.
		- parse rgb data.
		- calculate color
		- update the flag is_inited to true
*/
static bool	init_colors(t_rgb *color, char **color_components)
{
	color->red = ft_atoi((const char *)color_components[0]);
	color->green = ft_atoi((const char *)color_components[1]);
	color->blue = ft_atoi((const char *)color_components[2]);
	if (color->red < 0 || color->red > 255)
		return (false);
	if (color->green < 0 || color->green > 255)
		return (false);
	if (color->blue < 0 || color->blue > 255)
		return (false);
	color->color = (color->red * 65536) + (color->green * 256) + color->blue;
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
		- create a new instance of t_rgb if necesary.
		- init the t_rgb with the scraped, parsed data.
		- free the temporary data stored in (char **)color_components
*/
void handler_init_parse_colors(t_engine *eng, char *line, t_rgb *rgb)
{
	t_rgb	*color;
	char	**color_components;

	if (rgb && rgb->is_inited == true)
		quit_error("HIPC : parser error", eng->garbage_coll);					//* possible error : colors duplicated

	color_components = trim_each_element_array(ft_split(line + 2, ','));			// From the given line. We will split it in every ',' and then trim the extra "\t" or " ". 
	if (!has_valid_rgb_data(color_components))
	{
		free_array_strings(color_components);
		quit_error("HIPC : parser error", eng->garbage_coll);						//* possible error : err color data
	}

	color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!color)
		quit_error(MALLOC_ERROR, eng->garbage_coll);
	ft_lstadd_back(&eng->garbage_coll, ft_lstnew(color));

	if (!init_colors(color, color_components))
		quit_error("HIPC : parser error", eng->garbage_coll);					//* possible error : err color out band
	free_array_strings(color_components);
	*rgb = *color;
}