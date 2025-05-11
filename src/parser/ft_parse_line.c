/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:49 by alm               #+#    #+#             */
/*   Updated: 2025/05/11 13:06:10 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_free_strs(char **strs)
{
	int i;

	i = -1;
	if (strs)
		while (strs[++i])
			free(strs[i]);
	free(strs);
}

static int	ft_count_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			i++;
	return (i);
}

/* static int	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("STR[%d]: %s\n", i, strs[i]);
		i++;
	}
	return (i);
} */

void	ft_parse_map(char *line, t_game *game)
{
	char	*tmp;
	
	game->cfg->start_map = true;
	tmp = game->map->raw_data;
	game->map->raw_data = ft_strjoin(tmp, line);
	ft_safe_free(tmp);
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
/* 	printf("line: %s\n", line);
	printf("trim: %s\n", trimmed);
	printf("count: %d\n", ft_count_strs(strs));
	ft_print_strs(strs); */
	if (ft_count_strs(strs) == 2)
	{
		printf("STRS: %d\n", ft_strcmp(strs[0], "NO"));
		if (ft_strcmp(strs[0], "NO") == 0)
			game->cfg->no = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "SO") == 0)
			game->cfg->so = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "EA") == 0)
			game->cfg->ea = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "WE") == 0)
			game->cfg->we = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "F") == 0)
			game->cfg->f = ft_strdup(strs[1]);
		if (ft_strcmp(strs[0], "C") == 0)
			game->cfg->c = ft_strdup(strs[1]);
	}
	ft_free_strs(strs);
}