/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 00:23:46 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*tmp_src;
	unsigned char	*tmp_dest;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_src = src;
	tmp_dest = dest;
	i = 0;
	while (i < n)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
		i++;
	}
	return (dest);
}
