/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:16:27 by thaley            #+#    #+#             */
/*   Updated: 2019/03/03 18:48:59 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		solution(t_fillit **fillit, t_map *map)
{
	int		i;
	// t_map *tet;
	// tet = NULL;

	i = 0;
	// tet = new_map(4);
	// hollow_map(tet);
	// backtrack(fillit, map, i);
	while (i < 3)
	{
		place_tetrimo(fillit[i]->left_up_corner, &map->map, 0, 0, fillit[i]->width, fillit[i]->height);
		i++;
	}
	i = 0 ;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	return (0);
}

/*
** нужно чтобы он полноценно сохранял измененную временную карту, а не перезаписывал ее
** пока не перепробует все фигуры -> потом только обнулит и заново
** продумать эти условия !!!
*/

// int		backtrack(t_fillit **fillit, t_map *map, int i)
// {
// 	int		x; //может х и у тоже должны передаваться?
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	while (y < (map->side - fillit[i]->height + 1))
// 	{
// 		while (x < (map->side - fillit[i]->width + 1))
// 		{
// 			if (place_tetrimo(fillit[i]->left_up_corner, map->map, x, y)) //vozmozhno karta c &
// 				return (1);
// 			else
// 			{
// 				backtrack(fillit, map, i);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }
