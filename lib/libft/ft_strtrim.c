/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:38:29 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 15:37:18 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
/*
int	main(void)
{
	char	*result;

	// Test 1 : chaîne avec des caractères à trim aux deux extrémités
	result = ft_strtrim("   Bonjour, monde!   ", " ");
	printf("Test 1 : '%s'\n", result);
	free(result);
	// Test 2 : trim des caractères en début et fin
	result = ft_strtrim("xxHello, World!xx", "x");
	printf("Test 2 : '%s'\n", result);
	free(result);
	// Test 3 : trim avec tous les caractères identiques au set
	result = ft_strtrim("aaaaaa", "a");
	printf("Test 3 : '%s'\n", result);
	free(result);
	// Test 4 : chaîne sans caractères du set
	result = ft_strtrim("Hello, World!", "x");
	printf("Test 4 : '%s'\n", result);
	free(result);
	// Test 5 : chaîne vide
	result = ft_strtrim("", " ");
	printf("Test 5 : '%s'\n", result);
	free(result);
	// Test 6 : trim avec set vide (ne change rien)
	result = ft_strtrim("Bonjour", "");
	printf("Test 6 : '%s'\n", result);
	free(result);
	// Test 7 : chaîne NULL
	result = ft_strtrim(NULL, " ");
	printf("Test 7 : %s\n", result ? result : "(NULL)");
	free(result);
	// Test 8 : set NULL
	result = ft_strtrim("Hello", NULL);
	printf("Test 8 : %s\n", result ? result : "(NULL)");
	free(result);
	return (0);
}
*/
