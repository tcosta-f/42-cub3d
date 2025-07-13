/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:45:31 by alm               #+#    #+#             */
/*   Updated: 2025/07/13 12:46:21 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_down(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		game->k->esc = true;
	else if (key_code == XK_CW || key_code == XK_SW)
		game->k->w = true;
	else if (key_code == XK_CA || key_code == XK_SA)
		game->k->a = true;
	else if (key_code == XK_CS || key_code == XK_SS)
		game->k->s = true;
	else if (key_code == XK_CD || key_code == XK_SD)
		game->k->d = true;
	else if (key_code == XK_LEFT)
		game->k->left = true;
	else if (key_code == XK_UP)
		game->k->up = true;
	else if (key_code == XK_RIGHT)
		game->k->right = true;
	else if (key_code == XK_DOWN)
		game->k->down = true;
	return (0);
}

int	ft_key_up(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		game->k->esc = false;
	else if (key_code == XK_CW || key_code == XK_SW)
		game->k->w = false;
	else if (key_code == XK_CA || key_code == XK_SA)
		game->k->a = false;
	else if (key_code == XK_CS || key_code == XK_SS)
		game->k->s = false;
	else if (key_code == XK_CD || key_code == XK_SD)
		game->k->d = false;
	else if (key_code == XK_LEFT)
		game->k->left = false;
	else if (key_code == XK_UP)
		game->k->up = false;
	else if (key_code == XK_RIGHT)
		game->k->right = false;
	else if (key_code == XK_DOWN)
		game->k->down = false;
	return (0);
}