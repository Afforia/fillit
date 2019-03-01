/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:59 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 18:12:01 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

void	hollow_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->side)
	{
		map->map[i][j] = '.';
		if (j == map->side)
		{
			map->map[i][j] = '\n'; // mb need '\0???
			i++;
			j = -1;
		}
		j++;
	}
	map->map[map->side-1][map->side] = '\0';
}