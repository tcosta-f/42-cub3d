/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:41:39 by bschwell          #+#    #+#             */
/*   Updated: 2025/05/29 16:48:20 by bschwell         ###   ########.fr       */
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

static void	ft_init_game_struct(t_game **game)
{
	t_map	*map;
	t_cfg	*cfg;
	t_color	*f;
	t_color	*c;

	cfg = (t_cfg *) ft_calloc(1, sizeof(t_cfg));
	cfg->valid = false;
	cfg->start_map = false;
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	map->data = ft_calloc(1, sizeof(char *));
	map->raw_data = ft_calloc(1, sizeof(char));
	c = (t_color *) ft_calloc(1, sizeof(t_color));
	f = (t_color *) ft_calloc(1, sizeof(t_color));
	(*game)->cfg = cfg;
	(*game)->map = map;
	ft_init_color(c);
	ft_init_color(f);
	(*game)->cfg->c = c;
	(*game)->cfg->f = f;
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
		ft_print_game(&game);
		ft_free_game(&game);
	}
	else
		return (ft_throw_error(ERR_WRNG_ARG_SIZ, EX_GENERICERR));
	return (0);
}
