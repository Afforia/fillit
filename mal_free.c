/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:42:05 by thaley            #+#    #+#             */
/*   Updated: 2019/03/09 19:06:13 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*new_fillit(int i)
{
	t_fillit	*new;
	int			j;

	j = 0;
	new = (t_fillit *)malloc(sizeof(t_fillit));
	if (!(new->tetrimo = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	new->crd = (int **)malloc(sizeof(int *) * 5);
	while (j < 4)
	{
		new->crd[j] = (int *)malloc(sizeof(int) * 2);
		j++;
	}
	new->content = 'A' + i;
	return (new);
}

t_map		*new_map(int side)
{
	t_map	*new;
	int		i;

	i = 0;
	new = (t_map *)malloc(sizeof(t_map));
	new->side = side;
	new->x = 0;
	new->y = 0;
	new->map = (char **)malloc(sizeof(char *) * side + 1);
	while (i < side)
	{
		new->map[i] = dot_string(side);
		i++;
	}
	new->map[i] = NULL;
	return (new);
}