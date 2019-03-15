/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:13:59 by thaley            #+#    #+#             */
/*   Updated: 2019/03/15 18:48:51 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_fillit	**feel_it;
	int			count;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((count = count_tet(argv[1])) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!(feel_it = write_buf(argv[1], count)))
	{
		ft_putstr("error\n");
		return (1);
	}
	sol_fillit(feel_it, count);
	return (0);
}

int			count_tet(char *argv)
{
	int		fd;
	int		ret;
	int		end;
	int		count;
	char	buf[22];

	end = 0;
	count = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (check_buf(buf, ret, &end))
		{
			close(fd);
			return (0);
		}
		count++;
	}
	close(fd);
	if (end != 1)
		return (0);
	if (count > 26 || count == 0)
		return (0);
	return (count);
}

t_fillit	**write_buf(char *argv, int count)
{
	t_fillit	**feel_it;
	int			i;
	int			fd;
	int			ret;
	char		buf[22];

	i = 0;
	fd = open(argv, O_RDONLY);
	if (!(feel_it = (t_fillit **)malloc(sizeof(t_fillit *) * count + 1)))
		return (NULL);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		feel_it[i] = write_tet(buf, i);
		feel_it[i]->height = find_hgt(feel_it[i]->tetrimo);
		feel_it[i]->width = find_wdt(feel_it[i]->tetrimo);
		i++;
	}
	close(fd);
	feel_it[i] = NULL;
	if ((check_shape(feel_it)))
		return (NULL);
	return (feel_it);
}

t_fillit	*write_tet(char *buf, int i)
{
	t_fillit	*feel_it;
	int			index;
	char		*str;

	index = 0;
	str = NULL;
	feel_it = new_fillit(i);
	str = ft_strdup(buf);
	while (index < 4)
	{
		buf = str;
		feel_it->tetrimo[index] = ft_strsub(str, 0, 4);
		str = ft_strsub(str, 5, ft_strlen(str) - 4);
		free(buf);
		index++;
	}
	free(str);
	feel_it->tetrimo[index] = NULL;
	offset(feel_it->tetrimo);
	return (feel_it);
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
