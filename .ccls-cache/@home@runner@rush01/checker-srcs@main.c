#include "checker.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *read_contents(void)
{
	int		bytes;
	char	buf[4096];
	char	*contents_str;

	bytes = read(STDIN_FILENO, buf, 4095);
	if (buf[bytes - 1] == '\n')
		buf[bytes - 1] = '\0';
	else
		buf[bytes] = '\0';
	contents_str = (char *) malloc(sizeof(*contents_str) * (strlen(buf) + 1));
	if (!contents_str)
		return (NULL);
	strcpy(buf, contents_str);
	return (contents_str);
}

int main(int argc, char **argv)
{
	t_map	*map;
	
	if (argc != 2)
	{
		printf("Usage: %s [constraints]\n", argv[0]);
		return (1);
	}
	map = map_create(argv[1]);
	if (!map)
		return (1);
	map_print_constraints(map);
	map_destroy(map);
}