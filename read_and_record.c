/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_record.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:41:04 by thaley            #+#    #+#             */
/*   Updated: 2019/02/22 17:45:56 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** what shoul function return
** should close fd before every return or make it at main?
*/

t_fillit		*read_buf(char *argv)
{
	int			fd;
	int			ret;
	int 		count;
	char		buf[BUFF_SIZE + 1];
	t_fillit	*tetrimo;
	t_fillit	*head;

	count = 0;
	tetrimo = new_list_fillit(count);
	head = tetrimo;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret == 21)
		{
			if (check_not_last_buf(buf)) //how should i exit from here
				return (NULL);
		}
		if (ret < 21)
		{
			if (check_last(buf)) //how should i exit from here
				return (NULL);
		}
		count++;
		tetrimo->tetriski = ft_strjoin(tetrimo->tetriski, buf); //что то лишнее записывает
		tetrimo->next = new_list_fillit(count); //возможно потому что он что то записывает когда баф уже закончился?
		tetrimo = tetrimo->next;
	}
	free (tetrimo); //need Free all lists || i think so
	tetrimo = head;
	if (count > 26 || count <= 0) //count need 1 insted of 0
		return (NULL);
	close (fd);
	return (tetrimo);
}