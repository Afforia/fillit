/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:57:16 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 17:56:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sol_fillit(t_fillit **feel_it, int count)
{
	t_map	*map;
	int		side;
	int		i;

	side = 2;
	i = 0;
	while (side * side < count * 4)
		side++;
	map = new_map(side);
	while (!(backtrack(feel_it, map, i)))
	{
		i = 0;
		side++;
		free_arr(map->map);
		free(map);
		map = new_map(side);
	}
	print_map(map);
	free_fillit(feel_it);
}

int		backtrack(t_fillit **feel_it, t_map *map, int i)
{
	int y;
	int x;

	if (feel_it[i] == NULL)
		return (1);
	y = 0;
	while (y < map->side - feel_it[i]->height + 1)
	{
		x = 0;
		while (x < map->side - feel_it[i]->width + 1)
		{
			if (check_place(feel_it[i], map, y, x))
			{
				if (backtrack(feel_it, map, ++i))
					return (1);
				else
					print_tet(feel_it[--i], map, '.', (t_p){x, y});
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		check_place(t_fillit *feel_it, t_map *map, int y, int x)
{
	int	i;
	int	j;

	j = 0;
	while (j < feel_it->width)
	{
		i = 0;
		while (i < feel_it->height)
		{
			if (feel_it->tetrimo[i][j] == '#' &&
				map->map[y + i][x + j] != '.')
				return (0);
			i++;
		}
		j++;
	}
	print_tet(feel_it, map, feel_it->content, (t_p){x, y});
	return (1);
}

void	print_tet(t_fillit *feel_it, t_map *map, char cont, t_p point)
{
	int	i;
	int	j;

	i = 0;
	while (i < feel_it->height)
	{
		j = 0;
		while (j < feel_it->width)
		{
			if (feel_it->tetrimo[i][j] == '#')
				map->map[point.y + i][point.x + j] = cont;
			j++;
		}
		i++;
	}
	point.x = 0;
	point.y = 0;
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->side)
	{
		ft_putstr(map->map[i]);
		ft_putstr("\n");
		i++;
	}
	free_arr(map->map);
	free(map);
	map = NULL;
}
