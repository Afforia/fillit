/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:06:57 by thaley            #+#    #+#             */
/*   Updated: 2019/03/03 19:32:22 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		place_tetrimo(char	**tetrimo, char ***map, int x, int y, int width, int height)
{
	int		i;
	int		j;
	char	**temp; //

	i = 0;
	j = 0;
	temp = *map; //нужно чтобы где то сохранялась карта ??
	while (y < 4 - height + 1)
	{
		j = 0;
		while (x < 4 - width + 1)
		{
			if (check_it(tetrimo, temp, x, y, width, height))
			{
				temp = print_tet(tetrimo, temp, x, y, width, height);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	*map = temp;
	return (0);
}
/*
** работает некорректно!!!
*/
int		check_it(char **tetrimo, char **map, int x, int y, int width, int height)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	temp = map;
	while (y + i <= 4 - height)
	{
		j = 0;
		while (j + x <= 4 - width) //4 = map->side
		{
			if ((tetrimo[i][j] == '#' && map[y + i][x + j] != '.') /*||  (4 < j + width || 4 < i + height) */)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char		**print_tet(char **tetrimo, char **temp, int x, int y, int width, int height)
{
	int	i;
	int	j;
	static char	letter;
	if (letter == 0)
		letter = 'A';
	else
		letter++;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (tetrimo[i][j] == '#')
				temp[y + i][x + j] = letter;
			j++;
		}
		i++;
	}
	return (temp);
}