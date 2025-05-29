/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:49 by alm               #+#    #+#             */
/*   Updated: 2025/05/29 16:14:11 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_count_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			i++;
	return (i);
}

void	ft_parse_map(char *line, t_game *game)
{
	char	*tmp;
	
	game->cfg->start_map = true;
	tmp = game->map->raw_data;
	game->map->raw_data = ft_strjoin(tmp, line);
	ft_safe_free(tmp);
}

static int	ft_check_color_unit(int c)
{
	if (c >= 0 && c <= 255)
		return (c);
	return (-1);
}

static void	ft_parse_colors(t_color *color, char *str)
{
	char	**colors_str;

	colors_str = ft_split(str, ',');
	if (colors_str && ft_count_strs(colors_str) == 3)
	{
		color->r = ft_check_color_unit(ft_atoi(colors_str[0]));
		color->g = ft_check_color_unit(ft_atoi(colors_str[1]));
		color->b = ft_check_color_unit(ft_atoi(colors_str[2]));
	}
	ft_free_strs(colors_str);
}


/**
 * @brief parse config into file. If line is invalid, skip the line.
 * 
 * @param line 	Line read from file
 * @param game	Pointer for Game Struct
 */
void	ft_parse_cfg(char *line, t_game *game)
{
	char 	**strs;
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n");
	strs = ft_split(trimmed, ' ');
	if (ft_count_strs(strs) == 2)
	{
		if (ft_strcmp(strs[0], "NO") == 0)
			game->cfg->no = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "SO") == 0)
			game->cfg->so = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "EA") == 0)
			game->cfg->ea = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "WE") == 0)
			game->cfg->we = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "F") == 0)
			ft_parse_colors(game->cfg->f, strs[1]);
		if (ft_strcmp(strs[0], "C") == 0)
			ft_parse_colors(game->cfg->c, strs[1]);
	}
	ft_safe_free(trimmed);
	ft_free_strs(strs);
}