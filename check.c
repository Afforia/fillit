/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:31:55 by thaley            #+#    #+#             */
/*   Updated: 2019/02/22 15:32:11 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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