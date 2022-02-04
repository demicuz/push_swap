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

void	pa(t_state *s)
{
	push(s->a, pop(s->b));
	ft_putstr("pa\n");
}

void	pb(t_state *s)
{
	push(s->b, pop(s->a));
	ft_putstr("pb\n");
}

void	ra(t_state *s)
{
	s->a->stack = s->a->stack->next;
	ft_putstr("ra\n");
}

void	rb(t_state *s)
{
	s->b->stack = s->b->stack->next;
	ft_putstr("rb\n");
}

void	rr(t_state *s)
{
	s->a->stack = s->a->stack->next;
	s->b->stack = s->b->stack->next;
	ft_putstr("rr\n");
}
