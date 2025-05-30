/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:19:02 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:19:03 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will add to dest the chars in src. 
// REMINDER : dest must have enought space to acept the amount of char in src.
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	ds_count;

	if (!src || !dest)
		return (dest);
	ds_count = 0;
	while (dest[ds_count] != '\0')
		ds_count++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[ds_count + i] = src[i];
		i++;
	}
	dest[ds_count + i] = '\0';
	return (dest);
}

/*
	REMINDER : related to handler_pre_clean_file();
	will : 
		- jump whitespaces, (" " & "\t")
		- if the first non whitespace is a texture or color and i > 0 
		(meaning there are whitespaces in the line) = true
		
*/
bool	is_t_c_need_pre_trim(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if (i > 0 && (line[i] == 'F' || line[i] == 'C'
			|| (line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A')))
		return (true);
	else
		return (false);
}

// REMINDER : related to handler_pre_clean_file();
bool	is_c_need_after_trim(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'F' || line[i] == 'C')
	{
		i++;
		while (line[i] != '\0' && ft_isspace(line[i]))
			i++;
		if (i > 1 && line[i] != '\0')
			return (true);
	}
	return (false);
}

// REMINDER : related to handler_pre_clean_file();
bool	is_t_need_after_trim(char *line)
{
	int	i;
	int	is_whitespace;
	int	has_tab;

	i = 0;
	is_whitespace = 0;
	has_tab = 0;
	if ((line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A'))
	{
		i += 2;
		while (line[i] != '\0' && ft_isspace(line[i]))
		{
			if (line[i] == '\t')
				has_tab++;
			is_whitespace++;
			i++;
		}
		if ((has_tab >= 1 || is_whitespace > 1) && line[i] != '\0')
			return (true);
	}
	return (false);
}
