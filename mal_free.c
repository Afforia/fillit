/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:43:40 by thaley            #+#    #+#             */
/*   Updated: 2019/02/28 18:14:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

t_fillit *new_struct()
{
	t_fillit	*new;
	int			i;

	i = 0;
	new = (t_fillit *)malloc(sizeof(t_fillit));
	new->left_up_corner = (char **)malloc(sizeof(char *) * 5);
	new->height = 0;
	new->height = 0;
	new->coord = (int **)malloc(sizeof(int *) * 5);
	while (i < 2) //why Adel i < 2 ???
	{
		new->coord[i] = (int *)malloc(sizeof(int) * 3);
		i++;
	}
	return (new);
}