/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:23:30 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 11:32:21 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_h_rays(t_game *game, t_raycast *rc)
{
	if (rc->ray_ang < PI)
	{
		rc->ray_y = (int) game->p->y - PREC_DN;
		rc->ray_x = (game->p->y - rc->ray_y) * rc->hrzt_tan + game->p->x;
		rc->ray_y_offset = -PREC_UP;
		rc->ray_x_offset = -rc->ray_y_offset * rc->hrzt_tan;
	}
	if (rc->ray_ang > PI)
	{
		rc->ray_y = (int) game->p->y + PREC_UP;
		rc->ray_x = (game->p->y - rc->ray_y) * rc->hrzt_tan + game->p->x;
		rc->ray_y_offset = PREC_UP;
		rc->ray_x_offset = -rc->ray_y_offset * rc->hrzt_tan;
	}
	if (rc->ray_ang == 0 || rc->ray_ang == PI)
	{
		rc->ray_x = game->p->x;
		rc->ray_y = game->p->y;
		rc->dof = rc->max_dof;
	}
}

static void	ft_hit_h_wall(t_game *game, t_raycast *rc, int map_x, int map_y)
{
	if (map_x >= 0 && map_y >= 0 && map_x < game->map->w &&
		map_y < game->map->h && game->map->data[map_y][map_x] == '1')
	{
		rc->hrzt_x = rc->ray_x;
		rc->hrzt_y = rc->ray_y;
		rc->hrzt_dist = ft_dist(game->p->x, game->p->y, rc->hrzt_x, rc->hrzt_y);
		rc->dof = rc->max_dof;
	}
	else
	{
		rc->ray_x += rc->ray_x_offset;
		rc->ray_y += rc->ray_y_offset;
		rc->dof++;
	}
}

static void	ft_v_rays(t_game *game, t_raycast *rc)
{
	rc->dof = 0;
	rc->vert_x = game->p->x;
	rc->vert_y = game->p->y;
	rc->vert_tan = -tan(rc->ray_ang);
	if (rc->ray_ang < PI / 2 || rc->ray_ang > 3 * PI / 2)
	{
		rc->ray_x = (int) game->p->x - PREC_DN;
		rc->ray_y = (game->p->x - rc->ray_x) * rc->vert_tan + game->p->y;
		rc->ray_x_offset = -PREC_UP;
		rc->ray_y_offset = -rc->ray_x_offset * rc->vert_tan;
	}
	if (rc->ray_ang > PI / 2 && rc->ray_ang < 3 * PI / 2)
	{
		rc->ray_x = (int) game->p->x + PREC_UP;
		rc->ray_y = (game->p->x - rc->ray_x) * rc->vert_tan + game->p->y;
		rc->ray_x_offset = PREC_UP;
		rc->ray_y_offset = -rc->ray_x_offset * rc->vert_tan;
	}
	if (rc->ray_ang == PI / 2 || rc->ray_ang == 3 * PI / 2)
	{
		rc->ray_x = game->p->x;
		rc->ray_y = game->p->y;
		rc->dof = rc->max_dof;
	}
}

static void	ft_hit_v_wall(t_game *game, t_raycast *rc, int map_x, int map_y)
{
	if (map_x >= 0 && map_y >= 0 && map_x < game->map->w &&
		map_y < game->map->h && game->map->data[map_y][map_x] == '1')
	{
		rc->vert_x = rc->ray_x;
		rc->vert_y = rc->ray_y;
		rc->vert_dist = ft_dist(game->p->x, game->p->y, rc->vert_x, rc->vert_y);
		rc->dof = rc->max_dof;
	}
	else
	{
		rc->ray_x += rc->ray_x_offset;
		rc->ray_y += rc->ray_y_offset;
		rc->dof++;
	}
}

void	ft_pick_wall(t_game *game, t_raycast *rc)
{
	int	map_x;
	int	map_y;

	ft_rc_reset(game, rc);
	ft_h_rays(game, rc);
	while (rc->dof < rc->max_dof)
	{
		map_x = (int)(rc->ray_x);
		map_y = (int)(rc->ray_y);
		ft_hit_h_wall(game, rc, map_x, map_y);
	}
	ft_v_rays(game, rc);
	while (rc->dof < rc->max_dof)
	{
		map_x = (int)(rc->ray_x);
		map_y = (int)(rc->ray_y);
		ft_hit_v_wall(game, rc, map_x, map_y);
	}
}
