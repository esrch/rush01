#ifndef COMMON_H
# define COMMON_H

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


#endif