/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:31 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/05 13:59:31 by urlooved &&      ###   ########.fr       */
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
	if (SCREEN_WIDTH < 72 || SCREEN_WIDTH > 1080 || SCREEN_HEIGHT < 48 || SCREEN_HEIGHT > 1920)
	{
		print_error("pre_parsing msg : err screen params");
		exit(1);
		return (false);
	}
	return (true);
}