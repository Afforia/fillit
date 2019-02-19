/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:34:14 by thaley            #+#    #+#             */
/*   Updated: 2019/02/19 20:38:24 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft/libft.h"

/*
** подумать над тем чтобы сделать в листах двойной массив
** 1 лист - 1 фигура
** backtracking
** FREEEEEEE!!!! DON'T FORGET!!!!!
*/

int		main(int argc, char **argv)
{
	int			fd;
	// int			ret;
	t_fillit	*fillit; // сюды клади фигуры

	if (argc != 2)	// продумать лучше usage
	{
		ft_putstr("usage: fillt\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fillit = read_file(fd);
	// while (fillit)
	// {
	// 	printf("%d || %d\n", fillit->width, fillit->height);
	// 	fillit = fillit->next;
	// }
	return(0);
}