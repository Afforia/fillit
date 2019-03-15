/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:57:19 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 18:38:20 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"

typedef	struct	s_fillit
{
	char		**tetrimo;
	char		content;
	int			height;
	int			width;
}				t_fillit;

typedef struct	s_map
{
	char		**map;
	int			side;
	int			x;
	int			y;
}				t_map;

typedef struct	s_p
{
	int			x;
	int			y;
}				t_p;

int				count_tet(char *argv);
t_fillit		**write_buf(char *argv, int count);
t_fillit		*write_tet(char *buf, int i);
void			offset(char **tetrimo);

int				check_buf(char *buf, int ret, int *end);
int				check_shape(t_fillit **feel_it);
int				check_in(char **tetrimo);
int				find_count(char **tetrimo, int i, int j);

t_fillit		*new_fillit(int i);
t_map			*new_map(int side);
char			*dot_string(int side);
void			free_arr(char **arr);
void			free_fillit(t_fillit **feel_it);

int				find_y(char **tetrimo);
int				find_x(char **tetrimo);
int				find_hgt(char **tetrimo);
int				find_wdt(char **tetrimo);

void			sol_fillit(t_fillit **feel_it, int count);
int				backtrack(t_fillit **feel_it, t_map *map, int i);
int				check_place(t_fillit *feel_it, t_map *map, int y, int x);
void			print_tet(t_fillit *feel_it, t_map *map, char cont, t_p point);
void			print_map(t_map *map);

#endif
