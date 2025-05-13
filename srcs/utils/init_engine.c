/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:32:58 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/07 14:32:58 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_engine(t_engine *eng, char **av, char **first)
{
    *first = malloc(sizeof(char));
    if (!*first)
        quit_error_no_free("init_engine : err malloc");
    eng->garbage_coll = ft_lstnew(*first);
    eng->map_data = ft_malloc(sizeof(t_map_data), eng->garbage_coll);
	if (!eng->map_data)
		quit_error_no_free("init_engine : err malloc");
    eng->mlx_data = ft_malloc(sizeof(t_win), eng->garbage_coll);
	if (!eng->mlx_data)
		quit_error_no_free("init_engine : err malloc");
    eng->cal = ft_malloc(sizeof(t_calcul_data), eng->garbage_coll);
	if (!eng->cal)
		quit_error_no_free("init_engine : err malloc");
    eng->size_file_content = get_line_count_in_file((const char *)av[1], eng->garbage_coll);
    eng->file_raw_data = ft_malloc(sizeof(char *) * (eng->size_file_content + 1), eng->garbage_coll);
	if (!eng->file_raw_data)
		quit_error_no_free("init_engine : err malloc");
}