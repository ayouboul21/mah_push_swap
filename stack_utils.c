/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:00 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 21:08:34 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_set_last(t_stack **stack, t_stack *last)
{
	t_stack	*tmp;

	if (!stack || *stack == NULL || !last)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp->last = last;
		tmp = tmp->next;
	}
}

t_stack	*ft_new_node(long num)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node || num == 2147483648)
	{
		if (node && num == 2147483648)
			free(node);
		return (NULL);
	}
	node->num = num;
	node->next = NULL;
	return (node);
}

int	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!new)
		return (0);
	else if (stack && !(*stack))
	{
		*stack = new;
		new->next = NULL;
		new->last = new;
		return (1);
	}
	else if (stack)
	{
		tmp = tmp->last;
		tmp->next = new;
		ft_set_last(stack, new);
		return (1);
	}
	else
		return (0);
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
