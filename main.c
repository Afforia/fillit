/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:03:43 by thaley            #+#    #+#             */
/*   Updated: 2019/02/24 19:08:13 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int			count;
	t_fillit	*fillit;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit\n");
		return (1);
	}
	fillit = read_buf(argv[1]);
	return (0);
}