/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:34:53 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/24 17:44:16 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_del.h"

void    write_map(char *buf, char **map) //pishet map
{
    int i;
    char *str;

    i = 0;
    str = ft_strdup(buf);
    while (i < 4)
    {
        buf = str;
        map[i] = ft_strsub(str, 0, 4);//проверка выделения памяти нужна наверное
        str = ft_strsub(str, 5, ft_strlen(str) - 5);
        free(buf);
        i++;
    }
    free(str);
    map[i] = NULL;
}

/* void    write_x_y(char **map, int **coord) //pishet coordinates мб потом пофришить прямо здесь массив мап если он больше не нужен
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map)
        }
    }
} */



t_fillit *new_feel_it(void)//создающая новый лист функция + выделяющая память для листа функция..к черту листы, хочу массив структур
{
    t_fillit *new;
    int i;

    new = (t_fillit *)malloc(sizeof(t_fillit));
    new->map = (char **)malloc(sizeof(char *) * 5);
    i = 0;
    new->coord = (int **)malloc(sizeof(int *) * 5); 
    while (i < 2)
    {
        new->coord[i] = (int *)malloc(sizeof(int) * 3); //проверка и фри
        i++;
    }
    return(new);
}

t_fillit **write_main(char *file, int kolvo)
{
    char *buf;
    int ret;
    int fd;
    int i;
    t_fillit **feel_it;
    int j;//

    buf = (char *)malloc(sizeof(char) * 22);
    feel_it = (t_fillit **)malloc((sizeof(t_fillit *)) * (kolvo + 1)); //proverka and free
    fd = open(file, O_RDONLY);
    i = 0;
    while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
        feel_it[i] = new_feel_it(); //попробую выделять память в самих функциях, чтобы не передавать..проще передавать
        write_map(buf, feel_it[i]->map); //нужен ли указатель на двойной массив..мб и так сработает
        j = 0;//
        while (feel_it[i]->map[j])
        {
            printf("%s\n", feel_it[i]->map[j]);
            j++;
        }
        printf("-\n");//
        offset(feel_it[i]);
        feel_it[i]->abc = 65 + i;
        j = 0;//
        while (feel_it[i]->map[j])
        {
            printf("%s\n", feel_it[i]->map[j]);
            j++;
        }
        printf("-\n");//
        i++;
	}
    feel_it[i] = NULL;
    free(buf);
    close(fd);
	return (feel_it);
}

/*test()
{
    int abcd[4];
    ft_bzero(&abcd[0], sizeof(int) * 4)

    abcd[0]

} */