/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:57 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:18:58 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will study the context of the current position.
static bool	is_current_pos_context_correct(char **map, int i, int j)
{
	if (i == 0 || i == array_len(map) - 1 || j == 0
		|| j == (int)ft_strlen(map[0]) - 1)
		return (false);
	if (map[i - 1][j] == '-' || map[i + 1][j] == '-'
		|| map[i][j - 1] == '-' || map[i][j + 1] == '-')
		return (false);
	return (true);
}

static bool	is_map_atribute(char c)
{
	if (c == '0' || c == '1' || c == '-' || is_cardinal_player(c))
		return (true);
	return (false);
}

//not static because is also called in init_player.c
bool	has_map_valide_atributes(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!is_map_atribute(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_map_pos_context_correct(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || is_cardinal_player(map[i][j]))
			{
				if (!is_current_pos_context_correct(map, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

// Will count amount of players in the map. 
// We can only acept only 1 player in the map. 
bool	has_map_one_player(char **map)
{
	int	nb_p;
	int	i;
	int	j;

	nb_p = 0;
	i = 1;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j])
		{
			if (is_cardinal_player(map[i][j]))
				nb_p++;
			j++;
		}
		i++;
	}
	if (nb_p == 1)
		return (true);
	else
		return (false);
}
