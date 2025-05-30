/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 00:23:18 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tsrc;
	unsigned char	*tdest;

	i = 0;
	tsrc = (unsigned char *)src;
	tdest = (unsigned char *)dest;
	while (i < n)
	{
		tdest[i] = tsrc[i];
		if (tsrc[i] == (unsigned char )c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
