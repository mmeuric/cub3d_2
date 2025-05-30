/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:37:03 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:37:04 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && i < n - 1 && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*
int	main(void)
{
	char	*str1 = "Hello";
	char	*str2 = "Hello";
	char	*str3 = "HelLo";
	char	*str4 = "World";

	printf("Original strncmp: %d\n", strncmp(str1, str2, 5));
	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 5));
	printf("Original strncmp: %d\n", strncmp(str1, str3, 4));
	printf("ft_strncmp: %d\n", ft_strncmp(str1, str3, 4));
	printf("Original strncmp: %d\n", strncmp(str1, str4, 5));
	printf("ft_strncmp: %d\n", ft_strncmp(str1, str4, 5));

	return (0);
}*/
