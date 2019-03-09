/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 17:12:57 by thaley            #+#    #+#             */
/*   Updated: 2019/03/09 18:47:09 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_x(char **tetrimo)
{
	int	i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetrimo[i][j] == '#')
				return (j);
			i++;
		}
		j++;
	}
	return (j);
}

int		find_y(char **tetrimo)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimo[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

void	coord(char **tetrimo, int **crd)
{
	int		i;
	int		j;
	int		num;

	num = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimo[i][j] == '#')
			{
				crd[num][0] = i; //height
				crd[num][1] = j; //width
				num++; 
			}
			j++;
		}
		i++;
	}
	crd[num] = NULL;
}