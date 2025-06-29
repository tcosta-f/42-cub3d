/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_enclosed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:53:36 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 13:58:56 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	ft_is_walkable(char c)
{
	return (c == '0' || (c == 'N' || c == 'S' || c == 'E' || c == 'W'));
}

static int	ft_is_out_of_bounds(t_map *map, int y, int x)
{
	if (y < 0 || x < 0)
		return (1);
	if (!map->data[y])
		return (1);
	if (x >= (int)ft_strlen(map->data[y]))
		return (1);
	return (0);
}

static int	ft_is_surrounded(t_map *map, int y, int x)
{
	if (ft_is_out_of_bounds(map, y - 1, x) || map->data[y - 1][x] == ' ')
		return (0);
	if (ft_is_out_of_bounds(map, y + 1, x) || map->data[y + 1][x] == ' ')
		return (0);
	if (ft_is_out_of_bounds(map, y, x - 1) || map->data[y][x - 1] == ' ')
		return (0);
	if (ft_is_out_of_bounds(map, y, x + 1) || map->data[y][x + 1] == ' ')
		return (0);
	return (1);
}

bool	ft_check_map_enclosed(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map->data[++y])
	{
		x = -1;
		while (game->map->data[y][++x])
			if (ft_is_walkable(game->map->data[y][x]))
				if (!ft_is_surrounded(game->map, y, x))
					ft_error_free_all_exit(game, ERR_MAP_NOT_CLOS, true, 1);
	}
	return (true);
}
