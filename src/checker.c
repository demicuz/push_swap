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
#include <get_next_line.h>
#include <unistd.h>

int	do_op_2(t_state *s, char *line)
{
	if (ft_strcmp(line, "rr\n") == 0)
	{
		if (s->a->size > 0)
			s->a->stack = s->a->stack->next;
		if (s->b->size > 0)
			s->b->stack = s->b->stack->next;
	}
	else if (ft_strcmp(line, "rra\n") == 0 && s->a->size > 0)
		s->a->stack = s->a->stack->prev;
	else if (ft_strcmp(line, "rrb\n") == 0 && s->b->size > 0)
		s->b->stack = s->b->stack->prev;
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		if (s->a->size > 0)
			s->a->stack = s->a->stack->prev;
		if (s->b->size > 0)
			s->b->stack = s->b->stack->prev;
	}
	else
		return (0);
	return (1);
}

int	do_op(t_state *s, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(s->a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(s->b);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		swap(s->a);
		swap(s->b);
	}
	else if (ft_strcmp(line, "pa\n") == 0)
		push(s->a, pop(s->b));
	else if (ft_strcmp(line, "pb\n") == 0)
		push(s->b, pop(s->a));
	else if (ft_strcmp(line, "ra\n") == 0 && s->a->size > 0)
		s->a->stack = s->a->stack->next;
	else if (ft_strcmp(line, "rb\n") == 0 && s->b->size > 0)
		s->b->stack = s->b->stack->next;
	else
		return (do_op_2(s, line));
	return (1);
}

void	check_ops(t_state *s)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!do_op(s, line))
		{
			ft_putstr("Error\n");
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted_cstack(s->a) && s->b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
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
	fill_stack(s.a, s.arr, argc - 1);
	check_ops(&s);
	exit(EXIT_SUCCESS);
}
