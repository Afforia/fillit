/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:43:58 by thaley            #+#    #+#             */
/*   Updated: 2019/03/13 13:42:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sol_map(t_fillit **fillit, int count) //here need to return map
{
	t_map	*map;
	int		side;
	int		i;

	side = 2;
	i = 0;
	while (side * side < count * 4) // вычисляет минимальный размер карты
		side++;
	map = new_map(side); //создает новую карту
	while (!(check_tet(fillit, map, count, i)))//пока возвращает 0 в итоге а не 1
	{
		i = 0;
		side++; //увеличивает размер карты
		free_map(map);
		map = new_map(side);
	}
	int k = 0;
	while (map->map[k])
	{
		printf("%s\n", map->map[k]); // это все просто выводит результат
		k++;
	}
	printf("\n\n");
}

int		check_tet(t_fillit **fillit, t_map *map, int count, int i)
{
	int y;
	int x; //без доп переменных для карты сегфолтится
	
	if (fillit[i] == NULL) //если длшел до последней вернуть все ок
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
				else // удаляет тетримо после которой не смог поставить
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

/*
** проверяет можно ли поместить на карту
** если можно х и у приравнивает к интам в структуре карты
** и печатает
** если нет врозвращает 0
*/

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

/*
** печатает фигурку на карту или убирает фигурку
** для этого и передаю char content
** в конце обнуляет х и у в структуре карты
*/

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