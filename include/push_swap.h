/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psharen <psharen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/01/01 20:20:20 by psharen           #+#    #+#             */
/*   Updated: 2000/01/01 20:20:20 by psharen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

// Cycled stack
typedef struct s_cstack
{
	t_dlist	*stack;
	int		size;
}	t_cstack;

typedef struct s_state
{
	t_cstack	*a;
	t_cstack	*b;
	int			*arr;
}	t_state;

// array
int		*sort(int arr[], int n);
int		is_sorted_array(int arr[], int n);
int		if_has_duplicates(int sorted_arr[], int n);

// doubly linked list
t_dlist	*ft_dlstnew_int(int data);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);

// init
void	init_state(t_state *state, int argc);
void	fill_stack(t_cstack *cs, int arr[], int n);
int		check_and_fill(int arr[], int argc, const char *argv[]);

// operations
void	pa(t_state *s);
void	pb(t_state *s);
void	ra(t_state *s);
void	rb(t_state *s);
void	rr(t_state *s);

// sort
void	sort_and_print_big(t_state *s);
int		find_elem(t_dlist *stack, int elem);
void	rotate_many(t_cstack *cs, int offset, char *stack_name);

// stack
void	push(t_cstack *cs, t_dlist *elem);
void	push_front(t_cstack *cs, t_dlist *elem);
t_dlist	*pop(t_cstack *cs);
void	swap(t_cstack *cs);
int		is_sorted_cstack(t_cstack *cs);

// utils
void	mem_error(void);
double	lerp(double a, double b, double t);
int		binary_search(int sorted_arr[], int n, int elem);
int		ft_atoi_safe(const char *str, int *err);
int		is_num(const char *s);

#endif
