/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:38:05 by alm               #+#    #+#             */
/*   Updated: 2025/05/10 15:37:29 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if File Descriptor is actually a directory
 * 
 * @param fd 
 * @return true 
 * @return false 
 */

static bool	ft_check_if_dir(int fd)
{
	char	buf;
	if (read(fd, &buf, 1) < 0 && errno == EISDIR)
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

void	ft_parse_config(int fd, t_game *game)
{
	char	*line;

	printf("ft_parse_config: fd = %d\n", fd);
	printf("ft_parse_config: game = %p\n", game);
	
	line = get_next_line(fd);
	while (line)
	{
		ft_parse_line(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

static bool	ft_check_struct (t_game *game)
{
	printf("ft_check_struct: game = %p\n", game);
	return (true);
}

/**
 * @brief Setup Game
 * 
 * @param file 	filename
 * @param game 	game struct
 */
void	ft_create_setup(char *file, t_game *game)
{
	// char	*line;
	// char	*map_data;
	// char	*tmp_line;
	int		fd;
	// int		lines_total;

	fd = open(file, O_RDONLY);
	if (fd == -1 || ft_check_if_dir(fd) == true)
		ft_error_free_all_exit(game, ERR_CANNOT_RD_FL, true, EX_GENERICERR);
	fd = open(file, O_RDONLY);	
	ft_parse_config(fd, game);
	ft_check_struct(game);
	close(fd);
}
