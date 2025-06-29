/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:32:30 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 09:07:38 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	ft_check_chars(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[x])
		{
			if (!ft_strchr("NSEW01 ", map->data[y][x]))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	ft_check_map(t_map *map)
{
	if (!ft_check_chars(map))
		return (false);
	return (true);
}
