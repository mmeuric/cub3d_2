/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:27:34 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/13 14:27:34 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if ((char)set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//maybe unused
char	*ft_str_dup_cub(char *str, t_list *garb_c)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_malloc(sizeof(char) * ft_strlen(str) + 1, garb_c);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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

bool	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' 
		|| c == '\v' || c == '\f' 
		|| c == '\r')
		return (true);
	else
		return (false);
}