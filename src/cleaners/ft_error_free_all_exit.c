/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_all_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:07:11 by alm               #+#    #+#             */
/*   Updated: 2025/07/13 12:19:20 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Free game and optionally displays error and exit with errno code.
 * 
 * @param game 		game to be freed
 * @param msg 		error message (pass NULL if don't want to display any error)
 * @param mode 		set to true if you want program to exit
 * @param code 		errno: exit code
 */
void	ft_error_free_all_exit(t_game *game, char *msg, bool mode, int code)
{
	if (msg)
		ft_display_error(msg);
	ft_free_game(&game);
	if (mode)
		exit(code);
}

int		ft_handle_exit(t_game *game)
{
	ft_error_free_all_exit(game, CY"Thanks for playing! Bye!"RST, true, 0);
	return (0);
}
