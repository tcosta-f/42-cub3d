/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:45:31 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 17:27:28 by alm              ###   ########.fr       */
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

static void	ft_player_move(t_game *game, double new_x, double new_y)
{
	int	x_forward;
	int	y_forward;

	x_forward = (int)(game->p->x + (new_x * 8) * DIFF_MV);
	y_forward = (int)(game->p->y + (new_y * 8) * DIFF_MV);
	if (game->map->data[(int)game->p->y][x_forward] != '1')
	{
		game->p->x += new_x * DIFF_MV;
		game->p->col_x = x_forward * (WIN_W / game->map->w);
	}
	if (game->map->data[y_forward][(int)game->p->x] != '1')
	{
		game->p->y += new_y * DIFF_MV;
		game->p->col_y = y_forward * (WIN_H / game->map->h);
	}
}

static void	ft_player_turn(t_game *game, char dir)
{
	if (dir == 'L')
		game->p->ang -= DIFF_RT + (game->p->ang < 0) * (2 * PI);
	else
		game->p->ang += DIFF_RT - (game->p->ang > 2) * (2 * PI);
	if (game->p->ang < 0)
		game->p->ang += 2 * PI;
	if (game->p->ang > 2 * PI)
		game->p->ang -= 2 * PI;
	game->p->dx = cos (game->p->ang);
	game->p->dy = sin (game->p->ang);
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

void	ft_handle_keys(t_game *game) {
	if (game->k->esc == true)
		ft_handle_exit(game);
	if (game->k->up || game->k->w)
		ft_player_move(game, game->p->dx * DIFF_MV, game->p->dy * DIFF_MV);
	if (game->k->down || game->k->s)
		ft_player_move(game, game->p->dx * DIFF_MV, game->p->dy * DIFF_MV);
	if (game->k->a)
		ft_player_move(game, game->p->dy * DIFF_MV, game->p->dx * DIFF_MV);
	if (game->k->d)
		ft_player_move(game, game->p->dy * DIFF_MV, game->p->dx * DIFF_MV);
	if (game->k->left)
		ft_player_turn(game, 'L');
	if (game->k->right)
		ft_player_turn(game, 'R');
}