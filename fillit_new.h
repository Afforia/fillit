/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_new.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:48:53 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 15:02:42 by thaley           ###   ########.fr       */
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
}				t_map;

typedef struct	s_point
{
	int		x;
	int		y;
}
				t_point;

int			count_tetrimo(char *argv);
int			check_not_last(char *buf);
int			check_last(char *buf);
t_fillit	**write_from_buf(char *argv, int count);
t_fillit	*new_fillit();
void		write_figure(char *buf, char **tetrimo);
void		offset(char **tetrimo);
int			find_x(char **tetrimo);
int			find_y(char **tetrimo);
void		find_tet_area(t_fillit **fillit, int count);
int			find_width(char **tetrimo);
int			find_height(char **tetrimo);
t_map		*new_map(int count);
void		hollow_map(t_map *map);
int			backtrack(t_fillit **fillit, t_map *map);

#endif