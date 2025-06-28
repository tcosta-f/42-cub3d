/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:12:06 by alm               #+#    #+#             */
/*   Updated: 2025/06/28 23:11:41 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("STR[%d]: %s\n", i, strs[i]);
		i++;
	}
	return (i);
}

static void	ft_print_color(t_color *color, char *name)
{
	printf("%s: %d | %d | %d\n", name, color->r, color->g, color->b);
}

static void	ft_print_cfg(t_cfg *cfg)
{
	printf("\n######## CFG ########\n");
	if (cfg->no)
		printf("NO: %s\n", cfg->no);
	if (cfg->so)
		printf("SO: %s\n", cfg->so);
	if (cfg->we)
		printf("WE: %s\n", cfg->we);
	if (cfg->ea)
		printf("EA: %s\n", cfg->ea);
	if (cfg->f)
		ft_print_color(cfg->f, "F");
	if (cfg->c)
		ft_print_color(cfg->c, "C");
	printf("valid: %d\n", cfg->valid);
	printf("dup_val: %d\n", cfg->dup_val);
}

void	ft_print_game(t_game **game)
{
	if (*game)
	{
		ft_printf("######## GAME ########\n");
		ft_printf("map: %p\n", (*game)->map);
		ft_printf("cfg: %p\n", (*game)->cfg);
		if ((*game)->map)
		{
			ft_printf("######## MAP RAW DATA ########\n");
			if ((*game)->map->raw_data)
				ft_printf("map raw data:\n%s", (*game)->map->raw_data);
			ft_printf("######## MAP DATA ########\n");
			if ((*game)->map->data)
			{
				ft_printf("map data:\n%s");
				ft_print_strs((*game)->map->data);
			}
		}
		if ((*game)->cfg)
			ft_print_cfg((*game)->cfg);
	}
}
