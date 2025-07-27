/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:12:06 by alm               #+#    #+#             */
/*   Updated: 2025/07/25 12:05:32 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Prints color structure to check it
 * 
 * @param color 
 * @param name 
 */
static void	ft_print_color(t_color *color, char *name)
{
	printf("%s: %d | %d | %d\n", name, color->r, color->g, color->b);
}

/**
 * @brief Prints player structure to check it
 * 
 * @param player 
 * @param name 
 */
void	ft_print_player(t_player *p)
{
	printf("\n######## PLAYER ########\n");
	printf("pos > %f, %f\n", p->pos_x, p->pos_y);
	printf("dir > %f, %f | %d\n", p->dir_x, p->dir_y, p->dir);
	printf("plane > %f, %f\n", p->plane_x, p->plane_y);
}

/**
 * @brief Prints config structure to check it
 * 
 * @param cfg 
 */
static void	ft_print_cfg(t_cfg *cfg)
{
	printf("\n######## CFG ########\n");
	if (cfg->no_fil)
		printf("NO: %s\n", cfg->no_fil);
	if (cfg->so_fil)
		printf("SO: %s\n", cfg->so_fil);
	if (cfg->we_fil)
		printf("WE: %s\n", cfg->we_fil);
	if (cfg->ea_fil)
		printf("EA: %s\n", cfg->ea_fil);
	if (cfg->f)
		ft_print_color(cfg->f, "F");
	if (cfg->c)
		ft_print_color(cfg->c, "C");
	if (cfg->w_img && cfg->h_img)
		printf("w x h_img: %d x %d\n", cfg->w_img, cfg->h_img);
	printf("valid: %d\n", cfg->valid);
	printf("dup_val: %d\n", cfg->dup_val);
}

/**
 * @brief Prints game struct to check it
 * 
 * @param game 
 */
void	ft_print_game(t_game **game)
{
	if (*game)
	{
		ft_printf("######## GAME ########\n");
		ft_printf("map: %p\n", (*game)->map);
		ft_printf("cfg: %p\n", (*game)->cfg);
		if ((*game)->map)
		{
			ft_printf("\n######## MAP RAW DATA ########\n");
			if ((*game)->map->raw_data)
				ft_printf("%s", (*game)->map->raw_data);
			ft_printf("\n######## MAP DATA ########\n");
			if ((*game)->map->data)
				ft_print_strs((*game)->map->data);
		}
		if ((*game)->cfg)
			ft_print_cfg((*game)->cfg);
	}
}
