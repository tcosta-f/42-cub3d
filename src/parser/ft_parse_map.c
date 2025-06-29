/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:35:20 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 21:23:12 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_parse_map(char *line, t_game *game)
{
	char	*tmp;

	game->cfg->started_map = true;
	tmp = game->map->raw_data;
	game->map->raw_data = ft_strjoin(tmp, line);
	if (game->map->data)
		ft_free_strs(game->map->data);
	game->map->data = ft_split(game->map->raw_data, '\n');
	ft_safe_free(tmp);
}
