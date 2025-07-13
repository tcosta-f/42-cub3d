/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:44:22 by alm               #+#    #+#             */
/*   Updated: 2025/07/13 19:01:50 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Draw BG before starting raycasting on top of it
 * 
 * @param game 
 * @return * void 
 */
static void ft_draw_bg(t_game **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_draw_pixel((*game)->img, x, y, (*game)->cfg->c->color);
			ft_draw_pixel((*game)->img, x, y + WIN_H / 2,
				(*game)->cfg->f->color);
			x++;
		}
		y++;
	}
}

static void	ft_init_rc(t_game *game, t_raycast **rc)
{
	(*rc)->color = 0x0000AA;
	if (game->map->h > game->map->w)
		(*rc)->max_dof = game->map->h;
	else
		(*rc)->max_dof = game->map->w;
	(*rc)->ray_ang = game->p->ang - DR / (MAX_RAYS / FOV) * MAX_RAYS / 2;
	(*rc)->ray = 0;
	(*rc)->line_y = 0;
}

/**
 * @brief Generate a new raycast depending on the Player View
 * 
 * @param game 
 * @return int 
 */
static void	ft_raycast(t_game *game)
{
	t_raycast	*rc;

	rc = ft_calloc(1, sizeof(t_raycast));
	ft_init_rc(game, &rc);
	while (rc->ray < MAX_RAYS)
	{
		/* ft_choose_wall(cub, &rc);
		ft_choose_texture(cub, &rc);
		ft_draw_3d_walls(cub, &rc); */
		rc->ray_ang += DR / (MAX_RAYS / FOV);
		rc->ray++;
	}
	free(rc);
}

int	ft_render(t_game *game)
{
	ft_handle_keys(game);
	ft_draw_bg(&game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}