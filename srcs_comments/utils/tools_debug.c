/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:53:18 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 14:04:56 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//! Attention Printf 
// Function to print the content of game->file_raw_data
void print_file_raw_data(t_game *game)
{
    int i = 0;

    if (!game || !game->file_raw_data)
    {
        printf("Error: eng or game->file_raw_data is NULL.\n");
        return;
    }

    printf("Content of game->file_raw_data:\n");
    while (game->file_raw_data[i])
    {
        printf("Line %d: %s\n", i, game->file_raw_data[i]);
        i++;
    }
}

#include "cub3d.h"

//! Attention Printf 
// Function to print the content of game->map_data->map
void print_map_data(t_game *game)
{
    int i = 0;

    if (!game || !game->map_data || !game->map_data->map)
    {
        printf("Error: game, game->map_data, or game->map_data->map is NULL.\n");
        return;
    }

    printf("Content of game->map_data->map:\n");
    while (game->map_data->map[i])
    {
        printf("Line %d: %s\n", i, game->map_data->map[i]);
        i++;
    }
}