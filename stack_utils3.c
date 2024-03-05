/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:38:40 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 17:59:55 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->index = i;
		i++;
		a = a->next;
	}
}

void	set_pvl_stack(t_stack *a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*curr;

	curr = a;
	while (curr)
	{
		i = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->num < curr->num)
				i++;
			tmp = tmp->next;
		}
		curr->pvl = i;
		curr = curr->next;
	}
}

void	get_min_to_top(t_stack **a)
{
	t_stack	*min;

	index_stack(*a);
	min = find_max_min(*a, 'm');
	while ((*a) != min)
	{
		if (min->index > ft_stack_size(*a) / 2)
			rev_rotate(a, a, 'a', 0);
		else
			rotate(a, a, 'a', 0);
	}
}

void	set_cost(t_stack *a, int size_a, int size_b)
{
	while (a)
	{
		a->cost = a->index;
		if (a->index > size_a / 2)
			a->cost = size_a - a->index;
		if (a->target->index <= size_b / 2)
			a->cost += a->target->index;
		else
			a->cost += size_b - a->target->index;
		a = a->next;
	}
}

t_stack	*find_cheapest_node(t_stack *a, int size_a, int size_b)
{
	int		lowest;
	t_stack	*lowest_cost;

	set_cost(a, size_a, size_b);
	lowest = a->cost;
	lowest_cost = a;
	while (a && lowest)
	{
		if (a->cost <= lowest)
		{
			lowest = a->cost;
			lowest_cost = a;
		}
		a = a->next;
	}
	return (lowest_cost);
}
