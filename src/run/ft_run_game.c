#include "../../include/cub3d.h"

void	ft_run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_loop(game->mlx);
}
