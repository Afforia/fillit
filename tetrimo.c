/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:16:27 by thaley            #+#    #+#             */
/*   Updated: 2019/03/06 16:15:02 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

// int		solution(t_fillit **fillit, t_map *map)
// {
// 	int		i;
	
// 	i = 0;
// 	while (backtrack(fillit, map, i) == 1 && (i < 3))
// 	{
// 		i++;
// 	}
// 	i = 0 ;
// 	while (map->map[i])
// 	{
// 		printf("%s\n", map->map[i]);
// 		i++;
// 	}
// 	return (0);
// }

/*
** нужно чтобы он полноценно сохранял измененную временную карту, а не перезаписывал ее
** пока не перепробует все фигуры -> потом только обнулит и заново
** продумать эти условия !!!
*/

// int		backtrack(t_fillit **fillit, t_map *map, int i)
// {
// 	int		x; //может х и у тоже должны передаваться?
// 	int		y;
// 	int		j;
// 	char	**tet = NULL;

// 	j = 0;
// 	x = 0;
// 	y = 0;
// 	if (!tet)
// 	{
// 		tet = (char **)malloc(sizeof(char *) * map->side + 1);
// 		while (j < map->side)
// 		{
// 			tet[j] = ft_strdup(map->map[j]);
// 			j++;
// 		}
// 		tet[j] = NULL;
// 	}
// 	while (y < (map->side - fillit[i]->height + 1))
// 	{
// 		while (x < (map->side - fillit[i]->width + 1))
// 		{
// 			if (place_tetrimo(fillit[i]->left_up_corner, &tet, x, y, fillit[i]->width, fillit[i]->height))
// 			{
// 				if (i == 2)
// 				{
// 					j = 0;
// 					while (j < map->side)
// 					{
// 						map->map[j] = ft_strcpy(map->map[j], tet[j]);
// 						j++;
// 					}
// 				}
// 				// free(tet);
// 				return (1);
// 			}
// 			else
// 			{
// 				if (i < 2)
// 				{
// 					j = 0;
// 					while (j < map->side)
// 					{
// 						tet[j] = ft_strcpy(tet[j], map->map[j]);
// 						j++;
// 					}
// 					i++;
// 					backtrack(fillit, map, i);
// 				}
// 				else
// 					return (0);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }
