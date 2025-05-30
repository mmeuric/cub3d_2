/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:37:59 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 01:52:50 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[h] == '\0')
		return ((char *)haystack);
	while (haystack[h])
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)haystack + h);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (0);
}

/*
char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	if (!hay || !need)
		return (NULL);
	if (!need || !need[0])
		return ((char *)hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] && need[j] && i + j < len && hay[i + j] == need[j])
			j++;
		if (!need[j])
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
*/
/*
int	main(void)
{
	char	*haystack = "Hello, this is a test string!";
	char	*needle = "test";
	size_t	len = 25;

	printf("Original strnstr: %s\n", strnstr(haystack, needle, len));
	printf("ft_strnstr: %s\n", ft_strnstr(haystack, needle, len));

	return (0);
}*/
