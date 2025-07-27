/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:45:33 by alm               #+#    #+#             */
/*   Updated: 2025/07/27 11:18:29 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_safe_free_img(void *mlx, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx, img);
}

static void	ft_free_map(t_map *map)
{
	ft_safe_free(map->raw_data);
	ft_free_strs(map->data);
	ft_safe_free(map);
}

static void	ft_free_config(t_game *game)
{
	ft_safe_free(game->cfg->no_fil);
	ft_safe_free(game->cfg->so_fil);
	ft_safe_free(game->cfg->we_fil);
	ft_safe_free(game->cfg->ea_fil);
	ft_safe_free_img(game->mlx, game->cfg->no_img);
	ft_safe_free_img(game->mlx, game->cfg->so_img);
	ft_safe_free_img(game->mlx, game->cfg->we_img);
	ft_safe_free_img(game->mlx, game->cfg->ea_img);
	ft_safe_free(game->cfg->c);
	ft_safe_free(game->cfg->f);
	ft_safe_free(game->cfg);
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
			ft_free_config((*game));
		if ((*game)->win)
			mlx_destroy_window((*game)->mlx, (*game)->win);
		if ((*game)->mlx != NULL)
		{
			if ((*game)->img->img)
				mlx_destroy_image((*game)->mlx, (*game)->img->img);
			ft_safe_free((*game)->img);
			mlx_destroy_display((*game)->mlx);
			ft_safe_free((*game)->mlx);
		}
		ft_safe_free((*game)->k);
		ft_safe_free((*game)->p);
		ft_safe_free(*game);
		*game = NULL;
	}
}
