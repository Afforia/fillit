/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:06:13 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/24 19:18:08 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int find_y(char **map)
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
            if (map[i][j] == '#')
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

static int find_x(char **map)
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

void offset(char **map)
{
    int x;
    int y;
    int i;
    int j;

    i = 0;
    x = find_x(map);
    y = find_y(map);
    if (x == 0 && y == 0)
        return ;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (map[i][j] == '#')
            {
                map[i - y][j - x] = '#';
                map[i][j] = '.';
            }
            j++;
        }
        i++;
    }
}