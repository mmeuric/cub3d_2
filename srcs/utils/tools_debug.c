/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:53:18 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/12 16:53:18 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//! Attention Printf 
// Function to print the content of eng->file_raw_data
void print_file_raw_data(t_engine *eng)
{
    int i = 0;

    if (!eng || !eng->file_raw_data)
    {
        printf("Error: eng or eng->file_raw_data is NULL.\n");
        return;
    }

    printf("Content of eng->file_raw_data:\n");
    while (eng->file_raw_data[i])
    {
        printf("Line %d: %s\n", i, eng->file_raw_data[i]);
        i++;
    }
}