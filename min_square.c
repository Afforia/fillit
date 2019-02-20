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
** int area = sum of tetrimos area || по-хорошему это должно быть площать греб. фигурок
** x = width of map
** y = height of map
** IT WORKS!!! print map_square of dots. size = x * x 
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
	new_map = (char **)malloc(sizeof(char*) * x + 1); // теперь все норм выделяется, слепая смотри на скобочки
	while (i < x)
	{
		new_map[i] = ft_strnew(4);
		i++;
	}
	i = 0;
	while (j < x)
	{
		new_map[j][i] = '.'; // сегментит , j = 4  i = 12|| хз почему
		if (i == x)
		{
			new_map[j][i] = '\n';
			j++;
			i = -1;
		}
		i++;
	}
	return (new_map);
}
/*
** backtracking algorimth
** list/array with tetrimos, tetrimo width, tetrimo height, map area
||																															||
ALERT!!! пока что пусть принимает так: 1)основную структуру в которой вся фигня и записана по нашим тетримо
+ сами тетримо
									   2)площадь карты (я только не уверена сама карта нужна только для печати или чтобы он
запихать фигурки попытался тоже нужна ?? - вопрос пока не решен)
||																															||
** вот это вот должно что то принимать чтобы работать
** и как то пихать эти штуки на карту
*/

void		backtrack(t_fillit *tetrimo, int area)  //а жирота и длиннота точно не из листа берутся? always your CAP
{
	int x; //width
	int y; //height

	x = 0;
	y = 0;
	while (y < area - tetrimo->height + 1)
	{
		while (x < area - tetrimo->width + 1)
		{
			if (place_tetrimo(tetrimo, area)) // тут как то их заталкивать надо
				return ;
			else
				backtrack(tetrimo->next, area); // а тут точно не *ху* передается
			x++;	
		}
		y++;
	}
}

/*
** prototype for place tetrimo
** нужно продумать как он должен их вставлять
*/

int		place_tetrimo(t_fillit *tetrimo, int area)
{
	printf ("tet - %c || area - %d\n", tetrimo->content, area);
	return (1);
}