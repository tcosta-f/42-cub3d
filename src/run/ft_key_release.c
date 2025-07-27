/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:09:59 by alm               #+#    #+#             */
/*   Updated: 2025/07/27 10:53:17 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_release(int key_code, t_game *g)
{
	if (key_code == XK_ESCAPE)
		g->k->esc = false;
	else if (key_code == XK_CW || key_code == XK_SW)
		g->k->w = false;
	else if (key_code == XK_CA || key_code == XK_SA)
		g->k->a = false;
	else if (key_code == XK_CS || key_code == XK_SS)
		g->k->s = false;
	else if (key_code == XK_CD || key_code == XK_SD)
		g->k->d = false;
	else if (key_code == XK_LEFT)
		g->k->left = false;
	else if (key_code == XK_UP)
		g->k->up = false;
	else if (key_code == XK_RIGHT)
		g->k->right = false;
	else if (key_code == XK_DOWN)
		g->k->down = false;
	return (0);
}
