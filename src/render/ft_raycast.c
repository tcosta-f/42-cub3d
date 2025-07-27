/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:19:02 by alm               #+#    #+#             */
/*   Updated: 2025/07/27 10:20:43 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_digital_differential_analyser(t_game *g)
{
	int	wall;

	wall = 0;
	while (wall == 0)
	{
		if (g->rc->side_dist_x < g->rc->side_dist_y)
		{
			g->rc->side_dist_x += g->rc->delta_dist_x;
			g->rc->map_x += g->rc->step_x;
			g->rc->wall_side = 0;
		}
		else
		{
			g->rc->side_dist_y += g->rc->delta_dist_y;
			g->rc->map_y += g->rc->step_y;
			g->rc->wall_side = 1;
		}
		if (g->map->data[g->rc->map_y][g->rc->map_x] == '1')
			wall = 1;
	}
}

static void	ft_get_step(t_game *g)
{
	if (g->rc->dir_x < 0)
	{
		g->rc->step_x = -1;
		g->rc->side_dist_x = (g->p->pos_x - g->rc->map_x) * g->rc->delta_dist_x;
	}
	else
	{
		g->rc->step_x = 1;
		g->rc->side_dist_x = (g->rc->map_x + 1.0 - g->p->pos_x) * g->rc->delta_dist_x;
	}
	if (g->rc->dir_y < 0)
	{
		g->rc->step_y = -1;
		g->rc->side_dist_y = (g->p->pos_y - g->rc->map_y) * g->rc->delta_dist_y;
	}
	else
	{
		g->rc->step_y = 1;
		g->rc->side_dist_y = (g->rc->map_y + 1.0 - g->p->pos_y) * g->rc->delta_dist_y;
	}
}

static void	ft_get_delta_dist(t_game *g)
{	
	if (g->rc->dir_x == 0)
		g->rc->delta_dist_x = INT_MAX;
	else
		g->rc->delta_dist_x = fabs(1 / g->rc->dir_x);
	if (g->rc->dir_y == 0)
		g->rc->delta_dist_y = INT_MAX;
	else
		g->rc->delta_dist_y = fabs(1 / g->rc->dir_y);
}

static void	ft_init_raycasting(t_game *g, int x)
{
	g->rc->map_x = g->p->pos_x;
	g->rc->map_y = g->p->pos_y;
	g->rc->cam_x = 2 * x / (double) WIN_W - 1;
	g->rc->dir_x = (g->p->dir_x + g->p->plane_x * g->rc->cam_x);
	g->rc->dir_y = (g->p->dir_y + g->p->plane_y * g->rc->cam_x);
}

void	ft_raycast(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		ft_init_raycasting(g, x);
		ft_get_delta_dist(g);
		ft_get_step(g);
		ft_digital_differential_analyser(g);
		if (g->rc->wall_side == 0)
			g->rc->perpwalldist = (g->rc->side_dist_x - g->rc->delta_dist_x);
		else
			g->rc->perpwalldist = (g->rc->side_dist_y - g->rc->delta_dist_y);
		draw_column(g, x);
		x++;
	}
}
