/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_del.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:48:53 by thaley            #+#    #+#             */
/*   Updated: 2019/02/24 17:24:29 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# include <stdio.h> //

typedef struct		s_fillit
{
	char			**map;
    int	            **coord;
	char			abc;
}					t_fillit;

int read_main(char *file, int *kolvo);
int check_last(char *buf);
int check_not_last_buf(char *buf);

t_fillit **write_main(char *file, int kolvo);

void offset(t_fillit *feel_it);

#endif