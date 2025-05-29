/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:10:44 by bschwell          #+#    #+#             */
/*   Updated: 2025/05/29 16:10:55 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_strs(char **strs)
{
	int i;

	i = -1;
	if (strs)
		while (strs[++i])
			ft_safe_free(strs[i]);
	ft_safe_free(strs);
}