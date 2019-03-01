/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:01:13 by thaley            #+#    #+#             */
/*   Updated: 2019/03/01 14:40:41 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		find_height(char **tetrimo)
{
	int	j;
	int	i;

	i = 3;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (tetrimo[i][j] == '#')
				return (i+1);
			j--;
		}
		i--;
	}
	return (i);
}

int		find_width(char **tetrimo)
{
	int j;
	int	i;

	j = 3;
	while (j >= 0)
	{
		i = 3;
		while (i >= 0)
		{
			if (tetrimo[i][j] == '#')
				return (j + 1);
			i--;
		}
		j--;
	}
	return (j);
}

int		find_y(char **tetrimo)
{
    int i;
    int j;

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

int 	find_x(char **tetrimo)
{
    int i;
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
void	find_tet_area(t_fillit **fillit, int count)
{
	int	j;

	j = 0;	
	while(j < count)
	{
		fillit[j]->height = find_height(fillit[j]->left_up_corner);
		fillit[j]->width = find_width(fillit[j]->left_up_corner);
		j++;
	}
}