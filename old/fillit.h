/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:48:53 by thaley            #+#    #+#             */
/*   Updated: 2019/02/24 13:17:29 by thaley           ###   ########.fr       */
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
# define BUFF_SIZE 21
// # include "gnl/get_next_line.h"

typedef struct	s_fillit
{
	char			**left_up_corner;
	char			*tetriski;// - сосиски! ХА-Ха-ха...
	char			content; //это харанит хештег (то чем мы аля заполняем)
	int				width; // ширин фигурки (известна так же под именем мистер Х)
	int				height; // жена ширины - высота фигурки (именуемая У)
	int				count; //счетчик/№ тетриминошек || возможно вообще ненужная тут фигня
	struct s_fillit	*next; //ну и указатель без него никуда || ему бы брата который назад любит ходить
}				t_fillit;

typedef struct	s_map
{
	char	**map;
	int		area;
}				t_map;

typedef struct	s_point
{
	int		x;
	int		y;
}
				t_point;

t_fillit	*new_list_fillit(int count);
char		**find_map(int area);
void	backtrack(t_fillit *tetrimo, int area);
t_point *makepoint(int x, int y);
int		solution(int count, char *buf);
int check_last(char *buf);
int check_not_last_buf(char *buf);
t_fillit		*read_buf(char *argv);
// void	write_coordinates(t_fillit *tetrimo);

#endif