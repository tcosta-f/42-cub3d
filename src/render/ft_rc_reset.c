/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:20:13 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 11:36:55 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_rc_reset(t_game *game, t_raycast *rc)
{
	rc->vert_dist = 1000000000;
	rc->hrzt_dist = 1000000000;
	rc->dist = 1000000000;
	if (rc->ray_ang < 0)
		rc->ray_ang += 2 * PI;
	if (rc->ray_ang > 2 * PI)
		rc->ray_ang -= 2 * PI;
	rc->dof = 0;
	rc->hrzt_x = game->p->x;
	rc->hrzt_y = game->p->y;
	rc->hrzt_tan = -1 / tan (rc->ray_ang);
}
