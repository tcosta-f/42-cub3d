#include "../../include/cub3d.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > WIN_H - 1 || x < 0
		|| x > WIN_W - 1)
		return ;
	pixel = (g->img->add + (y * g->img->line_len
				+ x * (g->img->bpp / 8)));
	*(int *)pixel = color;
}

int	get_color(t_game *g, int x, int y, t_img* tex)
{
	return (*(int *)(tex + (y * tex->line_len + x * (tex->bpp / 8))));
}

void	define_texture(t_game *g, int start, int line_height)
{
	if (g->rc->wall_side == 0)
		g->rc->wall_x = g->p->pos_y + g->rc->perpwalldist * g->rc->dir_y;
	else
		g->rc->wall_x = g->p->pos_x + g->rc->perpwalldist * g->rc->dir_x;
	g->rc->wall_x -= floor(g->rc->wall_x);
	g->rc->tex_x = g->rc->wall_x * 128;
	if (g->rc->wall_side == 0 && g->rc->dir_x > 0)
		g->rc->tex_x = 128 - g->rc->tex_x - 1;
	if (g->rc->wall_side == 1 && g->rc->dir_y < 0)
		g->rc->tex_x = 128 - g->rc->tex_x - 1;
	g->rc->step = 1.0 * 128 / line_height;
	g->rc->tex_pos = (start - WIN_H / 2
			+ line_height / 2) * g->rc->step;
}

void	define_column(t_game *g, int *line_height, int *start, int *end)
{
	*line_height = WIN_H / g->rc->perpwalldist;
	*start = -*line_height / 2 + WIN_H / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + WIN_H / 2;
	if (*end >= WIN_H)
		*end = WIN_H - 1;
}

void	draw(t_game *g, int x, int texture)
{
	int	color;

	color = get_color(g, g->rc->tex_x, g->rc->tex_y, texture);
	img_pix_put(g, x, g->rc->start, color);
}

void	draw_column(t_game *g, int x)
{
	int	line_height;

	define_column(g, &line_height, &g->rc->start, &g->rc->end);
	define_texture(g, g->rc->start, line_height);
	while (g->rc->start < g->rc->end)
	{
		g->rc->tex_y = (int)g->rc->tex_pos & (128 - 1);
		g->rc->tex_pos += g->rc->step;
		if (g->rc->wall_side == 1 && g->rc->dir_y < 0)
			draw(g, x, g->cfg->so_img);
		else if (g->rc->wall_side == 1 && g->rc->dir_y > 0)
			draw(g, x, g->cfg->no_img);
		else if (g->rc->wall_side == 0 && g->rc->dir_x < 0)
			draw(g, x, g->cfg->we_img);
		else if (g->rc->wall_side == 0 && g->rc->dir_x > 0)
			draw(g, x, g->cfg->ea_img);
		g->rc->start++;
	}
}