/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwell <bschwell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:18:23 by bschwell          #+#    #+#             */
/*   Updated: 2025/05/29 16:46:12 by bschwell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <sysexits.h>

/**
 * @brief Error Codes:
 * C error codes:
 * https://manpages.ubuntu.com/manpages/noble/man3/sysexits.h.3head.html
 * Bash Standard Errors: https://tldp.org/LDP/abs/html/exitcodes.html
 */

/* Bash Standard Errors */
# define EX_OK				0
# define EX_GENERICERR		1
# define EX_BUILTINERR		2
# define EX_EXECERR			126
# define EX_NOTFOUNDERR		127
# define EX_EXITARGERR		128
# define EX_OUTOFRANGEERR	255

/* Error Messages */

/* Parser errors */
# define ERR_WRNG_ARG_SIZ   "Usage: ./cub3D <map.cub>"
# define ERR_MISSING_CONF   "Missing configuration data"
# define ERR_MEMORY_ALLOC   "Memory allocation error"
# define ERR_FIL_EXTENSIO   "Invalid file extension. Must be .cub"
# define ERR_CANNOT_RD_FL   "Invalid .cub file"
# define ERR_SYNTAX_ERROR	"Sintax error in color definition"
# define ERR_INVALID_CHAR	"Invalid or mixed characters"
# define ERR_MAP_NOT_CLOS	"Map is not enclosed by wall"
# define ERR_STARTING_POS	"Multiple starting positions or none at all"
# define ERR_ELEMNT_ORDER	"Elements in wrong order"
# define ERR_DUPL_DFNTION	"Duplicate definition in file"
# define ERR_EXT_LINES_MP	"Extra lines after the map"

#endif /* ERRORS_H */
