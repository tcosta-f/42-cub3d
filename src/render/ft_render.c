/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:44:22 by alm               #+#    #+#             */
/*   Updated: 2025/07/26 11:42:39 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Draw BG before starting raycasting on top of it
 * 
 * @param game 
 * @return * void 
 */
static void ft_draw_bg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_draw_pixel((game)->img, x, y, (game)->cfg->c->color);
			ft_draw_pixel((game)->img, x, y + WIN_H / 2,
				(game)->cfg->f->color);
			x++;
		}
		y++;
	}
}

void	digital_differential_analyser(t_game *g)
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

void	get_step(t_game *g)
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

void	get_delta_dist(t_game *game)
{	
	if (game->rc->dir_x == 0)
		game->rc->delta_dist_x = INT_MAX;
	else
		game->rc->delta_dist_x = fabs(1 / game->rc->dir_x);
	if (game->rc->dir_y == 0)
		game->rc->delta_dist_y = INT_MAX;
	else
		game->rc->delta_dist_y = fabs(1 / game->rc->dir_y);
}

void	init_raycasting(t_game *game, int x)
{
	game->rc->map_x = game->p->pos_x;
	game->rc->map_y = game->p->pos_y;
	game->rc->cam_x = 2 * x / (double) WIN_W - 1;
	game->rc->dir_x = game->p->dir_x + game->p->plane_x * game->rc->cam_x;
	game->rc->dir_y = game->p->dir_y + game->p->plane_y * game->rc->cam_x;
}

static void	ft_raycast(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		init_raycasting(g, x);
		get_delta_dist(g);
		get_step(g);
		digital_differential_analyser(g);
		if (g->rc->wall_side == 0)
			g->rc->perpwalldist = ((g->rc->side_dist_x - g->rc->delta_dist_x));
		else
			g->rc->perpwalldist = ((g->rc->side_dist_y - g->rc->delta_dist_y));
		draw_column(g, x);
		x++;
	}
}

int	ft_render(t_game *game)
{
	ft_handle_keys(game);
	ft_draw_bg(game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}
