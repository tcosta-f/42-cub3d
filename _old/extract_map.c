/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:00:00 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/05/10 15:35:02 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_extract_map(t_list *file_lines, t_cfg *config);
int		ft_count_map_lines(t_list *file_lines);
char	**ft_copy_map(t_list *file_lines, int start_line, int map_height);

/**
 * @brief  Extracts the map from the .cub file and stores it in config->map.
 * 
 * @param  file_lines  The linked list containing the file's lines.
 * @param  config      The structure to store the extracted map.
 * @return int         
 *         1 on success, 0 on error.
 */
int	ft_extract_map(t_list *file_lines, t_cfg *config)
{
	t_list	*current;
	int		start_line;
	int		map_height;

	current = file_lines;
	start_line = 0;
	while (current)
	{
		if (ft_strchr((char *)current->content, '1'))
			break;
		start_line++;
		current = current->next;
	}
	map_height = ft_count_map_lines(file_lines);
	if (map_height == 0)
	{
		write(2, "Error\nMap section not found or empty\n", 37);
		return (0);
	}
	config->map = ft_copy_map(file_lines, start_line, map_height);
	if (!config->map)
	{
		write(2, "Error\nFailed to allocate map\n", 29);
		return (0);
	}
	return (1);
}

/**
 * @brief  Counts the number of lines in the map section.
 * 
 * @param  file_lines  The linked list containing the file's lines.
 * @return int         
 *         The number of lines in the map.
 */
int	ft_count_map_lines(t_list *file_lines)
{
	t_list	*current;
	int		count;

	current = file_lines;
	count = 0;
	while (current)
	{
		if (ft_strchr((char *)current->content, '1'))
			count++;
		current = current->next;
	}
	return (count);
}

/**
 * @brief  Copies the map from the linked list into a string array.
 * 
 * @param  file_lines  The linked list containing the file's lines.
 * @param  start_line  The index where the map starts.
 * @param  map_height  The number of lines in the map.
 * @return char**      
 *         The allocated map array.
 */
char	**ft_copy_map(t_list *file_lines, int start_line, int map_height)
{
	char	**map;
	int		i;
	t_list	*current;

	map = malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (NULL);
	current = file_lines;
	i = 0;
	while (i < start_line)
	{
		current = current->next;
		i++;
	}
	i = 0;
	while (i < map_height)
	{
		map[i] = ft_strdup((char *)current->content);
		if (!map[i])
			return (NULL);
		current = current->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
