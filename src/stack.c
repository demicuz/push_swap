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

void	push(t_cstack *cs, t_dlist *elem)
{
	t_dlist	*head;

	if (!cs || !elem)
		return ;
	if (cs->size == 0)
	{
		elem->next = elem;
		elem->prev = elem;
	}
	else
	{
		head = cs->stack;
		elem->next = head;
		elem->prev = head->prev;
		head->prev = elem;
		elem->prev->next = elem;
	}
	cs->size++;
	cs->stack = elem;
}

void	push_front(t_cstack *cs, t_dlist *elem)
{
	push(cs, elem);
	cs->stack = cs->stack->next;
}

t_dlist	*pop(t_cstack *cs)
{
	t_dlist	*elem;

	if (!cs || cs->size == 0)
		return (NULL);
	elem = cs->stack;
	if (cs->size > 1)
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		cs->stack = elem->next;
	}
	else
		cs->stack = NULL;
	cs->size--;
	return (elem);
}

// Swap two upper elements
// For 1 and 0 elements do nothing
void	swap(t_cstack *cs)
{
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*third;
	t_dlist	*last;

	if (cs->size < 2)
		return ;
	first = cs->stack;
	second = first->next;
	if (cs->size > 2)
	{
		third = second->next;
		last = first->prev;
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = last;
		third->prev = first;
		last->next = second;
	}
	cs->stack = second;
}

int	is_sorted_cstack(t_cstack *cs)
{
	t_dlist	*p;
	t_dlist	*last;

	if (cs->size < 2)
		return (1);
	p = cs->stack;
	last = cs->stack->prev;
	while (p != last)
	{
		if (p->data > p->next->data)
			return (0);
		p = p->next;
	}
	return (1);
}
