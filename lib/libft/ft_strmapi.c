/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:36:54 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:46:39 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
/*
char	to_uppercase_with_index(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char *str = "hello world";
	char *result = ft_strmapi(str, to_uppercase_with_index);

	if (result)
	{
		printf("Avant ft_strmapi: %s\n", str);
		printf("Après ft_strmapi: %s\n", result);
		free(result);
	}
	else
	{
		printf("Erreur lors de l'allocation ou de la transformation\n");
	}

	return (0);
}*/
