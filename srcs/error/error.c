/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:15:54 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:15:57 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	output_error_msg(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (err_msg)
		ft_putstr_fd(err_msg, 2);
	if (!err_msg)
		ft_putstr_fd("OEM : err", 2);
	ft_putstr_fd("\n", 2);
}

void	err_msg_free_gc_exit(char *err_msg, t_list *g_c)
{
	output_error_msg(err_msg);
	free_garbage_collector(g_c);
	exit(1);
}

void	err_msg_exit(char *err_msg)
{
	output_error_msg(err_msg);
	exit(1);
}
