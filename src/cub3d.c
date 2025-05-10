/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:41:39 by bschwell          #+#    #+#             */
/*   Updated: 2025/05/10 15:34:29 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void		ft_init_game_struct(t_game **game)
{
	t_map	*map;
	t_cfg	*cfg;

	cfg = (t_cfg *) ft_calloc(1, sizeof(t_cfg));
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	(*game)->cfg = cfg;
	(*game)->map = map;
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
		// ft_parse_game_config(game, argv[1]);
		//map = (t_map *) ft_calloc(1, sizeof(t_map));
		ft_print_game(&game);
		ft_free_game(&game);
	}
	else
		return (ft_throw_error(ERR_WRNG_ARG_SIZ, EX_GENERICERR));
	
	// if (!file_lines || !ft_validate_map_presence(file_lines))
	// {
	// 	write(2, "Error\nInvalid map file\n", 24);
	// 	return (EX_GENERICERR);
	// }
	// ft_parse_config(file_lines, &config);
	// if (!ft_validate_config(&config))
	// {
	// 	ft_free_list(file_lines);
	// 	ft_free_config(&config);
	// 	return (1);
	// }
	// if (!ft_extract_map(file_lines, &config) || !ft_validate_player_position(&config))
	// {
	// 	ft_free_list(file_lines);
	// 	ft_free_config(&config);
	// 	return (1);
	// }
	// ft_free_list(file_lines);
	// ft_free_config(&config);
	return (0);
}
