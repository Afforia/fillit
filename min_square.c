// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   min_square.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/02/10 20:46:03 by thaley            #+#    #+#             */
// /*   Updated: 2019/02/17 19:22:25 by thaley           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // DONT FORGET!!!
#include "libft/libft.h"
// такая х**ня и я нахожу в этом кайф!
/*
** int area = sum of tetrimos area
** x = width of map
** y = height of map
*/
char		**find_map(int area) //mb should return list for map
{
	char	**new_map;
	int		x;
	int		i = 0;
	int		j = 0;

	x = 2;
	while (x * x < area)
		x++;
	new_map = (char **)malloc((sizeof(char*)) * x); // не выделяется память нормально
	while (i < x)
	{
		new_map[i] = (char *)malloc(sizeof(char) * x);
		i++;
	}
	i = 0;
	while (j < x)
	{
		if (i == 4)
		{
			new_map[j][i] = '\0';
			j++;
		}
		new_map[j][i] = '.'; // сегментит когда j = 1
		i++;
	}
	return (new_map);
}
/*
** backtracking algorimth
** list/array with tetrimos, tetrimo width, tetrimo height, map area
*/

// void		backtrack(char **tetrimo, int width, int height, int area)
// {
// 	int x; //width
// 	int y; //height

// 	x = y = 0;
// 	while (y < area - height + 1)
// 	{
// 		while (x < area - width + 1)
// 		{
// 			if (place_tetrimo)
// 				return ; 
// 			else
// 				backtrack(tetrimo->next, width, height, area);
// 			x++;	
// 		}
// 		y++;
// 	}
// } 