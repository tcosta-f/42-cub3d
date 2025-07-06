/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:49 by alm               #+#    #+#             */
/*   Updated: 2025/07/03 22:45:51 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Count strings in array
 * 
 * @param strs 
 * @return int 
 */
static int	ft_count_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			i++;
	return (i);
}

/**
 * @brief Check if color units are within range (0..255)
 * 
 * @param c 
 * @return int 
 */
static int	ft_check_color_unit(int c)
{
	if (c >= 0 && c <= 255)
		return (c);
	return (-1);
}

/**
 * @brief Parse the colors into structure
 * 
 * @param color Color to be parsed
 * @param str 	String to parse
 * @param cfg 	Config struct to save
 */
static void	ft_parse_colors(t_color *color, char *str, t_cfg *cfg)
{
	char	**colors_str;

	colors_str = ft_split(str, ',');
	if (color->r == -1 && color->g == -1 && color->b == -1)
	{
		if (colors_str && ft_count_strs(colors_str) == 3)
		{
			color->r = ft_check_color_unit(ft_atoi_pos(colors_str[0]));
			color->g = ft_check_color_unit(ft_atoi_pos(colors_str[1]));
			color->b = ft_check_color_unit(ft_atoi_pos(colors_str[2]));
		}
	}
	else
	{
		cfg->dup_val = true;
	}
	ft_free_strs(colors_str);
}

/**
 * @brief 	Check if a Config Item exists. If not, save it.
 * 			If exists, create flag to throw error
 * 
 * @param val 			Value to be stored
 * @param cfg_item 		Config item to be stored
 * @param cfg 			Config structure to be saved
 */
static void	ft_check_n_store_cfg(char *val, char **cfg_item, t_cfg *cfg)
{
	if (*cfg_item == NULL)
		*cfg_item = ft_strdup(val);
	else
		cfg->dup_val = true;
}

/**
 * @brief parse config into file. If line is invalid, skip the line.
 * 
 * @param line 	Line read from file
 * @param game	Pointer for Game Struct
 */
void	ft_parse_cfg(char *line, t_game *game)
{
	char	**strs;
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n");
	strs = ft_split(trimmed, ' ');
	if (ft_count_strs(strs) == 2)
	{
		if (ft_strcmp(strs[0], "NO") == 0)
			ft_check_n_store_cfg(strs[1], &(game->cfg->no_fil), game->cfg);
		if (ft_strcmp(strs[0], "SO") == 0)
			ft_check_n_store_cfg(strs[1], &(game->cfg->so_fil), game->cfg);
		if (ft_strcmp(strs[0], "EA") == 0)
			ft_check_n_store_cfg(strs[1], &(game->cfg->ea_fil), game->cfg);
		if (ft_strcmp(strs[0], "WE") == 0)
			ft_check_n_store_cfg(strs[1], &(game->cfg->we_fil), game->cfg);
		if (ft_strcmp(strs[0], "F") == 0)
			ft_parse_colors(game->cfg->f, strs[1], game->cfg);
		if (ft_strcmp(strs[0], "C") == 0)
			ft_parse_colors(game->cfg->c, strs[1], game->cfg);
	}
	ft_safe_free(trimmed);
	ft_free_strs(strs);
}
