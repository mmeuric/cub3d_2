/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:54 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 16:24:25 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*allocate_string(int count)
{
	char	*str;
	int		i;

	str = (char *)malloc(count + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= count)
		str[i++] = '\0';
	return (str);
}

char	*ft_itoa(int num)
{
	char		*dst;
	int			count;
	int			i;
	long int	n;

	n = num;
	count = count_size(n);
	dst = allocate_string(count);
	if (!dst)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
		i++;
	}
	while (count > i)
	{
		dst[--count] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}

/*
int	main(void)
{
	int		num;
	char	*str;

	num = 12345;
	str = ft_itoa(num);
	if (str)
	{
		printf("Num: %d -> String: %s\n", num, str);
		free(str);
	}
	else
		printf("Erreur d'allocation mémoire\n");
	num = -12345;
	str = ft_itoa(num);
	if (str)
	{
		printf("Num: %d -> String: %s\n", num, str);
		free(str);
	}
	else
		printf("Erreur d'allocation mémoire\n");
	num = 0;
	str = ft_itoa(num);
	if (str)
	{
		printf("Num: %d -> String: %s\n", num, str);
		free(str);
	}
	else
		printf("Erreur d'allocation mémoire\n");
	return (0);
}
*/
