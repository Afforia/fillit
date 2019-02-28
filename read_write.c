/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:14:58 by thaley            #+#    #+#             */
/*   Updated: 2019/02/28 18:06:55 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fillit_new.h"

void		offset(char **tetrimo)
{
	int		x;
	int		y;
	int		i;
	int		j;

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

void		write_figure(char *buf, char **tetrimo)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(buf);
	while (i < 4)
	{
		buf = str;
		tetrimo[i] = ft_strsub(str, 0 ,4);
		str = ft_strsub(str, 5, ft_strlen(str) - 4);
		free(buf);
		i++;
	}
	free(str);
	tetrimo[i] = NULL;
}

int			count_tetrimo(char *argv)
{
	int		count;
	int		fd;
	int		ret;
	char	buf[22];
	
	count = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (ret == 21)
		{
			if (check_not_last(buf))
				return (0);
		}
		if (ret < 21)
		{
			if (check_last(buf))
				return (0);
		}
		count++;
	}
	if (count > 26 || count == 0)
		return (0);
	close (fd);
	return (count);
}

t_fillit	**write_from_buf(char *argv, int count)
{
	int			fd;
	int			ret;
	int			i;
	char		buf[22];
	t_fillit	**fillit;
	
	i = 0;
	fillit = (t_fillit **)malloc(sizeof(t_fillit *) * count + 1);
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		fillit[i] = new_struct();
		write_figure(buf, fillit[i]->left_up_corner);
		offset(fillit[i]->left_up_corner);
		i++;
	}
	fillit[i] = NULL;
	close(fd);
	return(fillit);
}