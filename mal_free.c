/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:43:40 by thaley            #+#    #+#             */
/*   Updated: 2019/03/03 19:38:56 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

t_sol_tet	*new_struct(t_map *map)
{
	t_sol_tet	*new;
	int			i;

	i = 0;
	if (!(new = (t_sol_tet*)malloc(sizeof(t_sol_tet))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->tet = (char **)malloc(sizeof(char *) * (map->side + 1));
	while (i < map->side)
	{
		new->tet[i] = ft_strdup(map->map[i]);
		i++;
	}
	new->tet[i] = NULL;
	return (new);
}

t_map		*new_map(int count)
{
	t_map	*new;
	int		i;
	int 	side;

	i = 0;
	side = 2;
	new = (t_map *)malloc(sizeof(t_map));
	new->area = count * 4;
	new->x = 0;
	new->y = 0;
	while (side * side < new->area)
		side++;
	new->side = side;
	new->map = (char **)malloc(sizeof(char *) * (side + 1));
	while (i < side)
	{
		new->map[i] = ft_strnew(side);
		i++;
	}
	new->map[i] = NULL;
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
	return (new);
}