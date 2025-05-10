
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:00:00 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/03/21 13:30:00 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_validate_config(t_cfg *config);
int		ft_validate_map_presence(t_list *file_lines);
int		ft_validate_player_position(t_cfg *config);
void	ft_free_split(char **split);

/**
 * @brief  Checks if all required elements (textures, colors) are present.
 * 
 * @param  config  Structure containing parsed configuration data.
 * @return int     
 *         1 if valid, 0 if missing elements.
 */
int	ft_validate_config(t_cfg *config)
{
	if (!config->tex_north || !config->tex_south || 
		!config->tex_west || !config->tex_east)
	{
		write(2, "Error\nMissing texture paths (NO, SO, WE, EA)\n", 45);
		return (0);
	}
	if (config->floor_color == -1 || config->ceiling_color == -1)
	{
		write(2, "Error\nMissing floor (F) or ceiling (C) color\n", 45);
		return (0);
	}
	return (1);
}

/**
 * @brief  Checks if the map is present in the .cub file.
 * 
 * @param  file_lines  Linked list containing the file's lines.
 * @return int         
 *         1 if the map is found, 0 otherwise.
 */
int	ft_validate_map_presence(t_list *file_lines)
{
	t_list	*current;
	int		found_map;
	char	*line;

	found_map = 0;
	current = file_lines;
	while (current)
	{
		line = (char *)current->content;
		if (ft_strchr(line, '1'))  //nao pode ser!!
		{
			found_map = 1;
			break;
		}
		current = current->next;
	}
	if (!found_map)
		write(2, "Error\nMap section not found in the .cub file\n", 45);
	return (found_map);
}

/**
 * @brief  Validates that there is exactly one player position in the map.
 * 
 * @param  config  Structure containing parsed configuration data.
 * @return int     
 *         1 if valid, 0 if no player or multiple players are found.
 */
int	ft_validate_player_position(t_cfg *config)
{
	int		i;
	int		j;
	int		player_count;
	char	**map;

	i = 0;
	player_count = 0;
	map = config->map;
	if (!map)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				config->player_x = j;
				config->player_y = i;
				config->player_dir = map[i][j];
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_putstr_fd("Error\nInvalid number of player positions (must be exactly 1)\n", 2);
		return (0);
	}
	return (1);
}

/**
 * @brief  Frees all memory allocated by ft_split.
 * 
 * @param  split  The array of strings to free.
 */
void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}