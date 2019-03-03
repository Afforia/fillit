#include "fillit.h"

void	backtrack(t_fillit *tetrimo, int area)
{
	int		x; //width
	int		y; //height

	x = 0;
	y = 0;
	while (y < area - tetrimo->height + 1)
	{
		while (x < area - tetrimo->width + 1)
		{
			if (place_tetrimo(tetrimo, area))
				return ;
			else
				backtrack(tetrimo->next, area);
			x++;
		}
		y++;
	}
}