/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:42:42 by bschwell          #+#    #+#             */
/*   Updated: 2025/07/13 10:45:09 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Loads and checks if texture can be parsed by MLX.
 * 
 * @param file 		file to be tested
 * @param mlx 		MLX to test
 * @return true 	All good
 * @return false 	Can't read it.
 */

void	ft_load_texture(char *file, void **img, t_game **game, void *mlx)
{
	int	temp_w;
	int	temp_h;

	temp_w = -1;
	temp_h = -1;
	*img = mlx_xpm_file_to_image(mlx, file, &temp_w, &temp_h);
	if (!img || temp_w <= 0 || temp_h <= 0)
		ft_error_free_all_exit(*game, ERR_READ_TEXTURE, true, 3);
	if ((*game)->cfg->w_img == -1 && (*game)->cfg->h_img == -1)
	{
		(*game)->cfg->w_img = temp_w;
		(*game)->cfg->h_img = temp_h;
	}
	if ((*game)->cfg->w_img != temp_w && (*game)->cfg->h_img != temp_h)
		ft_error_free_all_exit(*game, ERR_TEX_DIF_SIZE, true, 3);
}
