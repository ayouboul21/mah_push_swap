/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:17:25 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/18 16:24:09 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	find_sign(size_t *i, int *sign, const char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

long	ft_atoi(char *str)
{
	size_t	i;
	int		res;
	int		pre;
	int		sign;

	i = 0;
	res = 0;
	pre = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	find_sign(&i, &sign, str);
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (res == 214748364 && str[i] == '8' && sign == -1)
			return (-2147483648);
		res = res * 10 + str[i] - '0';
		if (res / 10 != pre)
			return (2147483648);
		pre = res;
		i++;
	}
	return (res * sign);
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

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
