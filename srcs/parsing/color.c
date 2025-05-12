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




static void	set_color(t_rgb *color, char **split, t_engine *eng)
{
	color->red = ft_atoi((const char *)split[0]);
	color->green = ft_atoi((const char *)split[1]);
	color->blue = ft_atoi((const char *)split[2]);
	clear_str_tab(split);
	if (color->red < 0 || color->red > 255)
		quit_error(COLOR_ERROR, eng->garbage_coll);
	if (color->green < 0 || color->green > 255)
		quit_error(COLOR_ERROR, eng->garbage_coll);
	if (color->blue < 0 || color->blue > 255)
		quit_error(COLOR_ERROR, eng->garbage_coll);
	color->color = (color->red * 65536) + (color->green * 256) + color->blue;
	color->is_inited = true;
}
static void	test_color(t_engine *eng, char **split)
{
	if (!composed_with(split[0], "0123456789")
		|| !ft_strlen(split[0])
		|| !composed_with(split[1], "0123456789") 
		|| !ft_strlen(split[1])
		|| !composed_with(split[2], "0123456789") 
		|| !ft_strlen(split[2]))
	{
		clear_str_tab(split);
		quit_error(COLOR_ERROR, eng->garbage_coll);
	}
}
static void	check_trim_color(char *str, t_engine *eng)
{
	char	*tmp;

	tmp = ft_strtrim(str + 1, " \t");
	if (!ft_isdigit(tmp[0]) || !ft_isdigit(tmp[ft_strlen(tmp) - 1]))
	{
		free(tmp);
		quit_error(COLOR_ERROR, eng->garbage_coll);
	}
	free(tmp);
}

// handler_get_parse_color
//TODO refacto
// TODO get_color need to become a main handler in color management calls.
// TODO needs to be included in init_color functions. And be called from Parents handlers.
static t_rgb	get_color(char *line, t_engine *eng)
{
	t_rgb	*colors;
	char	**split;
	int		nb_str;

	check_trim_color(line, eng);
	split = ft_split(line + 2, ',');
	nb_str = count_str(split);
	if (nb_str > 3 || nb_str < 3)
	{
		clear_str_tab(split);
		quit_error(COLOR_ERROR, eng->garbage_coll);
	}
	trim_split(split);
	test_color(eng, split);
	colors = (t_rgb *)malloc(sizeof(t_rgb));
	ft_lstadd_back(&eng->garbage_coll, ft_lstnew(colors));
	if (!colors)
		quit_error(MALLOC_ERROR, eng->garbage_coll);
	set_color(colors, split, eng);
	return (*colors);
}
//TODO GLOBAL : arg name "split" is not clear. To change.
//TODO : init_color is almost no necesary we need to find the way to update get_color to be a handler and manage everything.


// TODO init_color : To be erased
void	init_color(t_engine *eng, char *line, t_rgb *rgb)
{
	if (rgb && rgb->is_inited == true)									// In the income data, we check if the color is already inited before if true then error in the input file data.
		quit_error("IN : colors duplicated", eng->garbage_coll);
	*rgb = get_color(line, eng);
}