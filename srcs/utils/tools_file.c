/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:56:50 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/08 15:56:50 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line_count_in_file(char const *file_name, t_list *garb_c) // old name get_line_count_in_file
{
	int		fd;
	int		cmp;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		quit_error(FD_ERROR, garb_c);
	cmp = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		cmp++;
	}
	free(line);
	close(fd);
	return (cmp + 1);
}