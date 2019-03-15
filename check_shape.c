/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:26:42 by rfrankly          #+#    #+#             */
/*   Updated: 2019/03/15 15:17:33 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int find_count(char **map, int i, int j)
{
    int count;

    count = 0;
    if (j + 1 <= 3 && map[i][j + 1] == '#')
		count++;
	if (j - 1 >= 0 && map[i][j - 1] == '#')
		count++;
	if (i + 1 <= 3 && map[i + 1][j] == '#')
		count++;
	if (i - 1 >= 0 && map[i - 1][j] == '#')
		count++;
    return (count);
}
int check_count(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == '#')
			{
				count = count + find_count(map, i, j);
			}
			j++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (1);
	return (0);
}

void free_arr(void **mass)
{
    void **arr;

    arr = mass;
    while (*mass)
    {
        free(*mass);
        mass++;
    }
    free(arr);
}

int check_shape(t_fillit **feel_it)
{
    int i;

    i = 0;
    while (feel_it[i] != NULL)
    {
        if (check_count(feel_it[i]->tetrimo) == 1)
        {
            i = 0;
            while (feel_it[i] != NULL)
            {
                free_arr((void **)feel_it[i]->tetrimo);
                free(feel_it[i]);
                i++;
            }
            free(feel_it);
            return (1);
        }
        i++;
    }
    return (0);
}