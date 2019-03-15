/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:43:58 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 17:12:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sol_map(t_fillit **fillit, int count)
{
	t_map	*map;
	int		side;
	int		i;

	side = 2;
	i = 0;
	while (side * side < count * 4)
		side++;
	map = new_map(side);
	while (!(check_tet(fillit, map, count, i)))
	{
		i = 0;
		side++;
		free_map(map);
		map = new_map(side);
	}
	int k = 0;
	while (k < 4)
	{
		printf("%s\n", map->map[k]);
		k++;
	}
}

int		check_tet(t_fillit **fillit, t_map *map, int count, int i)
{
	int y;
	int x;
	
	if (fillit[i] == NULL)
		return (1);
	y = 0;
	while (i < count && (y < map->side - fillit[i]->height + 1))
	{
		x = 0;
		while (x < map->side - fillit[i]->width + 1)
		{
			if (place_on_map(fillit[i], map, y, x))
			{
				if (check_tet(fillit, map, count, ++i))
				{
					return (1);
				}
				else
				{
					i = i - 1;
					map->y = y;
					map->x = x;
					print_tet(fillit[i], map, '.');
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		place_on_map(t_fillit *fillit, t_map *map, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < fillit->height)
	{
		j = 0;
		while (j < fillit->width)
		{
			if (fillit->tetrimo[i][j] == '#' &&
				map->map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	map->y = y;
	map->x = x;
	print_tet(fillit, map, fillit->content);
	return (1);
}

void	print_tet(t_fillit *fillit, t_map *map, char content)
{
	int	i;
	int	j;

	i = 0;
	while (i < fillit->height)
	{
		j = 0;
		while (j < fillit->width)
		{
			if (fillit->tetrimo[i][j] == '#')
				map->map[map->y + i][map->x + j] = content;
			j++;
		}
		i++;
	}
	map->y = 0;
	map->x = 0;
}