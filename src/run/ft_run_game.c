#include "../../include/cub3d.h"

static void ft_init_game(t_game **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		ft_error_free_all_exit((*game), ERR_MLX_CREATION, 1, 3);
}

void ft_run_game(t_game **game)
{
	ft_init_game(game);
}