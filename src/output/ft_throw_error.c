/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:49:17 by bschwell          #+#    #+#             */
/*   Updated: 2025/06/29 21:41:28 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Throws error if needed, with code
 * 
 * @param msg 	see errors.h to possible errors
 * @param code 	code to return and exit afterwards
 * @return int 
 */
int	ft_throw_error(char *msg, int code)
{
	ft_display_error(msg);
	return (code);
}
