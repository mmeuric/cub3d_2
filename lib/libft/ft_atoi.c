/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:14 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 02:20:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

/*
int	main(void)
{
	char	*str1 = "   -42";
	char	*str2 = "   +123";
	char	*str3 = "   456";
	char	*str4 = "   -00321";

	printf("Original atoi: %d\n", atoi(str1));
	printf("ft_atoi: %d\n", ft_atoi(str1));
	printf("Original atoi: %d\n", atoi(str2));
	printf("ft_atoi: %d\n", ft_atoi(str2));
	printf("Original atoi: %d\n", atoi(str3));
	printf("ft_atoi: %d\n", ft_atoi(str3));
	printf("Original atoi: %d\n", atoi(str4));
	printf("ft_atoi: %d\n", ft_atoi(str4));

	return (0);
}*/
