/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:00:16 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 17:56:22 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*new_fillit(int i)
{
	t_fillit	*new;

	if (!(new = (t_fillit *)malloc(sizeof(t_fillit))))
		return (NULL);
	if (!(new->tetrimo = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	new->height = 0;
	new->width = 0;
	new->content = 'A' + i;
	return (new);
}

t_map		*new_map(int side)
{
	t_map	*new;
	int		i;

	i = 0;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	new->side = side;
	new->x = 0;
	new->y = 0;
	if (!(new->map = (char **)malloc(sizeof(char *) * side + 1)))
		return (NULL);
	while (i < side)
	{
		new->map[i] = dot_string(side);
		i++;
	}
	new->map[i] = NULL;
	return (new);
}

char		*dot_string(int side)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(side + 1)))
		return (NULL);
	while (i < side)
	{
		new[i] = '.';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void		free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
	tmp = NULL;
	arr = tmp;
}

void		free_fillit(t_fillit **feel_it)
{
	t_fillit	**tmp;
	int			i;

	tmp = feel_it;
	i = 0;
	while (feel_it[i] != NULL)
	{
		free_arr(feel_it[i]->tetrimo);
		free(feel_it[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
	feel_it = tmp;
}
