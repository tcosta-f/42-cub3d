/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:12:06 by alm               #+#    #+#             */
/*   Updated: 2025/05/11 12:58:19 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		printf("F: %s\n", cfg->f);
	if (cfg->c)
		printf("C: %s\n", cfg->f);
	printf("valid: %d\n", cfg->valid);
}

void		ft_print_game(t_game **game)
{
	if (*game)
	{
		ft_printf("######## GAME ########\n");
		ft_printf("map: %p\n", (*game)->map);
		ft_printf("cfg: %p\n", (*game)->cfg);
		if ((*game)->map)
		{
			ft_printf("######## MAP ########\n");
			if((*game)->map->raw_data)
				ft_printf("map:\n%s", (*game)->map->raw_data);
		}
		if ((*game)->cfg)
			ft_print_cfg((*game)->cfg);
	}
}
