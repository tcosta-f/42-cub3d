/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:35:20 by alm               #+#    #+#             */
/*   Updated: 2025/06/28 23:35:33 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_parse_map(char *line, t_game *game)
{
	char	*tmp;

	game->cfg->start_map = true;
	tmp = game->map->raw_data;
	game->map->raw_data = ft_strjoin(tmp, line);
	ft_safe_free(tmp);
	if (game->map->data)
		ft_free_strs(game->map->data);
	game->map->data = ft_split(game->map->raw_data, '\n');
}
