/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:38:05 by alm               #+#    #+#             */
/*   Updated: 2025/04/21 21:23:40 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_create_setup(char *file, t_game *game)
{
	// char	*line;
	// char	*map_data;
	// char	*tmp_line;
	int		fd;
	// int		lines_total;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		ft_error_free_all_exit(game, ERR_CANNOT_RD_FL, true, EX_GENERICERR);
	printf("open: %d\n", open(file, O_RDONLY | O_DIRECTORY));
	printf("errno: %d:%d\n", errno, ENOTDIR);
	if (open(file, O_RDONLY) == -1)
		ft_throw_error(ERR_CANNOT_RD_FL, EX_GENERICERR);
}
