#ifndef PUSH_H
# define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				rank;
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*first;
}					t_stack;

// utils
char				**split_nums(int ac, char *av[]);
void				indeex(t_stack *stack);
long				ft_atoi(const char *nptr, int *error);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				free_stack(t_stack *stack);
int					free_tab(char **tab);

// parsing
int					hdup(char **nums);
int					verif(char **nums);
t_node				*new_node(int value);
void				add_back(t_stack *stack, t_node *node);
// FIX: signature mise à jour — pars reçoit les deux stacks
void				pars(char **nums, t_stack *a, t_stack *b, int ac);

// moves
void				push(t_stack *src, t_stack *dst);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				rev_rot(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// algos
void				sort_three(t_stack *a);
int					push_min(t_stack *a, t_stack *b, int rank);
int					find_pos(t_stack *a, int rank);
void				sort_five(t_stack *a, t_stack *b);
void				k_sort(t_stack *a, t_stack *b);
int					find_max(t_stack *stack);

#endif
