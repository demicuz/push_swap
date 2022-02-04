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
#include <unistd.h>

void	sort_and_print_2(t_state *s)
{
	t_dlist	*first;

	first = s->a->stack;
	if (first->data > first->next->data)
	{
		swap(s->a);
		ft_putstr("sa\n");
	}
}

// Need to add total_size bc -1 % 3 is -1, not 2
void	sort_and_print_3(t_state *s)
{
	t_dlist	*first;
	int		total_size;

	first = s->a->stack;
	total_size = s->a->size + s->b->size;
	if (first->data != (first->next->data - 1 + total_size) % total_size)
	{
		swap(s->a);
		ft_putstr("sa\n");
	}
	if (!is_sorted_cstack(s->a))
	{
		if (find_elem(s->a->stack, s->b->size) > 0)
			ra(s);
		else
		{
			s->a->stack = s->a->stack->prev;
			ft_putstr("rra\n");
		}
	}
}

// void	sort_and_print_5(t_state *s)
// {
	
// }

void	sort_and_print(t_state *s)
{
	if (s->a->size == 2)
		sort_and_print_2(s);
	else if (s->a->size == 3)
		sort_and_print_3(s);
	else
		sort_and_print_big(s);
}


int	main(int argc, const char *argv[])
{
	t_state	s;

	if (argc == 1)
		return (0);
	init_state(&s, argc);
	if (!check_and_fill(s.arr, argc - 1, &argv[1]))
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (is_sorted_array(s.arr, argc - 1))
		exit(EXIT_SUCCESS);
	fill_stack(s.a, s.arr, argc - 1);
	sort_and_print(&s);
	exit(EXIT_SUCCESS);
}
