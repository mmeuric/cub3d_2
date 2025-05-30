/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pre_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:33:17 by urlooved &&       #+#    #+#             */
/*   Updated: 2025/05/05 13:33:17 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Will check:
	- Windows settings are aceptable.
	- Amount of arguments : 
		- Only case accepted 2 arguments.
	- Test / check availability of inpited file (av[1]).
*/
void handler_pre_parsing(int ac, char **av)
{
	if (!are_win_params_correct())
		err_msg_exit("PPP: Wrong window parameters");
	if (ac != 2)
		err_msg_exit("PPP: Wrong amount of arguments");
	if (!handler_pre_parser_file(av[1]))
		err_msg_exit("PPP: Err inputed file");
}