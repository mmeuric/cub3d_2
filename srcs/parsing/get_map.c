/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:44:28 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/19 19:11:17 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	int	i;
	int	no_map_comp;

	i = 0;
	no_map_comp = 0;
	while (line[i])
	{
		if (!is_in_set(line[i], " \t10NWES"))
			return (0);
		if (is_in_set(line[i], "10NWES"))
			no_map_comp++;
		i++;
	}
	return (no_map_comp);
}
// TODO maplen
int	count_line_map(int start, t_engine *eng)
{
	int	count;

	count = 0;
	while (eng->file_raw_data[start++])
		count++;
	return (count);
}

char	**get_map(int start, t_engine *eng)
{
	char	**map;
	int		i;

	map = ft_malloc(sizeof(char *) * (count_line_map(start, eng) + 1),
			eng->garbage_coll);
	i = 0;
	while (eng->file_raw_data[start])
	{
		map[i] = eng->file_raw_data[start];
		start++;
		i++;
	}
	map[i] = NULL;
	return (map);
}
// TODO init_map.
void	find_map(t_engine *eng)
{
	int		i;

	i = 0;
	while (eng->file_raw_data[i])
	{
		if (is_map_line(eng->file_raw_data[i]))
			break ;
		i++;
	}
	eng->map_data->map = get_map(i, eng);
	fill_map(eng->map_data, eng->garbage_coll);
}
