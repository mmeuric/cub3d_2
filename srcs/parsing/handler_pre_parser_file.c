/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:58:53 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/01 03:38:39 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//* This function checks if the input file name is valid.
static bool	is_file_extention_correct(char *file_name)
{
	unsigned int	len;

	len = (int)ft_strlen(file_name);
	if (len < 4)										// If the file name is too short, return 0 (invalid).
		return (false);
	if (ft_strncmp(&file_name[len - 4], ".cub", 4) != 0)
		return (false);									// Check if the file name ends with ".cub".
	return (true);
}

//* This function checks if the input file exists.
static bool	does_file_exist(char *file_name)
{
	int	fd;

	fd = open((char *)file_name, O_RDONLY);				// Try to open the file in read-only mode.
	if (fd == -1)										// If the file cannot be opened, return 0 (does not exist).
		return (false);
	close(fd);
	return (true);
}

//* This function checks if the input file is not a directory.
static bool	is_file_name_a_directory(char *file_name)
{
	int	fd;
	unsigned int	len;

	len = (int)ft_strlen(file_name);
	if (file_name[len - 5] == '/')
		return (false);
	fd = open((char *)file_name, O_DIRECTORY);			// Try to open the file as a directory.
	if (fd != -1)
	{
		close(fd);
		return (false);
	}
	return (true);
}

//* This function checks if the input file is not a symbolic link.
static bool	is_simbolic_link(char *file_name)
{
	int	fd;

	fd = open((char *)file_name, O_NOFOLLOW);			// Try to open the file without following symbolic links.
	if (fd == -1)
		return (false);
	close(fd);											// Close the file descriptor if it is valid.
	return (true);
}

// Handler that will check if the 
bool	handler_pre_parser_file(char *file_name)
{
	if (!is_file_extention_correct(file_name))						// check extention of the file.
		return (false);	
	if (!does_file_exist(file_name))								// Check if the file exists.
		return (false);
	if (!is_file_name_a_directory(file_name))						// Check if the file is not a directory.
		return (false);
	if (!is_simbolic_link(file_name))								// Check if the file is not a symbolic link.
		return (false);
	return (true);													// Return 1 if all checks pass and the file is valid.
}