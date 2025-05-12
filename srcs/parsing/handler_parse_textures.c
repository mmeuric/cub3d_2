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
*/
//todo check
static void	open_img_xpm(char *texture_name, t_engine *engine)
{
	void	*tmp;
	int		width;
	int		height;
	char	*msg;

	tmp = mlx_xpm_file_to_image(engine->mlx_data->mlx, texture_name, &height, &width);	// Load the XPM texture file.  Store the texture's dimensions in height and width.
	if (!tmp)																			// Check if the texture failed to load.
	{
		msg = ft_strjoin(TEXTURE_FILE_ERROR, texture_name);								// Create an error message for a failed load.		//todo chng msg
		ft_lstadd_back(&engine->garbage_coll, ft_lstnew(msg));							// Add the error message to the garbage collector.
	}
	else if (height != TEX_HEIGHT || width != TEX_WIDTH)								// Check if the texture dimensions are incorrect.
	{
		msg = ft_strjoin(SIZE_TEXTURE_ERROR, texture_name);								// Create an error message for invalid dimensions.	//todo chng msg
		ft_lstadd_back(&engine->garbage_coll, ft_lstnew(msg));							// Add the error message to the garbage collector.
	}
	if (tmp)																			// If the texture was successfully loaded:
		mlx_destroy_image(engine->mlx_data->mlx, tmp);									// Destroy the loaded texture to free memory.
	if (!tmp || height != TEX_HEIGHT || width != TEX_WIDTH)								// If the texture failed to load or has invalid dimensions:
	{
		mlx_destroy_display(engine->mlx_data->mlx);										// Destroy the MLX display context.
		free(engine->mlx_data->mlx);													// Free the MLX context memory.
		quit_error(msg, engine->garbage_coll);											// Exit with the appropriate error message.
	}
}

// todo check. 
// Will check nature of the texture file extention. 
//! is_texture_extention_correct
static bool	check_texture_file_name(char *file_name)
{
	unsigned int	len;

	if (!file_name)
		return (false);
	len = (int)ft_strlen(file_name);
	if (len < 5)
		return (false);
	if (file_name[len - 1] != 'm' || file_name[len - 2] != 'p' || file_name[len - 3] != 'x' || file_name[len - 4] != '.' || file_name[len - 5] == '/')
		return (false);
	return (true);
}

// This function checks for errors in texture files and ensures they are valid before proceeding.
void	handler_parse_textures(t_engine *engine)
{
	engine->mlx_data->mlx = mlx_init();													// Initialize the MLX library and store the context in the engine.
	if (!engine->mlx_data->mlx)															// Check if MLX initialization failed.
		quit_error(MLX_ERROR, engine->garbage_coll);									// Exit with an error if MLX initialization failed.
	// Check if all texture file names are valid.
	if (!check_texture_file_name(engine->map_data->n_texture)							// Validate the north texture file name.
		|| !check_texture_file_name(engine->map_data->s_texture)						// Validate the south texture file name.
		|| !check_texture_file_name(engine->map_data->w_texture)						// Validate the west texture file name.
		|| !check_texture_file_name(engine->map_data->e_texture))						// Validate the east texture file name.
	{
		mlx_destroy_display(engine->mlx_data->mlx);										// Destroy the MLX display context if validation fails.
		free(engine->mlx_data->mlx);													// Free the MLX context memory.
		quit_error(TEXTURE_FILE_NAME_ERROR, engine->garbage_coll);						// Exit with a texture file name error. 	//todo chng msg
	}
	// Open and validate each texture file.
	open_img_xpm(engine->map_data->n_texture, engine);									// Open and validate the north texture file.
	open_img_xpm(engine->map_data->s_texture, engine);									// Open and validate the south texture file.
	open_img_xpm(engine->map_data->e_texture, engine);									// Open and validate the east texture file.
	open_img_xpm(engine->map_data->w_texture, engine);									// Open and validate the west texture file.

	mlx_destroy_display(engine->mlx_data->mlx);											// Destroy the MLX display context after processing textures.
	free(engine->mlx_data->mlx);														// Free the MLX context memory.
}
