/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:48:53 by thaley            #+#    #+#             */
/*   Updated: 2019/02/19 21:40:34 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# define BUFF_SIZE 21
// # include "gnl/get_next_line.h"

typedef struct	s_fillit
{
	char			content;
	int				width;
	int				height;
	int				count;
	struct s_fillit	*next;
}				t_fillit;

typedef struct	s_point
{
	int		x;
	int		y;
}
				t_point;
t_fillit		*read_file(int fd);
char			**find_map(int area);
t_point 		*makepoint(int x, int y);
int 			read_main(char *buf, int fd);
int check_not_last_buf(char *buf);
int check_last(char *buf);

#endif