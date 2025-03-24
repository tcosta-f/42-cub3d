/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:30:29 by tcosta-f          #+#    #+#             */
/*   Updated: 2025/03/21 01:35:03 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_config
{
	char	*tex_north;
	char	*tex_south;
	char	*tex_west;
	char	*tex_east;
	int		floor_color;
	int		ceiling_color;
	int		player_x;
	int		player_y;
	char	player_dir;
	char	**map;
}	t_config;

/* parse.c */
int		ft_check_file_extension(char *filename);
int		ft_open_file(char *filename);
int		ft_count_tabs(char *line);
void	ft_expand_tabs(char *src, char *dest);
char	*ft_replace_tabs(char *line);
t_list	*ft_read_file_list(int fd);
void	ft_free_list(t_list *list);
void	ft_print_list(t_list *list);
int		main(int argc, char **argv);

/* parse_config.c */
int		ft_parse_config(t_list *file_lines, t_config *config);
int		ft_parse_texture(char *line, char **texture);
int		ft_parse_color(char *line, int *color);
int		ft_rgb_to_int(int r, int g, int b);
void	ft_free_config(t_config *config);

/* validate_config.c */
int		ft_validate_config(t_config *config);
int		ft_validate_map_presence(t_list *file_lines);
int		ft_validate_player_position(t_config *config);
void	ft_free_split(char **split);

/* extract_map.c */
int		ft_extract_map(t_list *file_lines, t_config *config);
int		ft_count_map_lines(t_list *file_lines);
char	**ft_copy_map(t_list *file_lines, int start_line, int map_height);

#endif