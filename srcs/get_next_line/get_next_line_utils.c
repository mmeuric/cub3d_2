/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:47 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/20 13:49:08 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_strncat(char *dest, char *src, int n)
{
	int	size_dest;
	int	i;

	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
}

void	ft_strcpy_from(char *dest, char *src, int j)
{
	int	size_dest;
	int	i;

	size_dest = 0;
	while (src && src[size_dest + j] != '\0')
		size_dest++;
	i = 0;
	while (i < size_dest)
	{
		dest[i] = src[j + i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_update_line(char **line, int j, char *buffer)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlength(*line) + j + 1));
	if (!tmp)
		return (-1);
	ft_strcpy_from(tmp, *line, 0);
	ft_strncat(tmp, buffer, j);
	free(*line);
	*line = malloc(sizeof(char) * (ft_strlength(tmp) + 1));
	if (!*line)
	{
		free(tmp);
		return (-1);
	}
	ft_strcpy_from(*line, tmp, 0);
	free(tmp);
	return (1);
}
