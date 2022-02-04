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
#include <unistd.h>

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