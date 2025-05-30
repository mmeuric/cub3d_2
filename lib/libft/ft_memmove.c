/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 00:24:21 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*tsrc;
	unsigned char		*tdest;

	i = -1;
	tsrc = src;
	tdest = dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (len > 0)
		{
			tdest[len - 1] = tsrc[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
			tdest[i] = tsrc[i];
	}
	return (dest);
}
