/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:22:56 by mmeuric          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:55 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_file(int fd, char *buffer, char *buf_remains, char **line)
{
	int	byte_read;
	int	j;

	byte_read = read(fd, buffer, BUFFER_SIZE);
	while (byte_read > 0)
	{
		j = 0;
		buffer[byte_read] = '\0';
		while (buffer[j] != '\0' && buffer[j] != '\n')
			j++;
		if (buffer[j] == '\n')
		{
			ft_strcpy_from(buf_remains, buffer, j + 1);
			if (ft_update_line(line, j, buffer) == -1)
				return (-1);
			break ;
		}
		if (ft_update_line(line, j, buffer) == -1)
			return (-1);
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (byte_read == 0 || byte_read == -1)
		return (byte_read);
	return (1);
}

int	ft_finish_buffer(char *buffer, char *buf_remains, char **line)
{
	int	i;

	i = 0;
	if (buf_remains[0] != 0)
	{
		ft_strcpy_from(buffer, buf_remains, 0);
		while (buf_remains[i] != '\0' && buf_remains[i] != '\n')
			i++;
		if (buf_remains[i] == '\n')
		{
			ft_strcpy_from(buf_remains, buffer, i + 1);
			if (ft_update_line(line, i, buffer) == -1)
				return (-1);
			return (1);
		}
		if (ft_update_line(line, i, buffer) == -1)
			return (-1);
	}
	return (0);
}

void	ft_empty_buffer(char *buf_remains)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf_remains[i] = 0;
		i++;
	}
}

char	*ft_strdupl(const char *s1)
{
	char	*cpy;
	char	*str;
	int		str_len;
	int		i;

	str = (char *)s1;
	str_len = ft_strlength(str);
	cpy = malloc(sizeof(char) * str_len + 1);
	if (!cpy)
		return (0);
	i = 0;
	while (i < str_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	buf_remains[BUFFER_SIZE + 1] = {0};
	int			return_value;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 258 || !line)
	{
		return (-1);
	}
	*line = NULL;
	return_value = ft_finish_buffer(buffer, buf_remains, line);
	if (return_value == 1 || return_value == -1)
		return (return_value);
	return_value = ft_read_file(fd, buffer, buf_remains, line);
	if (return_value == -1)
		return (-1);
	if (return_value == 0 || *line == NULL)
	{
		if (*line == NULL)
			*line = ft_strdupl("\0");
		ft_empty_buffer(buf_remains);
		return (0);
	}
	return (return_value);
}
