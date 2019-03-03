/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:30:25 by rfrankly          #+#    #+#             */
/*   Updated: 2019/03/03 17:17:09 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int kolvo;
	t_fillit **feel_it;

	kolvo = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file_name\n");
		exit(0);
	}
	if (read_main(argv[1], &kolvo) != 0)
	{
		ft_putstr("error: invalide file\n");
		exit(0);
	}
	feel_it = write_main(argv[1], kolvo);
	if (check_shape(feel_it) == 1)
	{
		ft_putstr("error: invalide file\n");
		exit(0);
	}
	return (0);
}