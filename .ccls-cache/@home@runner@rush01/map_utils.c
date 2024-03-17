#include "rush01.h"

#include <stdlib.h>

int	get_size(char *argv1)
{
	int	len;

	len = ft_strlen(argv1);
	if ((len + 1) % 8 != 0)
		return (-1);
	return ((len + 1) / 8);
}
