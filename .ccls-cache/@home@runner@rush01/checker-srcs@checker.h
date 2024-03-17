#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_int_list
{
	struct s_int_list	*next;
	int					num;
}	t_int_list;

typedef struct s_map
{
	size_t	size;
	int		*constraints;
	int		*contents;
}	t_map;

// Int list
int			int_list_add(t_int_list **list, int num);
void		int_list_destroy(t_int_list *list);
t_int_list	*int_list_last(t_int_list *list);
size_t		int_list_len(t_int_list *list);
int			*int_list_to_arr(t_int_list *list);

// Map
t_map		*map_create(char *constraints_str);
void		map_destroy(t_map *map);

// Map valid
bool		map_valid_constraints(t_map *map);

// Map print
void		map_print_constraints(t_map *map);

// Map utils
int			map_at(t_map *map, size_t row, size_t col);

// Map constraints
int			*map_constraints_top(t_map *map);
int			*map_constraints_bottom(t_map *map);
int			*map_constraints_left(t_map *map);
int			*map_constraints_right(t_map *map);

// Utils
size_t		int_arr_len(int *arr);

#endif