/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_new.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:48:53 by thaley            #+#    #+#             */
/*   Updated: 2019/03/03 17:36:34 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_NEW_H
# define FILLIT_NEW_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# include <stdio.h> //DONT FORGET REMOVE!
# define BUFF_SIZE 21
// # include "gnl/get_next_line.h"

typedef struct	s_fillit
{
	char			**left_up_corner;
	// int				**coord;
//	char			*tetriski;// - сосиски! ХА-Ха-ха...
//	char			content; //это харанит хештег (то чем мы аля заполняем)
	int				width; // ширин фигурки (известна так же под именем мистер Х)
	int				height; // жена ширины - высота фигурки (именуемая У)
//	int				count; //счетчик/№ тетриминошек || возможно вообще ненужная тут фигня
//	struct s_fillit	*next; //ну и указатель без него никуда || ему бы брата который назад любит ходить
}				t_fillit;

typedef struct	s_map
{
	char	**map;
	int		area;
	int		side;
	
	int		x;
	int		y;
}				t_map;

typedef struct	s_sol_tet
{
	char	**tet;
	int		x;
	int		y;
}
				t_sol_tet;

/*
** in = checker.c || from = read_write.c
*/

int			check_not_last(char *buf); // count_tetrimo
int			check_last(char *buf); // count_tetrimo

/*
** in = read_write.c || from = new.c(main)
*/

int			count_tetrimo(char *argv); //main
t_fillit	**write_from_buf(char *argv, int count); // main
void		write_figure(char *buf, char **tetrimo); // write_from_buf
void		offset(char **tetrimo); //write_from_buf

/*
** in = find_point.c || from = read_write.c new.c(main) 
*/

int			find_x(char **tetrimo); //offset
int			find_y(char **tetrimo); //offset
int			find_width(char **tetrimo); // find_tet_area
int			find_height(char **tetrimo); //find_tet_area
t_map		*find_tet_area(t_fillit **fillit, int count); //main

/*
** in = mal_free.c || from = read_write.c find_points.c tetrimo.c
*/

t_fillit	*new_fillit(); // write_from_buf
t_map		*new_map(int count); // find_tet_area
t_sol_tet	*new_struct(t_map *map); // 

/*
** in = map.c || from = find_points
*/

void		hollow_map(t_map *map); // find_tet_area

/*   	
**	in = tetrimo.c || from = main.c	
*/

int			solution(t_fillit **fillit, t_map *map); // main
int			backtrack(t_fillit **fillit, t_map *map, int i); // solution
// int			place_tetrimo(t_fillit **fillit, t_map *map, int i, t_map **tet); // backtrack

/*
** in = place_tetrimo.c ||  tetrimo.c
*/

int		place_tetrimo(char	**tetrimo, char ***map, int x, int y, int width, int height);//backtrack
int		check_it(char **tetrimo, char **map, int x, int y, int width, int height); //place_tetrimo
char	**print_tet(char **tetrimo, char **temp, int x, int y, int width, int height); // place_tetrimo

#endif