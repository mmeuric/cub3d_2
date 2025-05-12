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
bool handler_pre_parsing(int ac, char **av)
{
	if (!are_win_params_correct())
		return (print_error("pre parsing msg: Wrong window parameters"), exit(1), false);
	if (ac != 2)
		return (print_error("pre parsing msg: Wrong amount of arguments"), exit(1), false);
	if (!handler_pre_parser_file(av[1]))
		return (print_error("pre parsing msg: Error in file map"), exit(1), false);
	return (true);
}
