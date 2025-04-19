/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:41:39 by bschwell          #+#    #+#             */
/*   Updated: 2025/04/19 13:01:43 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	// int			fd;
	// t_list		*file_lines;
	// t_config	config;

	if (argc != 2)
	{
		ft_display_error(ERR_WRNG_ARG_SIZ);
		return (1);
	}
	ft_printf("argv[0]: %s\n", argv[0]);
	// fd = ft_open_file(argv[1]);
	// if (fd < 0)
	// 	return (1);
	// file_lines = ft_read_file_list(fd);
	// close(fd);
	// if (!file_lines || !ft_validate_map_presence(file_lines))
	// {
	// 	write(2, "Error\nInvalid map file\n", 24);
	// 	return (1);
	// }
	// ft_parse_config(file_lines, &config);
	// if (!ft_validate_config(&config))
	// {
	// 	ft_free_list(file_lines);
	// 	ft_free_config(&config);
	// 	return (1);
	// }
	// if (!ft_extract_map(file_lines, &config) || !ft_validate_player_position(&config))
	// {
	// 	ft_free_list(file_lines);
	// 	ft_free_config(&config);
	// 	return (1);
	// }
	// ft_free_list(file_lines);
	// ft_free_config(&config);
	return (0);
}
