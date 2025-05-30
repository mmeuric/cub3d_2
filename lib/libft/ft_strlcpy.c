/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:36:36 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 16:07:25 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	dest[20];
	size_t	result;

	result = ft_strlcpy(dest, "Bonjour tout le monde!", sizeof(dest));
	printf("Test 1:\nResultat: %zu\nDest: %s\n", result, dest);
	result = ft_strlcpy(dest, "Petit test", 5);
	printf("Test 2:\nResultat: %zu\nDest: %s\n", result, dest);
	result = ft_strlcpy(dest, "Autre test de longueur", 0);
	printf("Test 3:\nResultat: %zu\nDest: %s\n", result, dest);
	result = ft_strlcpy(dest, "", sizeof(dest));
	printf("Test 4:\nResultat: %zu\nDest: %s\n", result, dest);
	return (0);
}
*/
