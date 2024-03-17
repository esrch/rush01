#include "solver.h"

#include <stdlib.h>
#include <unistd.h>

int	get_size(char *argv1)
{
	int	len;

	len = ft_strlen(argv1);
	if ((len + 1) % 8 != 0)
		return (-1);
	return ((len + 1) / 8);
}

int	*init_map(int size)
{
	int	*map;
	int	i;

	map = malloc(sizeof(*map) * (size * size));
	if (!map)
		return (NULL);
	i = 0;
	while (i < size * size)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}

int	map_at(int *map, int size, int row, int col)
{
	return (map[row * size + col]);
}

void	print_map(int *map, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		if (i > 0 && i % size == 0)
			(void) write(STDOUT_FILENO, "\n", 1);
		(void) write(STDOUT_FILENO, &"0123456789"[map[i]], 1);
		(void) write(STDOUT_FILENO, " ", 1);
		i++;
	}
	(void) write(STDOUT_FILENO, "\n", 1);
}