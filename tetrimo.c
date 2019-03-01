/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:16:27 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 15:03:01 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		backtrack(t_fillit **fillit, t_map *map)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (y < (map->area - fillit[i]->height + 1))
	{
		while (x < (map->area - fillit[i]->width + 1))
		{
			if (place_tetrimo(fillit, map, i))
				return (0);
			else
				backtrack(fillit, map);
			x++;
		}
		y++;
	}
	return (1);
}