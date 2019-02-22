/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:03:43 by thaley            #+#    #+#             */
/*   Updated: 2019/02/20 21:25:07 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			ret;
	char		buf[256]; //malloc NEED
	int			count;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit\n");
		return (1);
	}
	
	fd = open(argv[1]);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret == 21)
		{
			if (check_not_last_buf(buf)) //how should i exit from here
				return (0);
		}
		if (ret < 21)
		{
			if (check_last(buf)) //how should i exit from here
				return (0);
		}
		count++;
	}
	if (count > 26 || count <= 0)
	{
		close (fd);
		return (1);
	}
	if ((solution(count, buf))) //mb need if solution wasnt found
	{
		close (fd);
		return (1);
	}
	close(fd);
	return (0);
}