/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:53:30 by thaley            #+#    #+#             */
/*   Updated: 2019/02/19 20:43:47 by thaley           ###   ########.fr       */
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
// size_t			find_end(char *buf, int i)
// {
// 	while (buf[i] != '\0')
// 	{
// 		if (i ==)
// 		i++;
// 	}
// 	return (i);
// }
t_fillit		*read_file(int fd)
{
	t_fillit	*fillit;
	t_fillit	*head;
	char		buf[BUFF_SIZE + 1]; // возможно стоит выделять память динамически
	// int			ret;
	// int			i = 0;
	int			count = 0;
	// char		**term_map = (char**)malloc(1);

	fillit = new_list(1);
	head = fillit;
	// t_point *p_min = makepoint(0, 0);
	// t_point *p_max = makepoint(3, 3);
	count = read_main(buf, fd);
	printf("%d\n", count);
	printf("%s\n", buf);
	return (fillit);
}