/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:57:19 by thaley            #+#    #+#             */
/*   Updated: 2019/03/06 19:36:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h" 

# include <stdio.h> //DONT FORGET REMOVE!

/*
** read_write.c
*/
int		read_buf(char *argv);

#endif