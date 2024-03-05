/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:25:36 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 17:39:03 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a, t_stack **b, t_stack *max)
{
	if (*a == max)
		rotate(a, b, 'a', 0);
	else if ((*a)->next == max)
		rev_rotate(a, b, 'a', 0);
	if ((*a)->num > (*a)->next->num)
		swap(a, b, 'a', 0);
}

void	turk_sort(t_stack **a, t_stack **b, int size)
{
	int	median;

	median = (size / 2);
	set_pvl_stack(*a);
	while (size > 3 && !is_sorted(*a))
	{
		ft_handle_target_a(a, b, median);
		size--;
	}
	ft_sort_three(a, b, find_max_min(*a, 'M'));
	while (*b)
	{
		index_stack(*a);
		index_stack(*b);
		ft_handle_target_b(a, b);
	}
	get_min_to_top(a);
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->num > (*a)->next->num)
			swap(a, b, 'a', 0);
	}
	else if (size == 3)
		ft_sort_three(a, b, find_max_min(*a, 'M'));
	else if (size >= 4)
		turk_sort(a, b, size);
}
