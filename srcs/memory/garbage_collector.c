/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:03 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:16:06 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_mlx(t_screen *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->data.img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_sreen);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
}

void	*malloc_gc(size_t size, t_list *g_c)
{
	void	*content;

	content = malloc(size);
	if (!content)
		err_msg_free_gc_exit("MGC : err malloc", g_c);
	ft_lstadd_back(&g_c, ft_lstnew(content));
	return (content);
}

void	free_garbage_collector(t_list *g_c)
{
	ft_lstclear(&g_c, &free);
}
