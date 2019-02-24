#include "fillit.h"

int		solution(int count, char *buf)
{
	t_fillit	*fillit;
	t_fillit	*head;
	t_map		*map;

	buf--;
	fillit = new_list_fillit(count); //выделять память сразу под все листы
	map = (t_map *)malloc(sizeof(t_map));
	map->area = count * 4;
	head = fillit;
	map->map = find_map(map->area);
	// backtrack(fillit, map->area); // подумать что должно возвращать
	return (0);
}

/*
** нужно чтобы считал сколько иксов в ряде под номером игрек
*/

void	write_coordinates(t_fillit *tetrimo)
{
	int		i;
	t_fillit	*head;
	char	**check;

	i = 0;
	int x = 0;
	int y = 0;
	head = tetrimo;
	/* while (tetrimo)
	{
		if (tetrimo->tetriski[i] == '#')
		{
			x++;			
		}
		if (tetrimo->tetriski[i] == '\n' && tetrimo->tetriski[i + 1] != '\n')
			tetrimo->dot[y] = tetrimo->dot[y + 1];
		if (tetrimo->count == 3 && tetrimo->tetriski[i] == '\0')
			break ;
		if (tetrimo->tetriski[i] == '\n' && tetrimo->tetriski[i + 1] == '\n')
		{
			tetrimo = tetrimo->next;
			i = 0;
		}
	}
	tetrimo = head; */
}