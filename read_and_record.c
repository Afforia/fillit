/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_record.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:04:22 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/19 20:47:28 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int check_not_last_buf(char *buf)
{
    int j;
    int resh;


    j = 1;
    resh = 0;
    while (buf[j - 1] != '\0')
    {
        if ((j % 5 == 0) && (buf[j - 1] != '\n'))
            return (1);
        else if((j == 21) && (buf[j - 1] != '\n'))
            return (1);
        else if ((j % 5 != 0) && (j != 21))
        {
            if ((buf[j - 1] != '.') && (buf[j - 1] != '#'))
                return (1);
            if (buf[j - 1] == '#')
                resh++;
        }
        j++;
    }
    if (resh != 4)
        return (1);
    return (0);
}

int check_last(char *buf)
{
    int j;
    int resh;

    j = 1;
    resh = 0;
    while (buf[j - 1] != '\0')
    {
        if ((j % 5 == 0) && (buf[j - 1] != '\n'))
            return (1);
        else if (j % 5 != 0)
        {
            if ((buf[j - 1] != '.') && (buf[j - 1] != '#'))
                return (1);
            if (buf[j - 1] == '#')
                resh++;
        }
        j++;
    }
    if ((resh != 4) || (j != 20))
        return (1);
    return (0);
}

int read_main(char *buf, int fd)
{
    int ret;
    int i;

    i = 0;
    while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret == 21)
        {
            if (check_not_last_buf(buf))
                return (1);
        }
        if (ret < 21)
        {
            if (check_last(buf))
                return (1);
        }
        i++;
	}
    close(fd);
	return (i);
}