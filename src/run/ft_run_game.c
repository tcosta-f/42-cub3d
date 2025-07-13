#include "../../include/cub3d.h"

static void ft_init_game(t_game **game)
{
	printf("\ngame running!\n");
	ft_print_game(game);
}

void ft_run_game(t_game **game)
{
	ft_init_game(game);
}