/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:33 by alm               #+#    #+#             */
/*   Updated: 2025/05/10 15:35:02 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_config(t_cfg *config)
{
	if (config->no != NULL)
		free(config->no);
	if (config->so != NULL)
		free(config->so);
	if (config->we != NULL)
		free(config->we);
	if (config->ea != NULL)
		free(config->ea);
	free(config);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->data != NULL)
		while (map->data[i] != NULL)
			free(map->data[i++]);
	free(map->data);
	free(map);
}
/**
 * @brief free the game pointer (&game) and sets it to NULL
 * 
 * @param game 
 */
void		ft_free_game(t_game **game)
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
			free((*game)->mlx);
		}
		free(*game);
		*game = NULL;
	}
}