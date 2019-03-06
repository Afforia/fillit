/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:18:17 by thaley            #+#    #+#             */
/*   Updated: 2019/03/06 18:31:54 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"
/*
** работает только последовательно
** не подставляет другие вариации тетримо
*/
int		solution(t_fillit **fillit, t_map *map)
{
	int		i;
	char	**tmp;
	int j;

	tmp = NULL;
	i = 0;
	while (i < 4)
	{
		map->y = 0;
		while (map->y < map->side)
		{
			map->x = 0;
			while (map->x < map->side)
			{
				if (check_it(fillit[i], map))
				{
					tmp = print_tet(fillit[i], map);
					if (i < 1)
						i++;
					else
					{
						j = 0;
						while (map->map[j])
						{
							printf("%s\n", map->map[j]);
							j++;
						}
						return (0);
					}
					map->x = 0;
					map->y = 0;
					continue;
				}
				map->x++;
			}
			map->y++;
		}
		i++;
	}
	j = 0;
	while (map->map[j])
	{
		printf("%s\n", map->map[j]);
		j++;
	}
	return (0);
}

int		check_it(t_fillit *fillit, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[map->y + i])
	{
		j = 0;
		while (map->map[map->x + j])
		{
			if (fillit->left_up_corner[i][j] == '#' &&
			map->map[map->y + i][map->x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	if (j < fillit->width || i < fillit->height)
		return (0);
	return (1);
	}

	char	**print_tet(t_fillit *fillit, t_map *map)
	{
		int		i;
		int		j;
		
		i = 0;
		while (i < fillit->height)
		{
			j = 0;
			while (j < fillit->width)
			{
				if (fillit->left_up_corner[i][j] == '#')
					map->map[map->y + i][map->x + j] = fillit->content;
				j++;
			}
			i++;
		}
		return (map->map);
	}
