/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:09:30 by alm               #+#    #+#             */
/*   Updated: 2025/07/27 10:53:01 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_press(int key_code, t_game *g)
{
	if (key_code == XK_ESCAPE)
		g->k->esc = true;
	else if (key_code == XK_CW || key_code == XK_SW)
		g->k->w = true;
	else if (key_code == XK_CA || key_code == XK_SA)
		g->k->a = true;
	else if (key_code == XK_CS || key_code == XK_SS)
		g->k->s = true;
	else if (key_code == XK_CD || key_code == XK_SD)
		g->k->d = true;
	else if (key_code == XK_LEFT)
		g->k->left = true;
	else if (key_code == XK_UP)
		g->k->up = true;
	else if (key_code == XK_RIGHT)
		g->k->right = true;
	else if (key_code == XK_DOWN)
		g->k->down = true;
	return (0);
}
