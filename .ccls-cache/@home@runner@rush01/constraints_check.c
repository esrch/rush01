#include "rush01.h"

int	is_valid_top(int *map, int *constraints, int size, int col)
{
	int	i;
	int	max;
	int	visible;
	int	first_digit_index;

	i = -1;
	max = 0;
	visible = 0;
	first_digit_index = -1;
	while (++i < size)
	{
		if (first_digit_index == -1 && map_at(map, size, i, col) != 0)
			first_digit_index = i;
		if (map_at(map, size, i, col) > max)
			visible++;
		if (map_at(map, size, i, col) > max)
			max = map_at(map, size, i, col);
	}
	if (constraints[col] > visible + first_digit_index)
		return (0);
	if (constraints[col] < visible + (first_digit_index != 0))
		return (0);
	return (1);
}

int	is_valid_bottom(int *map, int *constraints, int size, int col)
{
	int	i;
	int	max;
	int	visible;
	int	first_digit_index;

	i = size;
	max = 0;
	visible = 0;
	first_digit_index = -1;
	while (--i >= 0)
	{
		if (first_digit_index == -1 && map_at(map, size, i, col) != 0)
			first_digit_index = i;
		if (map_at(map, size, i, col) > max)
			visible++;
		if (map_at(map, size, i, col) > max)
			max = map_at(map, size, i, col);
	}
	if (constraints[size + col] > visible + first_digit_index)
		return (0);
	if (constraints[size + col] < visible + (first_digit_index != 0))
		return (0);
	return (1);
}

int	is_valid_left(int *map, int *constraints, int size, int row)
{
	int	i;
	int	max;
	int	visible;
	int	first_digit_index;

	i = -1;
	max = 0;
	visible = 0;
	first_digit_index = -1;
	while (++i < size)
	{
		if (first_digit_index == -1 && map_at(map, size, row, i) != 0)
			first_digit_index = i;
		if (map_at(map, size, row, i) > max)
			visible++;
		if (map_at(map, size, row, i) > max)
			max = map_at(map, size, row, i);
	}
	if (constraints[2 * size + row] > visible + first_digit_index)
		return (0);
	if (constraints[2 * size + row] < visible + (first_digit_index != 0))
		return (0);
	return (1);
}

int	is_valid_right(int *map, int *constraints, int size, int row)
{
	int	i;
	int	max;
	int	visible;
	int	first_digit_index;

	i = size;
	max = 0;
	visible = 0;
	first_digit_index = -1;
	while (--i >= 0)
	{
		if (first_digit_index == -1 && map_at(map, size, row, i) != 0)
			first_digit_index = i;
		if (map_at(map, size, row, i) > max)
			visible++;
		if (map_at(map, size, row, i) > max)
			max = map_at(map, size, row, i);
	}
	if (constraints[3 * size + row] > visible + first_digit_index)
		return (0);
	if (constraints[3 * size + row] < visible + (first_digit_index != 0))
		return (0);
	return (1);
}
