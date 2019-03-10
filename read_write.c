/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:36:42 by thaley            #+#    #+#             */
/*   Updated: 2019/03/10 14:39:22 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	**write_buf(char *argv, int count)
{
	int			fd;
	int			ret;
	int			i;
	char		buf[22];
	t_fillit	**fillit;

	i = 0;
	fd = open(argv, O_RDONLY);
	fillit = (t_fillit **)malloc(sizeof(t_fillit *) * count + 1);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		fillit[i] = new_fillit(i);
		write_tet(buf, fillit[i]->tetrimo);
		offset(fillit[i]->tetrimo);
		fillit[i]->height = height(fillit[i]->tetrimo);
		fillit[i]->width = width(fillit[i]->tetrimo);
		i++;
	}
	fillit[i] = NULL;
	close(fd);
	return (fillit);
}

void		write_tet(char *buf, char **tetrimo)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_strdup(buf);
	while (i < 4)
	{
		buf = str;
		tetrimo[i] = ft_strsub(str, 0, 4);
		str = ft_strsub(str, 5, ft_strlen(str) - 4);
		free(buf);
		i++;
	}
	free(str);
	tetrimo[i] = NULL;
}

void		offset(char **tetrimo)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	x = find_x(tetrimo);
	y = find_y(tetrimo);
	if (x == 0 && y == 0)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimo[i][j] == '#')
			{
				tetrimo[i - y][j - x] = '#';
				tetrimo[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

char	*dot_string(int side)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(side + 1)))
		return (0);
	while (i < side)
	{
		new[i] = '.';
		i++;
	}
	new[i] = '\0';
	return (new);
}
