/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:49:30 by thaley            #+#    #+#             */
/*   Updated: 2019/03/09 19:13:47 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sol_map(t_fillit **fillit, int count)
{
	t_map	*map;
	int		side;

	side = 2;
	while (side * side < count * 4)
		side++;
	map = new_map(side);
	// here i stoped!
}