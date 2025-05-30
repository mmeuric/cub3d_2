/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pre_clean_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:31 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:16:33 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*clean_line(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	while (line[i + j] != '\0' && !ft_isspace(line[i + j]))
		j++;
	new_line = malloc(ft_strlen(line) + 1);
	if (!new_line)
		return (NULL);
	ft_strncpy(new_line, line + i, j);
	new_line[j] = '\0';
	ft_strcat(new_line, " ");
	i += j;
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	ft_strcat(new_line, line + i);
	return (new_line);
}

// Pre-clean lines related to textures and colors, stop when the map starts
static bool	pre_clean_texture_color_lines(t_game *game)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (game->file_raw_data[i] != NULL)
	{
		if (is_t_c_need_pre_trim(game->file_raw_data[i]))
		{
			trimmed_line = ft_strtrim(game->file_raw_data[i], " \t");
			if (!trimmed_line)
				return (false);
			game->file_raw_data[i] = trimmed_line;
			ft_lstadd_back(&game->garbage_coll, ft_lstnew(trimmed_line));
		}
		i++;
	}
	return (true);
}

// Will handle : "F     20,20,20" -> "F 20,20,20". or  
// "NO		./pics/redbrick.xpm" ->  "NO ./pics/redbrick.xpm"
static bool	after_texture_color_trim(t_game *game)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (game->file_raw_data[i] != NULL)
	{
		if (is_c_need_after_trim(game->file_raw_data[i])
			|| is_t_need_after_trim(game->file_raw_data[i]))
		{
			trimmed_line = clean_line(game->file_raw_data[i]);
			if (!trimmed_line)
				return (false);
			game->file_raw_data[i] = trimmed_line;
			ft_lstadd_back(&game->garbage_coll, ft_lstnew(trimmed_line));
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
void	handler_pre_clean_file(t_game *game)
{
	if (!pre_clean_texture_color_lines(game))
		err_msg_free_gc_exit("HPCF : error parser", game->garbage_coll);
	if (!after_texture_color_trim(game))
		err_msg_free_gc_exit("HPCF : error parser", game->garbage_coll);
}
