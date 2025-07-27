/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:30:29 by t-costaf          #+#    #+#             */
/*   Updated: 2025/07/27 09:07:05 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include "./constants.h"
# include "colors.h"
# include "errors.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

/**
 * @brief 
 * @param data	 	2 dimension array with serialized map
 * @param raw_data	string with all '\n' that represents the map
 * @param p_x		initial player position X
 * @param p_y		initial player position Y
 */
typedef struct s_map
{
	char	**data;
	char	*raw_data;
	double	p_x;
	double	p_y;
	char	player_dir;
	int		w;
	int		h;
}	t_map;

/**
 * @brief	Image reference as in Minilibx documentation 
 * @param img	 		Img data from MLX
 * @param add	 		Img Pointer Address
 * @param bpp	 		Bits Per Pixel
 * @param line_len		Line length of the image
 * @param endian		A pointer to where the endian is written;
 */
typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/**
 * @brief Color Structure
 * @param r	 	Red value
 * @param g	 	Green value
 * @param b	 	Blue value
 * @param color	Color int value to be used in MLX
 */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

/**
 * @brief 
 * @param *_fil	 		Texture file
 * @param *_img	 		Texture image from MLX
 * @param hw_img	 	Width or Height of NO image loaded from MLX
 * @param strc	 		Color String representation as in the .cub file
 * @param strf			Color String representation as in the .cub file
 * @param dup_val		Is there a duplicate value?
 * @param valid			Is cfg valid?
 * @param started_map	Started the parser to read map?
 * @param ended_map		Ended reading map? (to check if there is
 * 						something after it)
 */
typedef struct s_cfg
{
	char	*no_fil;
	char	*so_fil;
	char	*we_fil;
	char	*ea_fil;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		h_img;
	int		w_img;
	t_color	*f;
	t_color	*c;
	char	*strc;
	char	*strf;
	bool	dup_val;
	bool	valid;
	bool	started_map;
	bool	ended_map;
}	t_cfg;

/**
 * @brief Check if key is pressed or not
 * @param	any		Any param holds true if key is pressed, false otherwise
 * 
 */
typedef struct s_keys
{
	bool	esc;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	w;
	bool	a;
	bool	s;
	bool	d;
}	t_keys;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double		plane_x;
	double		plane_y;
	char		dir;
}	t_player;

typedef struct s_raycast
{
	int			map_x;
	int			map_y;
	double		cam_x;
	double		dir_x;
	double		dir_y;
	int			step_x;
	int			step_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			wall_side;
	double		wall_x;
	double		wall_y;
	double		perpwalldist;
	int			start;
	int			end;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}	t_raycast;

typedef struct s_game
{
	t_map		*map;
	t_cfg		*cfg;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_keys		*k;
	t_player	*p;
	t_raycast	*rc;
}	t_game;

/* Setup */
void	ft_create_setup(char *file, t_game *game);

/* Helpers: Outputter Functions */
void	ft_display_error(char *msg);
int		ft_throw_error(char *msg, int code);
void	ft_print_game(t_game **game);
void	ft_display_msg(char *msg);

/* Cleaners */
void	ft_error_free_all_exit(t_game *game, char *msg, bool mode, int code);
void	ft_free_game(t_game **game);
void	ft_safe_free(void *ptr);
void	ft_free_strs(char **strs);
int		ft_handle_exit(t_game *game);

/* Parser */
void	ft_parse_cfg(char *line, t_game *game);
void	ft_parse_map(char *line, t_game *game);
void	ft_load_texture(char *file, void **img, t_game *game, void *mlx);

/* Validator */
bool	ft_check_map(t_game *game);
bool	ft_check_map_enclosed(t_game *game);

/* Utils */
int		ft_atoi_pos(const char *ptr);
void	ft_draw_pixel(t_img *img, int x, int y, int color);

/* Game Engine */
void	ft_init_game(t_game *game);
void	ft_run_game(t_game *game);
void	ft_handle_keys(t_game *game);
int		ft_key_press(int key_code, t_game *g);
int		ft_key_release(int key_code, t_game *game);

/* Render */
int			ft_render(t_game *game);
void		ft_rc_reset(t_game *game, t_raycast *rc);
void		ft_pick_wall(t_game *game, t_raycast *rc);
void		ft_pick_texture(t_game *game, t_raycast *rc);
void		ft_draw_image(t_game *game, t_raycast *rc);
void		draw_column(t_game *g, int x);

#endif
