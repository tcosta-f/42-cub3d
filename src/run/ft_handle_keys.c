/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:45:31 by alm               #+#    #+#             */
/*   Updated: 2025/07/26 11:47:34 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_key_press(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		game->k->esc = true;
	else if (key_code == XK_CW || key_code == XK_SW)
		game->k->w = true;
	else if (key_code == XK_CA || key_code == XK_SA)
		game->k->a = true;
	else if (key_code == XK_CS || key_code == XK_SS)
		game->k->s = true;
	else if (key_code == XK_CD || key_code == XK_SD)
		game->k->d = true;
	else if (key_code == XK_LEFT)
		game->k->left = true;
	else if (key_code == XK_UP)
		game->k->up = true;
	else if (key_code == XK_RIGHT)
		game->k->right = true;
	else if (key_code == XK_DOWN)
		game->k->down = true;
	return (0);
}

static void	ft_player_move(t_game *g, double next_x, double next_y, char sign)
{
	if (sign == '+')
	{
		if (g->map->data[(int)g->p->pos_y][(int)(g->p->pos_x + next_x)] != '1')
			g->p->pos_x += next_x;
		if (g->map->data[(int)(g->p->pos_y + next_y)][(int)g->p->pos_x] != '1')
			g->p->pos_y += next_y;
	}
	else if (sign == '-')
	{
		if (g->map->data[(int)g->p->pos_y][(int)(g->p->pos_x - next_x)] != '1')
			g->p->pos_x -= next_x;
		if (g->map->data[(int)(g->p->pos_y - next_y)][(int)(g->p->pos_x)] != '1')
			g->p->pos_y -= next_y;
	}
}

static void	ft_player_turn(t_game *g, double rot_spd)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = g->p->dir_x;
	tmp_plane_x = g->p->plane_x;
	g->p->dir_x = g->p->dir_x * cos(rot_spd) - g->p->dir_y * sin(rot_spd);
	g->p->dir_y = tmp_dir_x * sin(rot_spd) + g->p->dir_y * cos(rot_spd);
	g->p->plane_x = g->p->plane_x * cos(rot_spd) - g->p->plane_y * sin(rot_spd);
	g->p->plane_y = tmp_plane_x * sin(rot_spd) + g->p->plane_y * cos(rot_spd);
}

int		ft_key_release(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		game->k->esc = false;
	else if (key_code == XK_CW || key_code == XK_SW)
		game->k->w = false;
	else if (key_code == XK_CA || key_code == XK_SA)
		game->k->a = false;
	else if (key_code == XK_CS || key_code == XK_SS)
		game->k->s = false;
	else if (key_code == XK_CD || key_code == XK_SD)
		game->k->d = false;
	else if (key_code == XK_LEFT)
		game->k->left = false;
	else if (key_code == XK_UP)
		game->k->up = false;
	else if (key_code == XK_RIGHT)
		game->k->right = false;
	else if (key_code == XK_DOWN)
		game->k->down = false;
	return (0);
}

void	ft_handle_keys(t_game *g) {
	if (g->k->esc == true)
		ft_handle_exit(g);
	if (g->k->up || g->k->w)
		ft_player_move(g, g->p->dir_x * L_SPD, g->p->dir_y * L_SPD, '+');
	if (g->k->down || g->k->s)
		ft_player_move(g, g->p->dir_x * L_SPD, g->p->dir_y * L_SPD, '-');
	if (g->k->a)
		ft_player_move(g, g->p->plane_x * L_SPD, g->p->plane_y * L_SPD, '-');
	if (g->k->d)
		ft_player_move(g, g->p->plane_x * L_SPD, g->p->plane_y * L_SPD, '+');
	if ((g->k->left && (g->p->dir == 'N' || g->p->dir == 'S')) || (g->k->right && (g->p->dir == 'E' || g->p->dir == 'W')))
		ft_player_turn(g, -A_SPD);
	if ((g->k->left && (g->p->dir == 'E' || g->p->dir == 'W')) || (g->k->right && (g->p->dir == 'N' || g->p->dir == 'S')))
		ft_player_turn(g, A_SPD);
}