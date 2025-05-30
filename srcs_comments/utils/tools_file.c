/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:56:50 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:23:12 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_file_len(char *input_file, t_list *g_c)
{
	int		fd;
	int		cmp;
	char	*line;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		err_msg_free_gc_exit("GFL : err opening fd", g_c);
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

