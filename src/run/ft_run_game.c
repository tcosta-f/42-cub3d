#include "../../include/cub3d.h"

void	ft_init_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, WIN_TITLE);
	game->img->img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img->add = mlx_get_data_addr(game->img->img,
		&(game->img->bpp), &(game->img->line_len),
		&(game->img->endian));
	game->p->pos_x += 0.5;
	game->p->pos_y += 0.5;
	mlx_hook(game->win, 2, (1L << 0), ft_key_press, game);
	mlx_hook(game->win, 3, (1L << 1), ft_key_release, game);
	mlx_hook(game->win, 17, 0, ft_handle_exit, game);
}

void	ft_run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_loop(game->mlx);
}
