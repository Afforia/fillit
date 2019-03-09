/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:30:04 by thaley            #+#    #+#             */
/*   Updated: 2019/03/09 18:51:39 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			count;
	t_fillit	**fillit;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: \"./fillit source_filename\"\n");
		return (1);
	}
	if ((count = count_tet(argv[1])) == 0)
	{
		ft_putstr("invalid file!\n");
		return (1);
	}
	fillit = write_buf(argv[1], count);
	if (check_shape(fillit))
	{
		ft_putstr("invalid file!\n");
		return (1);
	}
	sol_map(fillit, count);
	return (0);
}

/*
** count number of tetrimo and check file
*/

int		count_tet(char *argv)
{
	int		fd;
	int		ret;
	int		count;
	char	buf[22];

	count = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (check_buf(buf, ret))
			return (0);
		count++;
	}
	close (fd);
	if (count > 26 || count == 0)
		return (0);
	return (count);
}
