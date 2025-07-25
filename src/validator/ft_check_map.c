/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:32:30 by alm               #+#    #+#             */
/*   Updated: 2025/07/25 18:27:38 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if all characters in map are valid
 * 
 * @param game 		Game struct
 * @return true 	All characters are valid
 * @return false 	There is at least 1 invalid
 */
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

static void	ft_set_player_dir(t_game *game, char c, int x, int y)
{
	game->p->pos_x = x;
	game->p->pos_y = y;
	game->p->dir = c;
	if (c == 'N')
	{
		game->p->dir_x = 0;
		game->p->dir_y = -1;
		game->p->plane_x = 0.66;
		game->p->plane_y = 0;
	}
	if (c == 'E')
	{
		game->p->dir_x = 1;
		game->p->dir_y = 0;
		game->p->plane_x = 0;
		game->p->plane_y = -0.66;
	}
	if (c == 'S')
	{
		game->p->dir_x = 0;
		game->p->dir_y = 1;
		game->p->plane_x = -0.66;
		game->p->plane_y = 0;
	}
	if (c == 'W')
	{
		game->p->dir_x = -1;
		game->p->dir_y = 0;
		game->p->plane_x = 0;
		game->p->plane_y = 0.66;
	}
}

/**
 * @brief 	Check for errors with the player position:
 * 			Checks for existance, and duplication.
 * 
 * @param game 		Game pointer
 * @return true 	If all is ok
 * @return false 	If not
 */
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
					game->map->p_x = (double) x;
					game->map->p_y = (double) y;
					ft_set_player_dir(game, game->map->data[y][x], x, y);
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

/**
 * @brief Checks if map is valid
 * 
 * @param game 		game structure
 * @return true 	if is
 * @return false 	if not
 */
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
