/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:25:25 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("Pour A : %d\n", ft_isdigit('A'));
		printf("Pour 0 : %d\n", ft_isdigit('0'));
		printf("Pour 5 : %d\n", ft_isdigit('5'));
	return (0);
}
*/
