/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 06:29:58 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/19 19:12:18 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_number_player(char **map) //?
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
			if (is_orientation_char(map[i][j]))
				nb_p++;
			j++;
		}
		i++;
	}
	return (nb_p == 1);
}
static bool	check_char_around(char **map, int i, int j)	//?
{
	if (i == 0 || i == count_str(map) - 1 || j == 0 || j == (int)ft_strlen(map[0]) - 1)
		return (false);
	if (map[i - 1][j] == '-' || map[i + 1][j] == '-' || map[i][j - 1] == '-' || map[i][j + 1] == '-')
		return (false);
	return (true);
}

static bool	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '-' || is_orientation_char(c))	//?
		return (true);
	return (false);
}
//not static because is also called in init_perso.c
bool	is_orientation_char(char c)	//?
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map[i])
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_map_char(map[i][j]))
				return (0);
			if (map[i][j] == '0' || is_orientation_char(map[i][j]))
			{
				if (!check_char_around(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (check_number_player((char **)map));
}
