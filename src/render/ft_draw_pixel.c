/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:23:39 by alm               #+#    #+#             */
/*   Updated: 2025/07/25 17:57:34 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	unsigned char	*pixel;
	int				i;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	i = img -> bpp - 8;
	pixel = (unsigned char *)(img -> add + (y * img -> line_len \
	+ x * (img -> bpp / 8)));
	while (i >= 0)
	{
		if (img -> endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img -> bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
