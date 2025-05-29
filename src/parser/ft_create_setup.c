/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:38:05 by alm               #+#    #+#             */
/*   Updated: 2025/05/29 16:53:03 by bschwell         ###   ########.fr       */
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

static void	ft_parse_config(int fd, t_game *game)
{
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	while (line)
	{
		trim = ft_strtrim(line, " \n");
		if (trim[0] == '1' || trim[0] == '0' || game->cfg->start_map == true)
			ft_parse_map(line, game);
		if (game->cfg->start_map == false)
			ft_parse_cfg(line, game);
		ft_safe_free(trim);
		ft_safe_free(line);
		line = get_next_line(fd);
	}
	ft_safe_free(line);
}

static bool	ft_check_struct(t_game *game)
{
	ft_printf("ft_check_struct: game = %p\n", game);
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
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || ft_check_if_dir(fd) == true)
		ft_error_free_all_exit(game, ERR_CANNOT_RD_FL, true, EX_GENERICERR);
	fd = open(file, O_RDONLY);
	ft_parse_config(fd, game);
	ft_check_struct(game);
	close(fd);
}
