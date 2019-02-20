/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:34:53 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/20 14:52:31 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_del.h"

/* int find_n(char *buf)
{
    int i;

    i = 0;
    while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				break ;
			i++;
		}
    return (i);
} */ //я и так знаю, где н

void    write_map(char **buf, char **map) //pishet map
{
    //int n;
    int i;
    char *str;

    i = 0;
    while (i < 4)
    {
        //n = find_n(*buf);
        str = *buf;
        map[i] = ft_strsub(*buf, 0, 4);//проверка выделения памяти нужна наверное
        *buf = ft_strsub(*buf, 5, ft_strlen(*buf) - 4);
        free(str);
        i++;
    }
    free(*buf); //надо ли при этом указатель на ноль
}

void    write_x_y(char **map, int **coord) //pishet coordinates мб потом пофришить прямо здесь массив мап если он больше не нужен
{

}

t_fillit *new_feel_it(void)//создающая новый лист функция + выделяющая память для листа функция..к черту листы, хочу массив структур
{
    t_fillit *new;
    int i;

    new->map = (char **)malloc((sizeof(char *)) * 4);
    //i = 0;
    /* while (i < 4)
    {
        new->map[i] = (char *)malloc((sizeof(char)) * 5); //надо прописать проверку на выделение памяти и пофришить все, если не получилось
        i++;
    } */ //все равно память в функции выделяется
    i = 0;
    new->coord = (char **)malloc((sizeof(char *)) * 2); 
    while (i < 2)
    {
        new->coord[i] = (char *)malloc((sizeof(char)) * 5); //проверка и фри
        i++;
    }
    return(new);
}

int write_main(char *file, int kolvo)
{
    char *buf;
    int ret;
    int fd;
    int i;
    t_fillit **feel_it;

    buf = (char *)malloc(sizeof(char) * 22);//proverka and free
    feel_it = (t_fillit **)malloc((sizeof(t_fillit *)) * kolvo); //proverka and free
    fd = open(file, O_RDONLY);
    i = 1;
    while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
        feel_it[i - 1] = new_feel_it(); //попробую выделять память в самих функциях, чтобы не передавать..проще передавать
        write_map(&buf, feel_it[i - 1]->map); //нужен ли указатель на двойной массив..мб и так сработает
        write_x_y(feel_it[i - 1]->map, feel_it[i - 1]->coord);//то же самое
        feel_it[i - 1]->numb = i; //mb ne nado
        feel_it[i - 1]->fi = 64 + i;
        i++;
	}
    close(fd);
	return (0);
}