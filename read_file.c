/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:53:30 by thaley            #+#    #+#             */
/*   Updated: 2019/02/20 21:01:01 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // DONT FORGET!!!

/*
** Now it return first tetrimo in a file
** allocated in new string
** КОРОЧЕ тут нужен двойной массив [1] - кол-во столбцов [2] - символы в строке! 
** что то уже не соображаешь "и над этим всем яркое солнце..." 
*/

t_fillit	*new_list(int count)
{
	t_fillit	*new_list;

	if (!(new_list = (t_fillit *)malloc(sizeof(t_fillit))))
		return (NULL);
	new_list->content = '#';
	new_list->width = 0;
	new_list->height = 0;
	new_list->next = NULL;
	count++;
	new_list->count = count;
	return (new_list);
}

/*
** разберись ты тут скоро вообще видеть ничего не будешь
** отправь часть в мейн нафиг оно тут а вместо фд передавай 
** количество тетримонов которые насчитало
**	// t_point *p_min = makepoint(0, 0); - mb need mb not 
**	// t_point *p_max = makepoint(3, 3); типо минимальный и максимальные координаты
** правда это только если сместить каждую фигурку в левый верхний угол
*/

t_fillit		*read_file(int temp)
{
	t_fillit	*fillit;
	t_fillit	*head;
	t_map		*map;
	char		**tmp;
	char		buf[BUFF_SIZE + 1]; // возможно стоит выделять память динамически

	temp = map->area;
	fillit = new_list(1); //FREE!!!!
	map = (t_map *)malloc(sizeof(t_map)); //NEED FREEEEEE!!!
	head = fillit;
	tmp = read_main(buf, &temp); // неуверена что так передается то что нужно
	if (map->area > 26 || map->area <= 0) //? check in main what function has return ?
		return(NULL);
	map->map = find_map(map->area * 4);
	backtrack(fillit, map->area);
	return (fillit);
}