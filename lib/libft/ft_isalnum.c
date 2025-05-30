/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:21:45 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:23:34 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("Pour A : %d\n", ft_isalpha('A'));
		printf("Pour * : %d\n", ft_isalpha('*'));
		printf("Pour k : %d\n", ft_isalpha('k'));
	return (0);
}
*/