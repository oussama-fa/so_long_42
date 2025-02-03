/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:47:28 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/03 01:39:05 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// gnl
# include <stdio.h> // remove_it
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "garbage/garbage.h"
// bool
# define TRUE 0
# define FALSE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pos{
	int	x;
	int	y;
}	t_pos;

typedef struct s_textures{
	void	*wall;
	void	*space;
	void	*player;
	void	*collect;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	char		**map;
	char		*join;
	t_pos		player;
	t_textures	*texture;
	void		*mlx;
}	t_game;

// gnl utils :
char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

// parsing_map
int		check_line(char *s);
int		check_validity_map(char *s);
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
void	parsing(char *av);

// error handling
void	print_err(char *s);

#endif