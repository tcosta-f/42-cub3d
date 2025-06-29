/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:18:38 by alm               #+#    #+#             */
/*   Updated: 2025/06/29 21:41:58 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Display an error accordingly to the PDF
 * 
 * @param msg 	Message to display. Check errors.h to see possible messages
 */
void	ft_display_error(char *msg)
{
	ft_printf(RD"Error\n"RST"%s\n", msg);
}
