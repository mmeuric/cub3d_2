/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:21:24 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:41:34 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *k, size_t n)
{
	ft_memset(k, 0, n);
}
/*
int main(void)
{
    char buffer1[100];
    char buffer2[100];

    strcpy(buffer1, "Salut les gars");
    strcpy(buffer2, "Salut les gars");

    printf("Avant ft_bzero: '%s'\n", buffer1);
    ft_bzero(buffer1, 16);
    printf("Après ft_bzero: '%s'\n", buffer1);

    printf("\nAvant bzero: '%s'\n", buffer2);
    bzero(buffer2, 16);
    printf("Après bzero: '%s'\n", buffer2);

    return 0;
}*/
