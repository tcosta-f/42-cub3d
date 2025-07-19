/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:14:11 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 11:33:54 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_pick_texture(t_game *game, t_raycast *rc)
{
	if (rc->vert_dist < rc->hrzt_dist)
	{
		rc->ray_x = rc->vert_x;
		rc->ray_y = rc->vert_y;
		rc->dist = rc->vert_dist;
		if (rc->ray_ang > PI / 2 && rc->ray_ang < 3 * PI / 2)
			rc->texture = game->cfg->ea_img;
		else
			rc->texture = game->cfg->we_img;
	}
	else
	{
		rc->ray_x = rc->hrzt_x;
		rc->ray_y = rc->hrzt_y;
		rc->dist = rc->hrzt_dist;
		if (rc->ray_ang > PI)
			rc->texture = game->cfg->so_img;
		else
			rc->texture = game->cfg->no_img;
	}
}