/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:30:25 by rfrankly          #+#    #+#             */
/*   Updated: 2019/02/17 21:02:45 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file_name\n");
		exit(0);
	}
	if (read_main(argv[1]) != 0)
	{
		ft_putstr("error: invalide file\n");
		exit(0);
	}
	return (0);
}