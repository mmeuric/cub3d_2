/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:27:34 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:20:07 by urlooved &&      ###   ########.fr       */
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

//maybe unused	// TODO erase
// char	*ft_str_dup_cub(char *str, t_list *g_c)
// {
// 	char	*new;
// 	int		i;

// 	i = 0;
// 	new = malloc_gc(sizeof(char) * ft_strlen(str) + 1, garb_c);
// 	while (str[i])
// 	{
// 		new[i] = str[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }
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