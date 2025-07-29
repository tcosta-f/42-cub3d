/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:44:22 by alm               #+#    #+#             */
/*   Updated: 2025/07/27 11:03:49 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Draw BG before starting raycasting on top of it
 * 
 * @param game 
 * @return * void 
 */
static void	ft_draw_bg(t_game *game)
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

int	ft_render(t_game *game)
{
	ft_handle_keys(game);
	ft_draw_bg(game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	return (0);
}
