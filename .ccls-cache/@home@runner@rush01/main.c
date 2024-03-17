#include <stdlib.h>
#include <unistd.h>

#include "solver.h"

int	handle_error(int *constraints)
{
	if (constraints)
		free(constraints);
	(void) write(STDOUT_FILENO, "Error.\n", 7);
	return (1);
}

int main(int argc, char **argv) {
	int	size;
	int	*constraints;
	int	*map;

	if (argc != 2)
		return (handle_error(NULL));
	size = get_size(argv[1]);
	if (size == -1)
		return (handle_error(NULL));
	constraints = init_constraints(argv[1], size);
	if (!constraints)
		return (handle_error(NULL));
	map = init_map(size);
	if (!map)
		return (handle_error(constraints));
	if (solve_map(map, constraints, size, 0) == 0)
		print_map(map, size);
	else
		(void) write(STDOUT_FILENO, "No solution found.\n", 19);
	free(constraints);
	free(map);
}