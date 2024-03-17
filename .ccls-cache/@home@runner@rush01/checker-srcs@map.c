#include "checker.h"

#include <stdlib.h>
#include <stdio.h>

static t_map *map_create_error(char *msg, t_map *map)
{
	fprintf(stderr, "%s\n", msg);
	if (!map)
		return (NULL);
	free(map->constraints);
	free(map->contents);
	free(map);
	return (NULL);
}

static int extract_num(char *constraints_str, t_int_list **num_list)
{
	char	*start;
	char	tmp_char;
	int		num;

	start = constraints_str;
	while (*constraints_str && *constraints_str != ' ')
	{
		if (*constraints_str < '0' || *constraints_str > '9')
			return (-1);
		constraints_str++;
	}
	tmp_char = *constraints_str;
	*constraints_str = '\0';
	num = atoi(start);
	*constraints_str = tmp_char;
	if (int_list_add(num_list, num) != 0)
		return (-1);
	return (constraints_str - start);
}

static int *build_constraints(char *constraints_str)
{
	int			*constraints;
	t_int_list	*num_list;
	int			len;

	num_list = NULL;
	while (*constraints_str)
	{
		if (*constraints_str == ' ')
			constraints_str++;
		else
		{
			len = extract_num(constraints_str, &num_list);
			if (len < 0)
			{
				int_list_destroy(num_list);
				return (NULL);
			}
			constraints_str += len;
		}
	}
	constraints = int_list_to_arr(num_list);
	int_list_destroy(num_list);
	return (constraints);
}

t_map *map_create(char *constraints_str)
{
	t_map	*map;
	size_t	len;

	map = (t_map *) malloc(sizeof(*map));
	if (!map)
		return (map_create_error("Error: Allocation error.", map));
	map->contents = NULL;
	map->constraints = build_constraints(constraints_str);
	if (!map->constraints)
		return (map_create_error("Error: System error while generating constraints.", map));
	len = int_arr_len(map->constraints);
	if (len == 0)
		return (map_create_error("Error: Empty constraints.", map));
	if (len % 4 != 0)
		return (map_create_error("Error: Invalid number of constraints.", map));
	map->size = len / 4;
	map->contents = (int *) malloc(sizeof(int) * (map->size * map->size + 1));
	if (!map->contents)
		return (map_create_error(" Error: Allocation error.", map));
	return (map);
}

void map_destroy(t_map *map)
{
	free(map->constraints);
	free(map->contents);
	free(map);
}
