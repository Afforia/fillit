/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:43:52 by thaley            #+#    #+#             */
/*   Updated: 2019/03/09 18:12:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** split i%5 and i==21
** if '#' not 4 (tetrimo must contain 4 chars)
** check last and not last in 1
*/

int		check_buf(char *buf, int ret)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
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
	if ((res != 4 || i != 20) && ret < 21)
		return (1);
	return (0);
}
