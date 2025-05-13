/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_file_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:00:05 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/19 19:53:07 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
	will open an XPM texture file, validates its dimensions,
	and handles errors if any issues arise.
	- "texture" : texture path.
	- "res" : responde from the mlx_xpm_file_to_image() call.
*/
static bool	is_t_open_size_correct(char *texture, t_win *mlx_data)
{
	void	*res;
	int		tmp_w;
	int		tmp_h;

	res = mlx_xpm_file_to_image(mlx_data->mlx, texture, &tmp_h, &tmp_w);	// Load the XPM texture file.  Store the texture's dimensions in tmp_h and tmp_w.
	if (!res)
		return (false);
	if (res)																// If the texture was successfully loaded:
		mlx_destroy_image(mlx_data->mlx, res);								// Destroy the loaded texture to free memory.
	if (!res || tmp_h != TEX_HEIGHT || tmp_w != TEX_WIDTH)					// If the texture failed to load or has invalid dimensions:
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
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'x' || file_name[len - 2] != 'p' || file_name[len - 1] != 'm')
		return (false);
	if (file_name[len - 5] == '/')
		return (false);
	return (true);
}

// This function checks for errors in texture files and ensures they are valid before proceeding.
void	handler_parse_textures(t_engine *engine, t_map_data *d_map)
{
	engine->mlx_data->mlx = mlx_init();															// Initialize the MLX library and store the context in the engine.
	if (!engine->mlx_data->mlx)																	// Check if MLX initialization failed.
		quit_error("HPT : parser error", engine->garbage_coll);									//* possible error : mlx error
	// Check if all texture file names are valid.
	if (!is_texture_path_valid(d_map->n_texture)												// Validate the north texture file name.
		|| !is_texture_path_valid(d_map->s_texture)												// Validate the south texture file name.
		|| !is_texture_path_valid(d_map->w_texture)												// Validate the west texture file name.
		|| !is_texture_path_valid(d_map->e_texture))											// Validate the east texture file name.
	{
		mlx_destroy_display(engine->mlx_data->mlx);												// Destroy the MLX display context if validation fails.
		free(engine->mlx_data->mlx);															// Free the MLX context memory.
		quit_error("HPT : parser error", engine->garbage_coll);									//* possible error : path data
	}
	// Open and validate each texture file.
	if (!is_t_open_size_correct(d_map->n_texture, engine->mlx_data)
	|| !is_t_open_size_correct(d_map->s_texture, engine->mlx_data)
	|| !is_t_open_size_correct(d_map->e_texture, engine->mlx_data)
	|| !is_t_open_size_correct(d_map->w_texture, engine->mlx_data))
	{
		mlx_destroy_display(engine->mlx_data->mlx);												// Destroy the MLX display context.
		free(engine->mlx_data->mlx);															// Free the MLX context memory.
		quit_error("HPT : parser error", engine->garbage_coll);									//* possible error : texture size / open error
	}

	mlx_destroy_display(engine->mlx_data->mlx);													// Destroy the MLX display context after processing textures.
	free(engine->mlx_data->mlx);																// Free the MLX context memory.
}
