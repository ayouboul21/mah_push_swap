/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:30:21 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/18 18:35:38 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_stack *stack)
{
	int		i;
	int		*tab;
	int		size;

	if (!stack)
		return (1);
	tab = (int *)malloc(ft_stack_size(stack) * sizeof(int));
	if (!tab)
		return (1);
	i = 0;
	while (stack)
	{
		size = i;
		while (size--)
			if (stack->num == tab[size])
				return (free(tab), 1);
		tab[i++] = stack->num;
		stack = stack->next;
	}
	free(tab);
	return (0);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!new)
		return ;
	else if (stack && !(*stack))
	{
		*stack = new;
		new->next = NULL;
		new->last = new;
	}
	else if (stack)
	{
		new->next = tmp;
		new->last = tmp->last;
		*stack = new;
	}
}

t_stack	*ft_find_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	if (!stack->next)
		return (NULL);
	return (stack);
}

t_stack	*find_max_min(t_stack *stack, char mode)
{
	t_stack	*res;

	res = stack;
	if (mode == 'm')
	{
		while (stack)
		{
			if (res->num > stack->num)
				res = stack;
			stack = stack->next;
		}
	}
	else if (mode == 'M')
	{
		while (stack)
		{
			if (res->num < stack->num)
				res = stack;
			stack = stack->next;
		}
	}
	return (res);
}
