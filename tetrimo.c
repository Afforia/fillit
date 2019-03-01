/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:16:27 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 20:07:58 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		solution(t_fillit **fillit, t_map *map)
{
	int		i;
	t_sol_tet *tet;
	tet = NULL;

	i = 0;
	tet = new_struct(map);
	backtrack(fillit, map, i, &tet);
	return (0);
}

/*
** нужно чтобы он полноценно сохранял измененную временную карту, а не перезаписывал ее
** пока не перепробует все фигуры -> потом только обнулит и заново
** продумать эти условия !!!
*/

int		place_tetrimo(t_fillit **fillit, t_map *map, int i, t_sol_tet **tet)
{
	int		m; //first index
	int		n; //second index

	m = 0;
	n = 0;
	(*tet)->tet = map->map;
	while ((*tet)->y < map->side && fillit[i]->left_up_corner[m])
	{
		(*tet)->x = 0;
		n = 0;
		while ((*tet)->x < map->side && fillit[i]->left_up_corner[m][n])
		{
			if ((*tet)->tet[(*tet)->y][(*tet)->x] == '.' && fillit[i]->left_up_corner[m][n] == '#')
			{
				(*tet)->tet[(*tet)->y][(*tet)->x] = '#';
				n++;
				(*tet)->x++;
			}
			else if ((*tet)->tet[(*tet)->y][(*tet)->x] == '.' && fillit[i]->left_up_corner[m][n] == '.')
			{
				(*tet)->x++;
				n++;
			}
			else if ((*tet)->tet[(*tet)->y][(*tet)->x] == '#' && fillit[i]->left_up_corner[m][n] == '#')
			{
				(*tet)->x = 1;
				m = 0;
				n = 0;
				continue;
			}
			else
			{
				n++;
				(*tet)->x++;
			}
		}
		(*tet)->y++;
		m++;
	}
	map->map = (*tet)->tet;
	free((*tet)->tet);
	if (i == 3)
		return (1);
	return (0);
}

int		backtrack(t_fillit **fillit, t_map *map, int i, t_sol_tet **tet)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (i < 4 && (y < (map->area - fillit[i]->height + 1)))
	{
		while (i < 4 && (x < (map->area - fillit[i]->width + 1)))
		{
			if (place_tetrimo(fillit, map, i, tet))
				return (1);
			else
			{
				i++;
				backtrack(fillit, map, i, tet);
			}
			x++;
		}
		y++;
	}
	return (0);
}