/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:19:43 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:20:07 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

//TODO to erase
// // char	**ft_tabncpy(char **tab, int n, t_list *g_c)
// // {
// // 	int		i;
// // 	char	**new_tab;

// // 	i = 0;
// // 	new_tab = malloc_gc(sizeof(char *) * n, garb_c);
// // 	while (tab[i] && i < n)
// // 	{
// // 		new_tab[i] = tab[i];
// // 		i++;
// // 	}
// // 	return (new_tab);
// // }

//TODO to erase
// // void	del_last_empty_str(char **tab, t_list *g_c) //TODO  to erase
// // {
// // 	int	i;
// // 	int	nb_str;
// // 	int	empty_str;

// // 	nb_str = array_len(tab);
// // 	i = nb_str - 1;
// // 	empty_str = 0;
// // 	while (i)
// // 	{
// // 		if (tab[i][0])
// // 			break ;
// // 		empty_str++;
// // 		i--;
// // 	}
// // 	tab = ft_tabncpy(tab, nb_str - empty_str, garb_c);
// // }
