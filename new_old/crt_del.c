/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:12:44 by thaley            #+#    #+#             */
/*   Updated: 2019/02/24 13:16:57 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** mb rename to create and free in other file
*/

t_fillit	*new_list_fillit(int count)
{
	t_fillit	*new_list;

	if (!(new_list = (t_fillit *)malloc(sizeof(t_fillit))))
		return (NULL);
	new_list->content = '#';
	new_list->width = 0;
	new_list->height = 0;
	new_list->next = NULL;
	new_list->tetriski = ft_strnew(0);
	new_list->count = count;
	new_list->left_up_corner = (char **)malloc(sizeof(char *));
	return (new_list);
}
char		**find_map(int area)
{
	char	**new_map;
	int		x;
	int		i;
	int		j;

	x = 2;
	i = 0;
	j = 0;
	while (x * x < area)
		x++;
	new_map = (char **)malloc(sizeof(char *) * x + 1);
	while (i < x)
	{
		new_map[i] = ft_strnew(x);
		i++;
	}
	i = 0;
	while (j < x)
	{
		new_map[j][i] = '.';
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