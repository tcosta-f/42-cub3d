/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:42:42 by bschwell          #+#    #+#             */
/*   Updated: 2025/06/29 09:08:46 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	ft_check_texture(char *file, void *mlx)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, file, &w, &h);
	if (!img || w <= 0 || h <= 0)
	{
		if (img)
			mlx_destroy_image(mlx, img);
		return (false);
	}
	if (img)
		mlx_destroy_image(mlx, img);
	return (true);
}
