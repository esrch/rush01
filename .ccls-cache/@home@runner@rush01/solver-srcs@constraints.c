#include "solver.h"

#include <stdlib.h>

static int	*get_constraints_error(int *constraints)
{
	free(constraints);
	return (NULL);
}

int	*init_constraints(char *argv1, int size)
{
	int	*constraints;
	int	i;
	int	digit;

	constraints = malloc(sizeof(*constraints) * (size * 4));
	if (!constraints)
		return (NULL);
	i = 0;
	while (i < size * 4)
	{
		if (i > 0 && argv1[i * 2 - 1] != ' ')
			return (get_constraints_error(constraints));
		if (argv1[i * 2] < '0' || argv1[i * 2] > '9')
			return (get_constraints_error(constraints));
		digit = argv1[i * 2] - '0';
		if (digit < 1 || digit > size)
			return (get_constraints_error(constraints));
		constraints[i] = digit;
		i++;
	}
	return (constraints);
}