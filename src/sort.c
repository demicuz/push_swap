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

#include "libft.h"
#include <push_swap.h>

static int	get_window(int n)
{
	double	t;

	if (n >= 100)
	{
		t = (n - 100) / 400.0;
		return (lerp(12, 30, t));
	}
	else if (n >= 50)
	{
		t = (n - 50) / 50.0;
		return (lerp(8, 12, t));
	}
	else if (n >= 10)
	{
		t = (n - 10) / 40.0;
		return (lerp(5, 8, t));
	}
	else
		return (5);
}

int	find_elem(t_dlist *stack, int elem)
{
	int		i;
	int		j;
	t_dlist	*p;

	i = 0;
	p = stack;
	while (p->data != elem)
	{
		p = p->next;
		i++;
	}
	j = 0;
	p = stack;
	while (p->data != elem)
	{
		p = p->prev;
		j++;
	}
	if (i <= j)
		return (i);
	else
		return (-j);
}

// Three write() calls. Ridiculous
void	rotate_many(t_cstack *cs, int offset, char *stack_name)
{
	int	i;

	i = 0;
	if (offset > 0)
	{
		while (i++ < offset)
		{
			cs->stack = cs->stack->next;
			if (*stack_name == 'b')
				ft_putstr("rb\n");
			else
				ft_putstr("ra\n");
		}
	}
	else
	{
		while (i++ < -offset)
		{
			cs->stack = cs->stack->prev;
			if (*stack_name == 'b')
				ft_putstr("rrb\n");
			else
				ft_putstr("rra\n");
		}
	}
}

static void	seek_and_push_all(t_state *s)
{
	int	offset;

	while (s->b->size > 0)
	{
		offset = find_elem(s->b->stack, s->b->size - 1);
		rotate_many(s->b, offset, "b");
		pa(s);
	}
}

// haha not readable
// s->a->stack->data is the first element in stack 'a'. And initially it's
// filled with INDICES of values. So when we compare it with s->b->size it
// magically works.
void	sort_and_print_big(t_state *s)
{
	int	window;

	window = get_window(s->a->size);
	while (s->a->size > 0)
	{
		if (s->a->stack->data < s->b->size)
		{
			pb(s);
			if (s->a->size > 1 && s->a->stack->data >= s->b->size + window)
				rr(s);
			else
				rb(s);
		}
		else if (s->a->stack->data < s->b->size + window)
			pb(s);
		else
			ra(s);
	}
	seek_and_push_all(s);
}
