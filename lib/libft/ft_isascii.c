/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:22:35 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:24:50 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("Pour A : %d\n", ft_isascii('A'));
		printf("Pour * : %d\n", ft_isascii('*'));
		printf("Pour k : %d\n", ft_isascii('k'));
	return (0);
}*/
