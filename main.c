/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:30:04 by thaley            #+#    #+#             */
/*   Updated: 2019/03/06 19:34:28 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		count;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit\n");
		return (1);
	}
	count = read_buf(argv[1]);
}