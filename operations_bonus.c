/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:28:49 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/18 18:20:28 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;

	if (!*stack_from)
		return (1);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (!*stack_to)
	{
		tmp->last = tmp;
		*stack_to = tmp;
		(*stack_to)->last = *stack_to;
		(*stack_to)->next = NULL;
	}
	else
	{
		tmp->last = (*stack_to)->last;
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
	return (1);
}

int	swap(t_stack **stack_a, t_stack **stack_b, char name, int i)
{
	t_stack	*tmp;

	if ((name == 's' || name == 'a') && *stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		*stack_a = tmp;
		i += 1;
	}
	if ((name == 's' || name == 'b') && *stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		*stack_b = tmp;
		i += 2;
	}
	return (1);
}

int	rotate(t_stack **stack_a, t_stack **stack_b, char name, int i)
{
	t_stack	*tmp;

	if ((name == 'r' || name == 'a') && *stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		ft_stackadd_back(stack_a, tmp);
		i += 1;
	}
	if ((name == 'r' || name == 'b') && *stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		ft_stackadd_back(stack_b, tmp);
		i += 2;
	}
	return (1);
}

int	rev_r(t_stack **stack_a, t_stack **stack_b, char name, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((name == 'r' || name == 'a') && *stack_a && (*stack_a)->next)
	{
		tmp = ft_find_before_last(*stack_a);
		tmp2 = tmp->next;
		tmp->next = NULL;
		ft_set_last(stack_a, tmp);
		ft_stackadd_front(stack_a, tmp2);
		i += 1;
	}
	if ((name == 'r' || name == 'b') && *stack_b && (*stack_b)->next)
	{
		tmp = ft_find_before_last(*stack_b);
		tmp2 = tmp->next;
		tmp->next = NULL;
		ft_set_last(stack_b, tmp);
		ft_stackadd_front(stack_b, tmp2);
		i += 2;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
}
