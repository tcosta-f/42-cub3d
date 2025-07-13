/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:41:39 by bschwell          #+#    #+#             */
/*   Updated: 2025/07/13 10:43:16 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	ft_init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

static void	ft_init_cfg(t_cfg **cfg)
{
	(*cfg)->valid = false;
	(*cfg)->started_map = false;
	(*cfg)->ended_map = false;
	(*cfg)->no_fil = NULL;
	(*cfg)->so_fil = NULL;
	(*cfg)->we_fil = NULL;
	(*cfg)->ea_fil = NULL;
	(*cfg)->no_img = NULL;
	(*cfg)->so_img = NULL;
	(*cfg)->we_img = NULL;
	(*cfg)->ea_img = NULL;
	(*cfg)->h_img = -1;
	(*cfg)->w_img = -1;
	(*cfg)->dup_val = false;
	(*cfg)->strc = NULL;
	(*cfg)->strf = NULL;
}

static void	ft_init_map(t_map **map)
{
	(*map)->data = NULL;
	(*map)->raw_data = ft_calloc(1, sizeof(char));
	(*map)->p_x = -1;
	(*map)->p_y = -1;
}

static void	ft_init_game_struct(t_game **game)
{
	t_map		*map;
	t_cfg		*cfg;
	t_color		*f;
	t_color		*c;

	cfg = (t_cfg *) ft_calloc(1, sizeof(t_cfg));
	ft_init_cfg(&cfg);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	ft_init_map(&map);
	c = (t_color *) ft_calloc(1, sizeof(t_color));
	f = (t_color *) ft_calloc(1, sizeof(t_color));
	(*game)->cfg = cfg;
	(*game)->map = map;
	ft_init_color(c);
	ft_init_color(f);
	(*game)->cfg->c = c;
	(*game)->cfg->f = f;
	(*game)->mlx = mlx_init();
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
			return (ft_throw_error(ERR_FIL_EXTENSIO, EX_GENERICERR));
		game = (t_game *) ft_calloc(1, sizeof(t_game));
		if (game == NULL)
			return (ft_throw_error(ERR_MEMORY_ALLOC, EX_GENERICERR));
		ft_init_game_struct(&game);
		ft_create_setup(argv[1], game);
		if(game->cfg->valid)
			ft_run_game(&game);
		ft_free_game(&game);
	}
	else
		return (ft_throw_error(ERR_WRNG_ARG_SIZ, EX_GENERICERR));
	return (0);
}
