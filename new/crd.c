/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:14:02 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 15:52:36 by thaley           ###   ########.fr       */
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

int		find_hgt(char **tetrimo)
{
	int		i;
	int		j;

	i = 3;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (tetrimo[i][j] == '#')
				return (i + 1);
			j--;
		}
		i--;
	}
	return (i);
}

int		find_wdt(char **tetrimo)
{
	int	i;
	int	j;

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
