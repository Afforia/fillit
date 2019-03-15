/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:39:44 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 18:41:32 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_buf(char *buf, int ret, int *end)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	if (*end)
		return (1);
	while (buf[i - 1] != '\0')
	{
		if ((i % 5 == 0 || i == 21) && buf[i - 1] != '\n')
			return (1);
		else if (i % 5 != 0 && i != 21)
		{
			if (buf[i - 1] != '.' && buf[i - 1] != '#')
				return (1);
			if (buf[i - 1] == '#')
				res++;
		}
		i++;
	}
	if (res != 4 && ret == 21)
		return (1);
	if (buf[20] != '\n')
		*end = 1;
	return (0);
}

int		check_shape(t_fillit **feel_it)
{
	int		i;

	i = 0;
	while (feel_it[i] != NULL)
	{
		if (check_in(feel_it[i]->tetrimo))
		{
			i = 0;
			while (feel_it[i] != NULL)
			{
				free_arr(feel_it[i]->tetrimo);
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

int		check_in(char **tetrimo)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimo[i][j] == '#')
				count = count + find_count(tetrimo, i, j);
			j++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (1);
	return (0);
}

int		find_count(char **tetrimo, int i, int j)
{
	int count;

	count = 0;
	if (j + 1 <= 3 && tetrimo[i][j + 1] == '#')
		count++;
	if (j - 1 >= 0 && tetrimo[i][j - 1] == '#')
		count++;
	if (i + 1 <= 3 && tetrimo[i + 1][j] == '#')
		count++;
	if (i - 1 >= 0 && tetrimo[i - 1][j] == '#')
		count++;
	return (count);
}
