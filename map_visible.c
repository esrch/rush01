#include "solver.h"

int	map_visible_top(int *map, int size, int col, int *first_index_out)
{
	int	visible;
	int	max;
	int	first_index;
	int	i;
	int	value;

	visible = 0;
	max = 0;
	first_index = -1;
	i = 0;
	while (i < size)
	{
		value = map_at(map, size, i, col);
		if (value != 0 && first_index == -1)
			first_index = i;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index_out = first_index;
	return (visible);
}

int	map_visible_bottom(int *map, int size, int col, int *first_index_out)
{
	int	visible;
	int	max;
	int	first_index;
	int	i;
	int	value;

	visible = 0;
	max = 0;
	first_index = -1;
	i = size;
	while (i-- > 0)
	{
		value = map_at(map, size, i, col);
		if (value != 0 && first_index == -1)
			first_index = size - i - 1;
		if (value > max)
		{
			max = value;
			visible++;
		}
	}
	*first_index_out = first_index;
	return (visible);
}

int	map_visible_left(int *map, int size, int row, int *first_index_out)
{
	int	visible;
	int	max;
	int	first_index;
	int	i;
	int	value;

	visible = 0;
	max = 0;
	first_index = -1;
	i = 0;
	while (i < size)
	{
		value = map_at(map, size, row, i);
		if (value != 0 && first_index == -1)
			first_index = i;
		if (value > max)
		{
			max = value;
			visible++;
		}
		i++;
	}
	*first_index_out = first_index;
	return (visible);
}

int	map_visible_right(int *map, int size, int row, int *first_index_out)
{
	int	visible;
	int	max;
	int	first_index;
	int	i;
	int	value;

	visible = 0;
	max = 0;
	first_index = -1;
	i = size;
	while (i-- > 0)
	{
		value = map_at(map, size, row, i);
		if (value != 0 && first_index == -1)
			first_index = size - i - 1;
		if (value > max)
		{
			max = value;
			visible++;
		}
	}
	*first_index_out = first_index;
	return (visible);
}
