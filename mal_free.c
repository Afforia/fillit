/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:43:40 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 14:35:59 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

t_map		*new_map(int count)
{
	t_map	*new;
	int		i;
	int 	side;

	i = 0;
	side = 2;
	new = (t_map *)malloc(sizeof(t_map));
	new->area = count * 4;
	while (side * side < new->area)
		side++;
	new->side = side;
	new->map = (char **)malloc(sizeof(char *) * (side + 1));
	while (i < side)
	{
		new->map[i] = ft_strnew(side);
		i++;
	}
	return (new);
}

t_fillit	*new_fillit()
{
	t_fillit	*new;
	int			i;

	i = 0;
	new = (t_fillit *)malloc(sizeof(t_fillit));
	new->left_up_corner = (char **)malloc(sizeof(char *) * 5);
	new->height = 0;
	new->height = 0;
	// new->coord = (int **)malloc(sizeof(int *) * 5);
	// while (i < 2) //why Adel i < 2 ???
	// {
	// 	new->coord[i] = (int *)malloc(sizeof(int) * 3);
	// 	i++;
	// }
	return (new);
}