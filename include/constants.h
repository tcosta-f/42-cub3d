/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:04:27 by alm               #+#    #+#             */
/*   Updated: 2025/07/26 10:55:56 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONSTS_H
# define CUB3D_CONSTS_H

/* Window */
# define WIN_TITLE "Cub3d"
# define WIN_W 800
# define WIN_H 600

/* KeySyms */
# define XK_ESCAPE		0xff1b  /* ESC */
# define XK_LEFT		0xff51  /* left arrow */
# define XK_UP			0xff52  /* up arrow */
# define XK_RIGHT		0xff53  /* right arrow */
# define XK_DOWN		0xff54  /* down arrow */
# define XK_KP_LEFT		0xff96  /* Keypad left arrow */
# define XK_KP_UP		0xff97  /* Keypad up arrow */
# define XK_KP_RIGHT	0xff98  /* Keypad right arrow */
# define XK_KP_DOWN		0xff99  /* Keypad down arrow */
# define XK_CA			0x0041  /* U+0041 LATIN CAPITAL LETTER A - left */
# define XK_CD			0x0044  /* U+0044 LATIN CAPITAL LETTER D - right */
# define XK_CS			0x0053  /* U+0053 LATIN CAPITAL LETTER S - down */
# define XK_CW			0x0057  /* U+0057 LATIN CAPITAL LETTER W - up */
# define XK_SA			0x0061  /* U+0061 LATIN SMALL LETTER A - left */
# define XK_SD			0x0064  /* U+0064 LATIN SMALL LETTER D - right */
# define XK_SS			0x0073  /* U+0073 LATIN SMALL LETTER S - down */
# define XK_SW			0x0077  /* U+0077 LATIN SMALL LETTER W - up */

/* Ray Casting */
# define PI 3.1415
# define DR 0.0174533 // 1 Degree Radian

# define MAX_DIST 1000000000
# define MAX_RAYS 400
# define FOV 60
# define WALL_H 700

# define PREC_DN 0.00001
# define PREC_UP 1

# define L_SPD 0.09 // Linear Speed
# define A_SPD 0.09 // Angular Speed
# define PLANE 0.66 // Plane Distance

#endif
