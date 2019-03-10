/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:49:30 by thaley            #+#    #+#             */
/*   Updated: 2019/03/10 18:34:01 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** неправильно выводит, скорее всего неправильно работает все, а не только вывод
*/
void	sol_map(t_fillit **fillit, int count)
{
	t_map	*map;
	int		side;

	side = 2;
	while (side * side < count * 4)
		side++;
	map = new_map(side);
	if (place_tet(fillit, &map, count))
	{
		int k = 0;
		while (map->map[k])
		{
			printf("%s\n", map->map[k]);
			k++;
		}
	}
}

int		place_tet(t_fillit **fillit, t_map **map, int count) //26 str
{
	int		i;

	i = 0;

	check_tet(fillit, *map, count, i);
	return (1);
}

int		check_tet(t_fillit **fillit, t_map *map, int count, int num)
{
	int		check;

	check = num;
	while (num < count && map->y < map->side - fillit[num]->height + 1)
	{
		map->x = 0;
		while (map->x < map->side - fillit[num]->width + 1)
		{
			if ((place_on_map(fillit[num], map)))
			{
				if (check_tet(fillit, map, count, num + 1))
					return (1);
				else
					print_tet(fillit[num], &map);
			}
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int		place_on_map(t_fillit *fillit, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->y + i < map->side && fillit->tetrimo[i])
	{
		j = 0;
		while (map->x + j < map->side && fillit->tetrimo[i][j])
		{
			if (fillit->tetrimo[i][j] == '#' && map->map[map->y + i][map->x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		print_tet(t_fillit *fillit, t_map **map)
{
	int		i;
	int		j;
	int		side;

	side = (*map)->side;
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