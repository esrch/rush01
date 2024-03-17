#include "solver.h"

#include <stdio.h>

static int	is_valid_placement(int *map, int *constraints, int size,
	int map_index)
{
	int	row;
	int	col;

	row = map_index / size;
	col = map_index % size;
	return (
		is_unique_in_col(map, size, row, col)
		&& is_valid_top(map, constraints, size, col)
		&& is_valid_bottom(map, constraints, size, col)
		&& is_valid_left(map, constraints, size, row)
		&& is_valid_right(map, constraints, size, row));
}

int	solve_map(int *map, int *constraints, int size, int index)
{
	int	digit;
	int	row;
	int col;

	if (index >= size * size)
		return (0);
	digit = size - index / size;
	row = index % size;
	col = 0;
	while (col < size)
	{
		if (map[row * size + col] == 0)
		{
			map[row * size + col] = digit;
			if (is_valid_placement(map, constraints, size, size * row + col))
			{
				if (solve_map(map, constraints, size, index + 1) == 0)
					return (0);
			}
			map[row * size + col] = 0;
		}
		col++;
	}
	return (-1);
}