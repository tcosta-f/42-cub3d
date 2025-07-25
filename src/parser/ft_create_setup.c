/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:38:05 by alm               #+#    #+#             */
/*   Updated: 2025/07/25 16:07:03 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if File Descriptor is a directory
 * 
 * @param fd 
 * @return boolean: true or false 
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
 * @brief Reads each line and parse into cfg structure
 * 
 * @param fd	File descriptor with the file
 * @param game	Game struct pointer
 */
static void	ft_parse_config(int fd, t_game *game)
{
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	while (line)
	{
		trim = ft_strtrim(line, " \n");
		if (trim[0] == '1' || trim[0] == '0' || game->cfg->started_map == true)
		{
			if (game->cfg->ended_map != true)
			{
				if (ft_strlen(trim) == 0)
					game->cfg->ended_map = true;
				else
					ft_parse_map(line, game);
			}
		}
		if (game->cfg->started_map == false && game->cfg->dup_val == false)
			ft_parse_cfg(line, game);
		ft_safe_free(trim);
		ft_safe_free(line);
		line = get_next_line(fd);
	}
	ft_safe_free(line);
}

void ft_create_trgb(t_color **color, int t, int r, int g, int b)
{
	(*color)->color = (t << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Check if config is all correct
 * 
 * @param cfg config pointer
 * @param mlx minilibx pointer to check if textures are loaded
 * @return true if all is ok
 * @return false if not
 */
static void	ft_check_config(t_game *game, void *mlx)
{
	if (game->cfg->c->r == -1 || game->cfg->c->g == -1
		|| game->cfg->c->b == -1 || game->cfg->f->r == -1
		|| game->cfg->f->g == -1 || game->cfg->f->b == -1)
		ft_error_free_all_exit(game, ERR_SYNTAX_ERROR, true, 3);
	else
	{
		ft_create_trgb(&(game->cfg->c), 0, game->cfg->c->r,
			game->cfg->c->g, game->cfg->c->b);
		ft_create_trgb(&(game->cfg->f), 0, game->cfg->f->r,
			game->cfg->f->g, game->cfg->f->b);
	}

	if (game->cfg->dup_val == true)
		ft_error_free_all_exit(game, ERR_DUPL_DFNTION, true, 3);	
	ft_load_texture(game->cfg->no_fil, &(game->cfg->no_img), game, mlx);
	ft_load_texture(game->cfg->so_fil, &(game->cfg->so_img), game, mlx);
	ft_load_texture(game->cfg->we_fil, &(game->cfg->we_img), game, mlx);
	ft_load_texture(game->cfg->ea_fil, &(game->cfg->ea_img), game, mlx);
}

/**
 * @brief Setup Game: Read the cub file, parses the config and check the map
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
	close(fd);
	ft_check_config(game, game->mlx);
	if(ft_check_map(game))
		game->cfg->valid = true;
}
