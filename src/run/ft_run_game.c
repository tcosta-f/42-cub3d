#include "../../include/cub3d.h"

static void ft_init_game(t_game **game)
{
	(*game)->win = mlx_new_window((*game)->mlx, WIN_W, WIN_H, WIN_TITLE);
}

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	unsigned char	*pixel;
	int				i;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	i = img->bpp - 8;
	pixel = (unsigned char *)(img->addr + (y * img->line_len + x * (img->bpp / 8)));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

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
			ft_draw_pixel((*game)->img, x, y + WIN_H / 2, (*game)-> cfg->f->color);
			x++;
		}
		y++;
	}
}

static void	ft_handle_keys(t_game *game) {
	if (game->k->esc == true)
		ft_handle_exit(game);
	// if (game->k->up || game->k->w )
	// 	player_move (game, game->p.dx * STEPS, game->p.dy * STEPS);
	// if (game->k->down || game->k->s)
	// 	player_move (game, game->p.dx * STEPS, game->p.dy * STEPS);
	// if (game->k->a)
	// 	player_move (game, game->p.dy * STEPS, game->p.dx * STEPS);
	// if (game->k->d)
	// 	player_move (game, game->p.dy * STEPS, game->p.dx * STEPS);
	// if (game->k->left)
	// 	player_turn (game, LEFT);
	// if (game->k->right)
	// 	player_turn (game, RIGHT);
}

static int render(t_game *game)
{
	ft_handle_keys(game);
	ft_draw_bg(&game);
	// raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void ft_run_game(t_game **game)
{
	ft_init_game(game);
	mlx_hook((*game)->win, 2, (1L << 0), ft_key_down, (*game));
	mlx_hook((*game)->win, 3, (1L << 0), ft_key_up, (*game));
	mlx_hook((*game)->win, 17, 0, ft_handle_exit, (*game));
	mlx_loop_hook ((*game)->mlx, render, *game);
	mlx_loop((*game)->mlx);
}