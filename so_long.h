/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:47:28 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 01:45:16 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// gnl
# include <stdio.h> // remove_it
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
// bool
# define TRUE 0
# define FALSE 1

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

// parsing
void	parsing(char *av);
int		check_filename(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// error handling
void	print_err(char *s);

#endif