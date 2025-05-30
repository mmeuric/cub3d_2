/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:21:36 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 02:00:44 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
	}
	else
	{
		ptr = malloc(count * size);
		if (!ptr)
			return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
int	main(void)
{
	int		*arr1;
	int		*arr2;
	size_t	i;

	arr1 = (int *)ft_calloc(5, sizeof(int));
	arr2 = (int *)calloc(5, sizeof(int));
	if (!arr1 || !arr2)
	{
		printf("Erreur d'allocation mémoire\n");
		return (1);
	}
	printf("Test de ft_calloc :\n");
	for (i = 0; i < 5; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	printf("Test de calloc de la libc :\n");
	for (i = 0; i < 5; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	free(arr1);
	free(arr2);
	return (0);
}
*/
