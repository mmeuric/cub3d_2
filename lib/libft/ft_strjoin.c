/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:35:58 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:35:59 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(*s1) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		str[j++] = s1[i++];
	i = 0;
	while (i < len2)
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*result;

	str1 = "Hello, ";
	str2 = "world!";
	result = ft_strjoin(str1, str2);
	if (result)
	{
		printf("Résultat de la concaténation : %s\n", result);
		free(result);
	}
	else
	{
		printf("Erreur d'allocation de mémoire.\n");
	}
	return (0);
}
*/