#include "checker.h"

#include <stdio.h>

static void map_print_constraints_dim(char *title, int *constraints, size_t size)
{
	size_t	i;

	i = 0;
	printf("%s: ", title);
	while (i < size)
	{
		if (i != 0)
			printf(" ");
		printf("%d", constraints[i]);
		i++;
	}
	printf("\n");
}

void map_print_constraints(t_map *map)
{
	if (!map)
		return ;
	map_print_constraints_dim("Top", map_constraints_top(map), map->size);
	map_print_constraints_dim("Bottom", map_constraints_bottom(map), map->size);
	map_print_constraints_dim("Left", map_constraints_left(map), map->size);
	map_print_constraints_dim("Right", map_constraints_right(map), map->size);
}