/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:09:38 by thaley            #+#    #+#             */
/*   Updated: 2019/02/28 18:18:35 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_new.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int			count;
	t_fillit	**fillit;

	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage\n");
		return (1);
	}
	if ((count = count_tetrimo(argv[1])) == 0)
	{
		ft_putstr("Invalid file.\n");
		return (1);
	}
	fillit = write_from_buf(argv[1], count);
	find_tet_area(fillit);
	return (0);
}