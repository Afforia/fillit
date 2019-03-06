/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:36:42 by thaley            #+#    #+#             */
/*   Updated: 2019/03/06 19:43:23 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_buf(char *argv)
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
	close (fd);
	return (count);
}