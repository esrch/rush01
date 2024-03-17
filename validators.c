#include "solver.h"

int	is_unique_in_col(int *map, int size, int row, int col)
{
	int	value;
	int	i;

	value = map_at(map, size, row, col);
	i = 0;
	while (i < size)
	{
		if (map_at(map, size, i, col) == value && i != row)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_top(int *map, int *constraints, int size, int col)
{
	int	visible;
	int	first_digit_index;
	int	min_constraint;
	int	max_constraint;

	visible = map_visible_top(map, size, col, &first_digit_index);
	if (first_digit_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	max_constraint = visible + first_digit_index;
	if (constraints[col] < min_constraint
		|| constraints[col] > max_constraint)
		return (0);
	return (1);
}

int	is_valid_bottom(int *map, int *constraints, int size, int col)
{
	int	visible;
	int	first_digit_index;
	int	min_constraint;
	int	max_constraint;

	visible = map_visible_bottom(map, size, col, &first_digit_index);
	if (first_digit_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	max_constraint = visible + first_digit_index;
	if (constraints[size + col] < min_constraint
		|| constraints[size + col] > max_constraint)
		return (0);
	return (1);
}

int	is_valid_left(int *map, int *constraints, int size, int row)
{
	int	visible;
	int	first_digit_index;
	int	min_constraint;
	int	max_constraint;

	visible = map_visible_left(map, size, row, &first_digit_index);
	if (first_digit_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	max_constraint = visible + first_digit_index;
	if (constraints[2 * size + row] < min_constraint
		|| constraints[2 * size + row] > max_constraint)
		return (0);
	return (1);
}

int	is_valid_right(int *map, int *constraints, int size, int row)
{
	int	visible;
	int	first_digit_index;
	int	min_constraint;
	int	max_constraint;

	visible = map_visible_right(map, size, row, &first_digit_index);
	if (first_digit_index == 0)
		min_constraint = visible;
	else
		min_constraint = visible + 1;
	max_constraint = visible + first_digit_index;
	if (constraints[3 * size + row] < min_constraint
		|| constraints[3 * size + row] > max_constraint)
		return (0);
	return (1);
}

