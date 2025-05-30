/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:29 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:25:44 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("Pour A : %d\n", ft_isprint('A'));
		printf("Pour * : %d\n", ft_isprint('*'));
		printf("Pour k : %d\n", ft_isprint('k'));
	return (0);
}
*/
