/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:30:29 by t-costaf          #+#    #+#             */
/*   Updated: 2025/06/29 11:29:53 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>

# include "colors.h"
# include "errors.h"

typedef struct s_map
{
	char	**data;
	char	*raw_data;
	int		p_x;
	int		p_y;
	char	player_dir;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_cfg
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	*f;
	t_color	*c;
	char	*strc;
	char	*strf;
	bool	dup_val;
	bool	valid;
	bool	started_map;
	bool	ended_map;
}	t_cfg;

typedef struct s_game
{
	t_map		*map;
	t_cfg		*cfg;
	void		*mlx;
	void		*win;
}	t_game;

/* Setup */
void	ft_create_setup(char *file, t_game *game);

/* Helpers: Outputter Functions */
void	ft_display_error(char *msg);
int		ft_throw_error(char *msg, int code);
void	ft_print_game(t_game **game);

/* Cleaners */
void	ft_error_free_all_exit(t_game *game, char *msg, bool mode, int code);
void	ft_free_game(t_game **game);
void	ft_safe_free(void *ptr);
void	ft_free_strs(char **strs);

/* Parser */
void	ft_parse_cfg(char *line, t_game *game);
void	ft_parse_map(char *line, t_game *game);

/* Validator */
bool	ft_check_texture(char *file, void* mlx);
bool	ft_check_map(t_game *game);

/* Utils */
int	ft_atoi_pos(const char *ptr);
int	ft_print_strs(char **strs);

/*
int		ft_open_file(char *filename);
int		ft_count_tabs(char *line);
void	ft_expand_tabs(char *src, char *dest);
char	*ft_replace_tabs(char *line);
t_list	*ft_read_file_list(int fd);
void	ft_free_list(t_list *list);
void	ft_print_list(t_list *list);
int		main(int argc, char **argv); */

/* parse_config.c */
/* int		ft_parse_config(t_list *file_lines, t_cfg *config);
int		ft_parse_texture(char *line, char **texture);
int		ft_parse_color(char *line, int *color);
int		ft_rgb_to_int(int r, int g, int b);
void	ft_free_config(t_cfg *config); */

/* validate_config.c */
/* int		ft_validate_config(t_cfg *config);
int		ft_validate_map_presence(t_list *file_lines);
int		ft_validate_player_position(t_cfg *config);
void	ft_free_split(char **split); */

/* extract_map.c */
/* int		ft_extract_map(t_list *file_lines, t_cfg *config);
int		ft_count_map_lines(t_list *file_lines);
char	**ft_copy_map(t_list *file_lines, int start_line, int map_height); */

#endif