/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:57:19 by thaley            #+#    #+#             */
/*   Updated: 2019/03/10 18:12:49 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h" 

# include <stdio.h> //DONT FORGET REMOVE!

typedef	struct	s_fillit
{
	char	**tetrimo;
	char	content;
	int		height;
	int		width;
}				t_fillit;

typedef struct	s_map
{
	char	**map;
	int		side;
	int		x;
	int		y;
}				t_map;

/*
** main.c
*/

int			count_tet(char *argv);

/*
** check.c
*/

int			check_buf(char *buf, int ret); //объединить проверки в 1 файл

/*
** check_shape.c || Adel's check
*/

int		check_shape(t_fillit **feel_it);
void	free_arr(void **mass);
int		check_count(char **map);
int		find_count(char **map, int i, int j);

/*
** read_write.c
*/

t_fillit	**write_buf(char *argv, int count);
void		write_tet(char *buf, char	**tetrimo);
void		offset(char **tetrimo);
char		*dot_string(int side);		

/*
** mal_free.c
*/

t_fillit	*new_fillit(int i);
t_map		*new_map(int side);
int			free_map(t_map *map);

/*
** coordinates.c
*/

int			find_x(char **tetrimo);
int			find_y(char **tetrimo);
int			height(char **tetrimo);
int			width(char **tetrimo);

/*
** solution.c
*/

void		sol_map(t_fillit **fillit, int count);
int			place_tet(t_fillit **fillit, t_map **map, int count);
int			check_tet(t_fillit **fillit, t_map *map, int count, int num);
int			place_on_map(t_fillit *fillit, t_map *map);
int			print_tet(t_fillit *fillit, t_map **map);

#endif