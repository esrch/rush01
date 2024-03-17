#ifndef SOLVER_H
# define SOLVER_H

// Utils
int		ft_strlen(char *s);

// Map utils
int		get_size(char *argv1);
int		*init_map(int size);
int		map_at(int *map, int size, int row, int col);
void	print_map(int *map, int size);

// Constraints
int	*init_constraints(char *argv1, int size);

// Solver
int	solve_map(int *map, int *constraints, int size, int index);

// Map visible
int	map_visible_top(int *map, int size, int col, int *first_index_out);
int	map_visible_bottom(int *map, int size, int col, int *first_index_out);
int	map_visible_left(int *map, int size, int row, int *first_index_out);
int	map_visible_right(int *map, int size, int row, int *first_index_out);

// Validators
int	is_unique_in_col(int *map, int size, int row, int col);
int	is_valid_top(int *map, int *constraints, int size, int col);
int	is_valid_bottom(int *map, int *constraints, int size, int col);
int	is_valid_left(int *map, int *constraints, int size, int row);
int	is_valid_right(int *map, int *constraints, int size, int row);

#endif