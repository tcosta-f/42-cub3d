/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:54 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/05/10 15:36:14 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_parse_config(t_list *file_lines, t_cfg *config);
int		ft_parse_texture(char *line, char **texture);
int		ft_parse_color(char *line, int *color);
int		ft_rgb_to_int(int r, int g, int b);
void	ft_free_config(t_cfg *config);

/**
 * @brief  Parses the configuration file and extracts textures and colors.
 * 
 * @param  file_lines  Linked list with the .cub file content.
 * @param  config      Structure to store parsed data.
 * @return int         
 *         1 on success, 0 on error.
 */
int	ft_parse_config(t_list *file_lines, t_cfg *config)
{
	t_list	*current;
	char	*line;

	current = file_lines;
	while (current)
	{
		line = (char *)current->content;
		if (ft_strncmp(line, "NO ", 3) == 0)
			ft_parse_texture(line + 3, &config->no);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			ft_parse_texture(line + 3, &config->so);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			ft_parse_texture(line + 3, &config->we);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			ft_parse_texture(line + 3, &config->ea);
		else if (ft_strncmp(line, "F ", 2) == 0)
			ft_parse_color(line + 2, &config->f);
		else if (ft_strncmp(line, "C ", 2) == 0)
			ft_parse_color(line + 2, &config->c);
		current = current->next;
	}
	return (1);
}

/**
 * @brief  Extracts and validates a texture path.
 * 
 * @param  line     The input line containing the texture path.
 * @param  texture  Pointer to store the extracted path.
 * @return int      
 *         1 on success, 0 on error.
 */
int	ft_parse_texture(char *line, char **texture)
{
	while (*line == ' ')
		line++;
	// if (*texture)
	// 	free(*texture);
	*texture = ft_strdup(line);
	if (!(*texture))
		return (0);
	return (1);
}

/**
 * @brief  Parses and validates an RGB color.
 * 
 * @param  line   The input line containing the RGB color.
 * @param  color  Pointer to store the converted integer color.
 * @return int    
 *         1 on success, 0 on error.
 */
int	ft_parse_color(char *line, int *color)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	*color = ft_rgb_to_int(r, g, b);
	ft_free_split(split);
	return (1);
}

/**
 * @brief  Converts RGB values to a single integer.
 * 
 * @param  r  Red component (0-255).
 * @param  g  Green component (0-255).
 * @param  b  Blue component (0-255).
 * @return int
 *         Converted color as an integer.
 */
int	ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/**
 * @brief  Frees memory allocated in the config structure.
 * 
 * @param  config  The config structure to free.
 */
void	ft_free_config(t_cfg *config)
{
	free(config->no);
	free(config->so);
	free(config->we);
	free(config->ea);
}
