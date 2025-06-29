/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:32:30 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 11:47:06 by alm              ###   ########.fr       */
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
			printf("[%d][%d]char:%s\n", y, x, ft_strchr("NSEW01 ", game->map->data[y][x]));
			if (ft_strchr("NSEW01 ", game->map->data[y][x]) == NULL)
				ft_error_free_all_exit(game, ERR_INVALID_CHAR, true, 3);
			x++;
		}
		y++;
	}
	return (true);
}

bool	ft_check_map(t_game *game)
{
	if (!ft_check_chars(game))
		return (false);
	return (true);
}
