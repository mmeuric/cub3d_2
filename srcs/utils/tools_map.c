/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:51 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:53 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// in the map data will replace every ' ' -> with an inputed simbol.
// REMINDER : you can use print_map_data() to check if the replacement is good.
static void	map_replace_with_simbol(char *str, char *line, unsigned int width,
	char simbol)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			line[i] = str[i];
		else
			line[i] = simbol;
		i++;
	}
	while (i < width)
	{
		line[i] = simbol;
		i++;
	}
	line[i] = '\0';
}

// Will output the size of the longest line in the map.
static unsigned int	get_map_max_weight(char **map)
{
	int				i;
	unsigned int	max_len;
	unsigned int	str_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		str_len = ft_strlen(map[i]);
		if (str_len > max_len)
			max_len = str_len;
		i++;
	}
	return (max_len);
}

// Will handle the malloc +gc and the update of every ' ' with inputed simbol. 
void	map_replace_spaces_with_simbols(t_map *data, t_list *g_c)
{
	int				i;
	char			*line;
	unsigned int	max_weight;

	max_weight = get_map_max_weight(data->map);
	i = 0;
	while (data->map[i])
	{
		line = malloc_gc(sizeof(char) * (max_weight + 1), g_c);
		map_replace_with_simbol(data->map[i], line, max_weight, '-');
		data->map[i] = line;
		i++;
	}
}

/*
	REMINDER used in : 
		- has_map_one_player()
		- is_map_atribute()
		- is_map_pos_context_correct()
		- init_player()
	
	Will study if the current position is a player orientation.
*/
bool	is_cardinal_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

// Will count rows_len in file from an starting point.
int	get_map_amount_rows(int map_start_at, t_game *game)
{
	int	rows_len;

	rows_len = 0;
	while (game->file_raw_data[map_start_at++])
		rows_len++;
	return (rows_len);
}
