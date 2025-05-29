/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:33 by alm               #+#    #+#             */
/*   Updated: 2025/05/29 16:48:59 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_config(t_cfg *config)
{
	ft_safe_free(config->no);
	ft_safe_free(config->so);
	ft_safe_free(config->we);
	ft_safe_free(config->ea);
	ft_safe_free(config->c);
	ft_safe_free(config->f);
	ft_safe_free(config);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->data)
		while (map->data[i])
			ft_safe_free(map->data[i++]);
	ft_safe_free(map->data);
	ft_safe_free(map->raw_data);
	ft_safe_free(map);
}
/**
 * @brief free the game pointer (&game) and sets it to NULL
 * 
 * @param game 
 */

void	ft_free_game(t_game **game)
{
	if (*game)
	{
		if ((*game)->map)
			ft_free_map((*game)->map);
		if ((*game)->cfg)
			ft_free_config((*game)->cfg);
		if ((*game)->win)
			mlx_destroy_window((*game)->mlx, (*game)->win);
		if ((*game)->mlx)
		{
			mlx_destroy_display((*game)->mlx);
			ft_safe_free((*game)->mlx);
		}
		ft_safe_free(*game);
		*game = NULL;
	}
}
