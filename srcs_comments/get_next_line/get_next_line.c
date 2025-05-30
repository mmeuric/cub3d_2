/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:20:19 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 12:20:19 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_new_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		return (i);
	else
		return (-1);
}

int	end(int ret, char **str, char **line)
{
	int		newline;

	if (ret == -1)
		return (-1);
	newline = find_new_line(*str);
	if (newline < 0)
	{
		*line = *str;
		*str = NULL;
		return (0);
	}
	else
	{
		*line = ft_substr_gnl(*str, 0, newline, 1);
		*str = ft_substr_gnl(*str, newline + 1, ft_strlen(*str) - newline, 0);
		return (1);
	}
}

int	fill_buf(char *buf, char **line, char **str, int ret)
{
	int		newline;

	if (ret == -1)
	{
		free(*str);
		return (-1);
	}
	buf[ret] = '\0';
	newline = find_new_line(buf);
	if (newline > -1)
	{
		*str = ft_strjoin_gnl(*str, buf);
		newline = find_new_line(*str);
		*line = ft_substr_gnl(*str, 0, newline, 1);
		*str = ft_substr_gnl(*str, newline + 1, ft_strlen(*str) - newline, 0);
		return (1);
	}
	*str = ft_strjoin_gnl(*str, buf);
	return (0);
}

int	free_str(int newline, char **str)
{
	if (newline == -1)
	{
		if (*str)
			free(*str);
		return (-1);
	}
	return (newline);
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[20 + 1];
	static char		*str = NULL;
	int				newline;

	if (!line || 20 <= 0 || read(fd, buf, 0))
		return (-1);
	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	ret = read(fd, buf, 20);
	while (ret > 0)
	{
		newline = fill_buf(buf, line, &str, ret);
		if (newline == 1 || newline == -1)
			return (free_str(newline, &str));
		ret = read(fd, buf, 20);
	}
	newline = end(ret, &str, line);
	return (free_str(newline, &str));
}
