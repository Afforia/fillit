/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:34:14 by thaley            #+#    #+#             */
/*   Updated: 2019/02/20 21:04:40 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	fd = 1;
	if (argc != 2)	// продумать лучше usage
	{
		ft_putstr("usage: fillt\n");
		return (1);
	}
	fillit = read_file(fd); // нужно что то нормальное туда передавать
	// while (fillit)
	// {
	// 	printf("%d || %d\n", fillit->width, fillit->height);
	// 	fillit = fillit->next;
	// }
	return(0);
}