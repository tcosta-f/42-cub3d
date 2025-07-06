/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:42:42 by bschwell          #+#    #+#             */
/*   Updated: 2025/07/06 21:13:17 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Checks if texture can be parsed by MLX.
 * 
 * @param file 		file to be tested
 * @param mlx 		MLX to test
 * @return true 	All good
 * @return false 	Can't read it.
 */

bool	ft_check_texture(char *file, void **img, t_game **game, void *mlx)
{
	*img = mlx_xpm_file_to_image(mlx, file, (*game)->cfg->w_img, (*game)->cfg->h_img);
	if (!img || (*game)->cfg->w_img <= 0 || (*game)->cfg->h_img <= 0)
	{
		if (img)
			mlx_destroy_image(mlx, img);
		ft_error_free_all_exit(*game, ERR_READ_TEXTURE, true, 3);
	}
	if ((*game)->cfg->w_img != (*game)->cfg->h_img)
		ft_error_free_all_exit(*game, ERR_READ_TEXTURE, true, 3);
}
