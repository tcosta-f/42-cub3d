/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:10:44 by bschwell          #+#    #+#             */
/*   Updated: 2025/06/29 21:36:48 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Safely free array of strings
 * 
 * @param strs 	array to be freed
 */
void	ft_free_strs(char **strs)
{
	int	i;

	i = -1;
	if (strs)
		while (strs[++i])
			ft_safe_free(strs[i]);
	ft_safe_free(strs);
}
