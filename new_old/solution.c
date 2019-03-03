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