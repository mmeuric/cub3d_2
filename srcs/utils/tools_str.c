/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:19:07 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:19:08 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Will check if the inputed char "c" is part of an inputed "char_set".
bool	is_in_char_set(char c, char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i] != '\0')
	{
		if (c == char_set[i])
			return (true);
		i++;
	}
	return (false);
}

// Will copy the data from dest into src.
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Will add chars from src to dest.
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// Will check if is a whitespace or not
bool	ft_isspace(char c)
{
	if (c == '\t' || c == ' '
		|| c == '\v' || c == '\f'
		|| c == '\r')
		return (true);
	else
		return (false);
}
