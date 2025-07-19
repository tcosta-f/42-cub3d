/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:43:23 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 18:10:19 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_draw_rect(t_game *game, int x_start, int y_start, int x_end,
	int y_end, int color)
{
	int	x;
	int	y;

	y = y_start;
	while (y <= y_end)
	{
		x = x_start;
		while (x <= x_end)
		{
			ft_draw_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}

static int	ft_get_pixel_color(void *texture, int x, int y, int tile_size)
{
	int		color;
	t_img	img;
	void	*temp;

	temp = mlx_get_data_addr(texture, &img.bpp, &img.line_len, &img.endian);
	temp = temp + (x + y * 64) * 4;
	color = *(unsigned char *)(temp + 2) << 16;
	color |= *(unsigned char *)(temp + 1) << 8;
	color |= *(unsigned char *)temp;
	return (color);
} 

static void	ft_set_rc_texture(t_game *game, t_raycast *rc)
{
	int	precision;

	if (rc->vert_dist < rc->hrzt_dist)
	{
		precision = (int)(rc->vert_y * 100) % 100;
		rc->texture_x = game->cfg->w_img * precision / 100;
		if (rc->ray_ang < PI / 2 || rc->ray_ang > 3 * PI / 2)
			rc->texture_x = game->cfg->w_img - rc->texture_x - 1;
	}
	else
	{
		precision = (int)(rc->hrzt_x * 100) % 100;
		rc->texture_x = game->cfg->w_img * precision / 100;
		if (rc->ray_ang > PI)
			rc->texture_x = game->cfg->w_img - rc->texture_x - 1;
	}
}

static void	ft_3d_cast(t_game *game, t_raycast *rc)
{
	rc->cast_ang = game->p->ang - rc->ray_ang;
	if (rc->cast_ang < 0)
		rc->cast_ang += 2 * PI;
	if (rc->cast_ang > 2 * PI)
		rc->cast_ang -= 2 * PI;
	rc->dist = rc->dist * cos(rc->cast_ang);
	rc->vert_line = (WIN_H * WIN_W / WALL_H) / rc->dist;
	rc->line_off = WIN_H / 2 - rc->vert_line / 2;
	rc->line_y = 0;
	rc->ray_hrzt_dist = WIN_W / MAX_RAYS;
	ft_set_rc_texture(game, rc);
}

void	ft_draw_image(t_game *game, t_raycast *rc)
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;

	ft_3d_cast(game, rc);
	x_start = rc->ray * rc->ray_hrzt_dist;
	x_end = rc->ray * rc->ray_hrzt_dist + rc->ray_hrzt_dist;
	x_end--;
	
	while (rc->line_y < rc->vert_line)
	{
		y_start = rc->line_y + rc->line_off;
		y_end = rc->line_y + rc->line_off;
		rc->texture_y = rc->line_y * game->cfg->h_img / rc->vert_line;
		rc->color = ft_get_pixel_color(rc->texture, rc->texture_x, rc->texture_y, game->cfg->w_img);
		ft_draw_rect(game, x_start, y_start, x_end, y_end, rc->color);
		rc->line_y++;
	}
}
