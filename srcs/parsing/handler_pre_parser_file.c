/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pre_parser_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:37 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:16:39 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//* This function checks if the input file name is valid.
static bool	is_file_extention_correct(char *file_path)
{
	unsigned int	len;

	len = (int)ft_strlen(file_path);
	if (len < 4)
		return (false);
	if (ft_strncmp(&file_path[len - 4], ".cub", 4) != 0)
		return (false);
	return (true);
}

//* This function checks if the input file exists.
static bool	does_file_exist(char *file_path)
{
	int	fd;

	fd = open((char *)file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

//* This function checks if the input file is not a directory.
static bool	is_file_path_a_directory(char *file_path)
{
	int				fd;
	unsigned int	len;

	len = (int)ft_strlen(file_path);
	if (len > 4 && file_path[len - 5] == '/')
		return (false);
	fd = open((char *)file_path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (false);
	}
	return (true);
}

//* This function checks if the input file is not a symbolic link.
static bool	is_simbolic_link(char *file_path)
{
	int	fd;

	fd = open((char *)file_path, O_NOFOLLOW);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

// Handler that will check if the 
bool	handler_pre_parser_file(char *file_path)
{
	if (!file_path || !*file_path)
		return (false);
	if (!is_file_extention_correct(file_path))
		return (false);
	if (!does_file_exist(file_path))
		return (false);
	if (!is_file_path_a_directory(file_path))
		return (false);
	if (!is_simbolic_link(file_path))
		return (false);
	return (true);
}
