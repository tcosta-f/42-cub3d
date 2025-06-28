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
	return (ft_check_chars(map));
}