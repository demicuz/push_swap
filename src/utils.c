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

#include <limits.h>
#include <push_swap.h>

void	mem_error(void)
{
	ft_putstr_fd("Memory error\n", 2);
	exit(EXIT_FAILURE);
}

double	lerp(double a, double b, double t)
{
	return (a + (b - a) * t);
}

int	binary_search(int sorted_arr[], int n, int elem)
{
	int	i;
	int	left;
	int	right;

	if (!sorted_arr || n == 0)
		return (-1);
	left = 0;
	right = n;
	i = (left + right) / 2;
	while (sorted_arr[i] != elem && left != right)
	{
		if (sorted_arr[i] < elem)
			left = (left + right + 1) / 2;
		else
			right = (left + right) / 2;
		i = (left + right) / 2;
	}
	if (sorted_arr[i] == elem)
		return (i);
	else
		return (-1);
}

int	is_num(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	return (*s == '\0');
}

int	ft_atoi_safe(const char *str, int *err)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0') * sign;
		if (result > INT_MAX || result < INT_MIN)
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	return (result);
}
