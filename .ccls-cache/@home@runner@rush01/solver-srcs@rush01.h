#ifndef RUSH01_H
# define RUSH01_H

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

// Validators
int	is_unique_in_col(int *map, int size, int row, int col);
int	is_valid_top(int *map, int *constraints, int size, int col);
int	is_valid_bottom(int *map, int *constraints, int size, int col);
int	is_valid_left(int *map, int *constraints, int size, int row);
int	is_valid_right(int *map, int *constraints, int size, int row);

#endif