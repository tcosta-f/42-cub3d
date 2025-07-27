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

static int	get_color(void *texture, int x, int y, int tile_size)
{
	int		color;
	void	*temp;
	t_img	img;

	temp = mlx_get_data_addr(texture, &img.bpp, &img.line_len, &img.endian);
	temp = temp + (x + y * tile_size) * 4;
	color = *(unsigned char *)(temp + 2) << 16;
	color |= *(unsigned char *)(temp + 1) << 8;
	color |= *(unsigned char *)temp;
	return (color);
} 

void	define_texture(t_game *g, int start, int line_height)
{
	if (g->rc->wall_side == 0)
		g->rc->wall_x = g->p->pos_y + g->rc->perpwalldist * g->rc->dir_y;
	else
		g->rc->wall_x = g->p->pos_x + g->rc->perpwalldist * g->rc->dir_x;
	g->rc->wall_x -= floor(g->rc->wall_x);
	g->rc->tex_x = g->rc->wall_x * g->cfg->h_img;
	if (g->rc->wall_side == 0 && g->rc->dir_x > 0)
		g->rc->tex_x = g->cfg->h_img - g->rc->tex_x - 1;
	if (g->rc->wall_side == 1 && g->rc->dir_y < 0)
		g->rc->tex_x = g->cfg->h_img - g->rc->tex_x - 1;
	g->rc->step = 1.0 * g->cfg->h_img / line_height;
	g->rc->tex_pos = (start - WIN_H / 2 + line_height / 2) * g->rc->step;
}

void	define_column(t_game *g, int *line_height, int *start, int *end)
{
	*line_height = WIN_H / g->rc->perpwalldist;
	*start = -*line_height / 2 + WIN_H / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + WIN_H / 2;
	if (*end >= WIN_H)
		*end = WIN_H;
}

void	draw(t_game *g, int x, t_img *texture)
{
	int	color;

	color = get_color(texture, g->rc->tex_x, g->rc->tex_y, g->cfg->h_img);
	img_pix_put(g, x, g->rc->start, color);
}

void	draw_column(t_game *g, int x)
{
	int	line_height;

	define_column(g, &line_height, &g->rc->start, &g->rc->end);
	define_texture(g, g->rc->start, line_height);
	while (g->rc->start < g->rc->end)
	{
		g->rc->tex_y = (int)g->rc->tex_pos & (g->cfg->h_img - 1);
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