/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:33 by alm               #+#    #+#             */
/*   Updated: 2025/04/21 21:45:44 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_config(t_config *config)
{
	if (config->tex_north != NULL)
		free(config->tex_north);
	if (config->tex_south != NULL)
		free(config->tex_south);
	if (config->tex_west != NULL)
		free(config->tex_west);
	if (config->tex_east != NULL)
		free(config->tex_east);
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
		if ((*game)->config)
			ft_free_config((*game)->config);
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