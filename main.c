/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:30:25 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/24 18:51:35 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int kolvo;

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
	write_main(argv[1], kolvo);
	return (0);
}