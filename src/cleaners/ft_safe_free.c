/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:12 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 21:37:39 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Safely frees something. Prevent "double free"
 * 
 * @param ptr Pointer to be checked and freed
 */
void	ft_safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
