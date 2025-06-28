/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:17:06 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/06/28 17:21:27 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_atoi_pos(const char *ptr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if(ft_strlen(ptr) == 0)
		return (-1);
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (-1);
		res *= 10;
		res += (ptr[i] - '0');
		i++;
	}
	return (res);
}
