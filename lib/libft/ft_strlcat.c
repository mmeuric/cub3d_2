/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:36:20 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:36:27 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (len_src + size);
	while (src[i] && (len_dst + i) < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int	main(void)
{
	char	dst1[20] = "Hello, ";
	char	dst2[20] = "Hello, ";
	const char	src[] = "World!";
	size_t	n = 15;

	printf("strlcat: %lu, %s\n", strlcat(dst1, src, n), dst1);
	printf("ft_strlcat: %lu, %s\n", ft_strlcat(dst2, src, n), dst2);

	return (0);
}*/
