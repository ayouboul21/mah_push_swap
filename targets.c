/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:17 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 17:40:00 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_targets_b(t_stack *b, t_stack *a)
{
	long	match;
	t_stack	*target;
	t_stack	*tmp;

	while (b)
	{
		(1 == 1) && (match = LONG_MAX, tmp = a);
		while (tmp)
		{
			if (tmp->num < match && tmp->num > b->num)
			{
				match = tmp->num;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (match == LONG_MAX)
			b->target = find_max_min(a, 'm');
		else
			b->target = target;
		b = b->next;
	}
}

void	fix_stack(t_stack **a, int median, t_stack *cheapest)
{
	while (*a != cheapest->target)
	{
		if (cheapest->target->index <= median)
			rotate(a, a, 'a', 0);
		else
			rev_rotate(a, a, 'a', 0);
	}
}

void	ft_handle_target_a(t_stack **a, t_stack **b, int mid_av)
{
	if ((*a)->pvl > mid_av)
	{
		push(b, a, 'b');
		rotate(a, b, 'b', 0);
	}
	else
		push(b, a, 'b');
}

void	ft_handle_target_b(t_stack **a, t_stack **b)
{
	int		median_a;
	int		median_b;
	t_stack	*cheapest;

	(1 == 1) && (median_a = ft_stack_size(*a) / 2,
		median_b = ft_stack_size(*b) / 2);
	find_targets_b(*b, *a);
	cheapest = find_cheapest_node(*b, ft_stack_size(*b), ft_stack_size(*a));
	while (*b != cheapest)
	{
		if (*a != cheapest->target && cheapest->index <= median_b
			&& cheapest->target->index <= median_a)
			rotate(a, b, 'r', 0);
		else if (*a != cheapest->target && cheapest->index > median_b
			&& cheapest->target->index > median_a)
			rev_rotate(a, b, 'r', 0);
		else if (cheapest->index <= median_b)
			rotate(a, b, 'b', 0);
		else
			rev_rotate(a, b, 'b', 0);
	}
	fix_stack(a, median_a, cheapest);
	push(a, b, 'a');
}
