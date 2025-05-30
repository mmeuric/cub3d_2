/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:38:19 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:38:20 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "Hello, world!";
	char	c;
	char	*result1;
	char	*result2;

	c = 'o';
	result1 = strrchr(s, c);
	result2 = ft_strrchr(s, c);
	printf("Result of strrchr: %s\n", result1);
	printf("Result of ft_strrchr: %s\n", result2);
	return (0);
}
*/
