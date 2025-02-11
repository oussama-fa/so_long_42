/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:47:28 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/09 20:52:59 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../garbage/garbage.h"
# include "/home/oufarah/minilibx-linux/mlx.h"

// bool
# define TRUE 0
# define FALSE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_textures
{
	void	*wall;
	void	*space;
	void	*player;
	void	*collect;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	char		*join;
	int			coin;
	t_pos		player;
	t_textures	texture;
	void		*mlx;
	void		*mlx_win;
}	t_game;

// gnl utils :
char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

// parsing_map
int		check_line(char *s);
int		check_validity_map(char *s, t_game *so_long);
int		check_same_len(char **map, int rows);
int		check_walls(char **map, int rows, int cols);
int		is_map_valid(char **map, int rows);
// parsing_utils
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		check_filename(char *str);
// parsing_validty
void	flood_fill(char **map, int y, int x);
void	check_valid_path(char **map_cpy, int y, int x);
t_pos	get_player_pos(char **map);
// parsing
char	*skip_last(char *s);
int		checkline_validity(char *s);
char	*mini_pars(char *av);
char	**ft_split(char const *s, char c);
void	parsing(t_game *so_long, char *av);

// textures
void	set_height_width(t_game *so_long, char **map);
void	draw_map(t_game *so_long, char **map, int y, int x);
void	set_textures(t_game *so_long);
void	free_textures(t_game *game);
// moves
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void	move_player(t_game *game, int x, int y);
int		key_hook(int keycode, t_game *game);

// error handling
void	print_err(char *s);
int		dstroy(t_game *so_long);

#endif