/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:31 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/14 15:08:52 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Function part of the pre-parsing part.
Is going to be used at the begining of the main.c to check or first check
if inputed data is correct before any malloc. 

 * are_win_params_correct() : check the windows paramenters inputed if 
 * they are part of an acceptable range size.
*/
bool	are_win_params_correct(void)
{
	if (SCREEN_W < 72 || SCREEN_W > 1080 || SCREEN_H < 48 || SCREEN_H > 1920)
		return (false);
	return (true);
}