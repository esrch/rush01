#include "checker.h"

#include <stdbool.h>

bool map_valid_constraints(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size * 4)
	{
		if (map->constraints[i] < 1 || map->constraints[i] > (int) map->size)
			return (false);
		i++;
	}
	return (true);
}