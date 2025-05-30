/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_parse_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:59 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/20 13:17:01 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
	will open an XPM texture file, validates its dimensions,
	and handles errors if any issues arise.
	- "texture" : texture path.
	- "res" : responde from the mlx_xpm_file_to_image() call.
*/
static bool	is_t_open_size_correct(char *texture, t_screen *mlx_data)
{
	void	*res;
	int		tmp_w;
	int		tmp_h;

	res = mlx_xpm_file_to_image(mlx_data->mlx, texture, &tmp_h, &tmp_w);
	if (!res)
		return (false);
	if (res)
		mlx_destroy_image(mlx_data->mlx, res);
	if (!res || tmp_h != TEXTURE_H || tmp_w != TEXTURE_W)
		return (false);
	return (true);
}

// Will check nature of the texture file extention. 
static bool	is_texture_path_valid(char *file_name)
{
	unsigned int	len;

	if (!file_name)
		return (false);
	len = (int)ft_strlen(file_name);
	if (len < 5)
		return (false);
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'x'
		|| file_name[len - 2] != 'p' || file_name[len - 1] != 'm')
		return (false);
	if (file_name[len - 5] == '/')
		return (false);
	return (true);
}

/*
  This function checks for errors in texture files and ensures
  	they are valid before proceeding.
*/
void	handler_parse_textures(t_game *game, t_map *d_map)
{
	game->mlx_data->mlx = mlx_init();
	if (!game->mlx_data->mlx)
		err_msg_free_gc_exit("HPT : parser error", game->garbage_coll);
	if (!is_texture_path_valid(d_map->n_texture)
		|| !is_texture_path_valid(d_map->s_texture)
		|| !is_texture_path_valid(d_map->w_texture)
		|| !is_texture_path_valid(d_map->e_texture))
	{
		mlx_destroy_display(game->mlx_data->mlx);
		free(game->mlx_data->mlx);
		err_msg_free_gc_exit("HPT : parser error", game->garbage_coll);
	}
	if (!is_t_open_size_correct(d_map->n_texture, game->mlx_data)
		|| !is_t_open_size_correct(d_map->s_texture, game->mlx_data)
		|| !is_t_open_size_correct(d_map->e_texture, game->mlx_data)
		|| !is_t_open_size_correct(d_map->w_texture, game->mlx_data))
	{
		mlx_destroy_display(game->mlx_data->mlx);
		free(game->mlx_data->mlx);
		err_msg_free_gc_exit("HPT : parser error", game->garbage_coll);
	}
	mlx_destroy_display(game->mlx_data->mlx);
	free(game->mlx_data->mlx);
}
