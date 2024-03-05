/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:04:18 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/28 16:17:58 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

t_stack	*ft_find_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	if (!stack->next)
		return (NULL);
	return (stack);
}
