#include "checker.h"

int	map_at(t_map *map, size_t row, size_t col)
{
	if (row < 1 || row >= map->size || col < 1 || col >= map->size)
		return (-1);
	return (map->contents[row * map->size + col]);
}
