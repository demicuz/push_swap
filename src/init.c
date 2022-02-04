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

#include <push_swap.h>

void	init_state(t_state *state, int argc)
{
	t_cstack	*a;
	t_cstack	*b;
	int			*arr;

	a = malloc(sizeof(t_cstack));
	b = malloc(sizeof(t_cstack));
	arr = malloc(argc * sizeof(int));
	if (!a || !b || !arr)
	{
		free(a);
		free(b);
		free(arr);
		mem_error();
	}
	a->stack = NULL;
	b->stack = NULL;
	a->size = 0;
	b->size = 0;
	state->a = a;
	state->b = b;
	state->arr = arr;
}

void	fill_stack(t_cstack *cs, int arr[], int n)
{
	int		i;
	t_dlist	*elem;

	i = 0;
	while (i < n)
	{
		elem = ft_dlstnew_int(arr[i]);
		if (!elem)
			mem_error();
		push_front(cs, elem);
		i++;
	}
}

static int	parse_input(int arr[], int argc, const char *argv[])
{
	int	i;
	int	num;
	int	err;

	i = 0;
	err = 0;
	while (i < argc)
	{
		num = ft_atoi_safe(argv[i], &err);
		if (!is_num(argv[i]) || err)
			return (0);
		arr[i] = num;
		i++;
	}
	return (1);
}

static void	fill_indices(int indices[], int n, int arr[], int arr_sorted[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		indices[i] = binary_search(arr_sorted, n, arr[i]);
		i++;
	}
}

// What an ugly piece of code. Would be much better with do/while
int	check_and_fill(int arr[], int argc, const char *argv[])
{
	int	*temp;
	int	*temp_sorted;

	temp = malloc(argc * sizeof(int));
	if (!temp)
		mem_error();
	if (!parse_input(temp, argc, argv))
	{
		free(temp);
		return (0);
	}
	temp_sorted = sort(temp, argc);
	if (if_has_duplicates(temp_sorted, argc))
	{
		free(temp);
		free(temp_sorted);
		return (0);
	}
	fill_indices(arr, argc, temp, temp_sorted);
	free(temp);
	free(temp_sorted);
	return (1);
}
