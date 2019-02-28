/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:31:55 by thaley            #+#    #+#             */
/*   Updated: 2019/02/28 18:02:26 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"

int		find_y(char **tetrimo)
{
	int y;
    int i;
    int j;

    i = 0;
    y = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (tetrimo[i][j] == '#')
            {
                y = i;
                return (y); 
            }
            j++;
        }
        i++;
    }
    return (y);
}

int 	find_x(char **map)
{
    int x;
    int i;
    int j;

    j = 0;
    x = 0;
    while (j < 4)
    {
        i = 0;
        while (i < 4)
        {
            if (map[i][j] == '#')
            {
                x = j;
                return (x); 
            }
            i++;
        }
        j++;
    }
    return (x);
}

int check_not_last(char *buf)
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