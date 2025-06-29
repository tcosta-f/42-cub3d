/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:32:30 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 13:54:34 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	ft_check_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->data[y] != 0)
	{
		x = 0;
		while (game->map->data[y][x] != 0)
		{
			if (ft_strchr("NSEW01 ", game->map->data[y][x]) == NULL)
				ft_error_free_all_exit(game, ERR_INVALID_CHAR, true, 3);
			x++;
		}
		y++;
	}
	return (true);
}

static bool	ft_check_player(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map->data[++y] != 0)
	{
		x = -1;
		while (game->map->data[y][++x] != 0)
		{
			if (ft_strchr("NSEW", game->map->data[y][x]))
			{
				if (game->map->p_x == -1 && game->map->p_y == -1)
				{
					game->map->p_x = x;
					game->map->p_y = y;
				}
				else
					ft_error_free_all_exit(game, ERR_STARTING_POS, true, 1);
			}
		}
	}
	if (game->map->p_x == -1 && game->map->p_y == -1)
		ft_error_free_all_exit(game, ERR_STARTING_POS, true, 1);
	return (true);
}

bool	ft_check_map(t_game *game)
{
	if (!ft_check_chars(game))
		return (false);
	if (!ft_check_player(game))
		return (false);
	if (!ft_check_map_enclosed(game))
		return (false);
	return (true);
}
