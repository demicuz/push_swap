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

// God I love Norminette. You can't pass more than 4 variables to functions and
// they shouldn't be longer than 25 lines. And you can't assign varialbes on the
// same line you declare them. Now try to unsee lines 41-42. HA!
static void	merge(int arr[], int temp[], int left, int right)
{
	int	i;
	int	j;
	int	k;
	int	mid;

	mid = (right + left) / 2 + 1;
	i = left;
	j = mid;
	k = left;
	while (i <= mid - 1 && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	i = left;
	while (i++ <= right)
		arr[i - 1] = temp[i - 1];
}

static void	merge_sort(int arr[], int temp[], int left, int right)
{
	int	mid;

	mid = 0;
	if (right > left)
	{
		mid = (right + left) / 2;
		merge_sort(arr, temp, left, mid);
		merge_sort(arr, temp, mid + 1, right);
		merge(arr, temp, left, right);
	}
}

int	*sort(int arr[], int n)
{
	int	*temp;
	int	*sorted;

	temp = malloc(n * sizeof(int));
	sorted = malloc(n * sizeof(int));
	if (!temp || !sorted)
		mem_error();
	sorted = ft_memcpy_int(sorted, arr, n * sizeof(int));
	merge_sort(sorted, temp, 0, n - 1);
	free(temp);
	return (sorted);
}

int	is_sorted_array(int arr[], int n)
{
	int	i;

	if (n <= 1)
		return (1);
	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	if_has_duplicates(int sorted_arr[], int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (sorted_arr[i] == sorted_arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}
