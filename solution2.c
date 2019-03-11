/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:41:36 by thaley            #+#    #+#             */
/*   Updated: 2019/03/11 20:20:12 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** просто последовательно печатает все фигурки
** если фигурки не помещаются увелисивает карту
*/

void	sol_map(t_fillit **fillit, int count)
{
	t_map	*map;
	int		side;

	side = 2;
	while (side * side < count * 4)
		side++;
	map = new_map(side);
	if (check_tet(fillit, &map, count))
	{
		int k = 0;
		while (map->map[k])
		{
			printf("%s\n", map->map[k]);
			k++;
		}
	}
}

int		check_tet(t_fillit **fillit, t_map **map, int count)
{
	int		i;

	i = 0;
	(*map)->y = 0;
	while (i < count && (*map)->y < (*map)->side - fillit[i]->height + 1)
	{
		(*map)->x = 0;
		while ((*map)->x < (*map)->side - fillit[i]->width + 1)
		{
			if ((place_on_map(fillit[i], map)))
			{
				print_tet(fillit[i], map);
				i++;
				(*map)->y = -1;
				break;
			}
			else if ((*map)->x == ((*map)->side - 1) - fillit[i]->width &&
				(*map)->y == ((*map)->side - 1) - fillit[i]->height)
			{
				*map = new_map((*map)->side + 1);
				i = 0;
				(*map)->y = -1;
				break;
			}
			(*map)->x++;
		}
		(*map)->y++;
	}
	return (1);
}

int		place_on_map(t_fillit *fillit, t_map **map)
{
	int i;
	int	j;

	i = 0;
	while ((*map)->y + i < (*map)->side && fillit->tetrimo[i])
	{
		j = 0;
		while ((*map)->x + j < (*map)->side && fillit->tetrimo[i][j])
		{
			if (fillit->tetrimo[i][j] == '#' &&
			(*map)->map[(*map)->y + i][(*map)->x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		print_tet(t_fillit *fillit, t_map **map)
{
	int i;
	int j;

	i = 0;
	while (i < fillit->height && (*map)->map[(*map)->y + i])
	{
		j = 0;
		while (j < fillit->width && (*map)->map[(*map)->y + i][(*map)->x + j])
		{
			if (fillit->tetrimo[i][j] == '#')
				(*map)->map[(*map)->y + i][(*map)->x + j] = fillit->content;
			j++;
		}
		i++;
	}
	return (0);
}