#include "checker.h"

int *map_constraints_top(t_map *map)
{
	return (map->constraints);
}

int *map_constraints_bottom(t_map *map)
{
	return (&map->constraints[map->size]);
}

int *map_constraints_left(t_map *map)
{
	return (&map->constraints[2 * map->size]);
}

int *map_constraints_right(t_map *map)
{
	return (&map->constraints[3 * map->size]);
}