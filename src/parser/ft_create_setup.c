/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:38:05 by alm               #+#    #+#             */
/*   Updated: 2025/06/28 23:37:18 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if File Descriptor is a directory
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

/**
 * @brief Parse config file into structure
 * 
 * @param fd
 * @param game
 */
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
		if (game->cfg->start_map == false && game->cfg->dup_val == false)
			ft_parse_cfg(line, game);
		ft_safe_free(trim);
		ft_safe_free(line);
		line = get_next_line(fd);
	}
	ft_safe_free(line);
}

static bool	ft_check_config(t_cfg *cfg, void *mlx)
{
	if (!ft_val_texture(cfg->no, mlx) || !ft_val_texture(cfg->so, mlx)
		|| !ft_val_texture(cfg->we, mlx) || !ft_val_texture(cfg->ea, mlx)
		|| cfg->c->r == -1 || cfg->c->g == -1 || cfg->c->b == -1
		|| cfg->f->r == -1 || cfg->f->g == -1 || cfg->f->b == -1
		|| cfg->dup_val == true)
		return (false);
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
	if (ft_check_config(game->cfg, game->mlx) && ft_check_map(game->map))
		game->cfg->valid = true;
	close(fd);
}
