/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:49:05 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 21:59:39 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_len(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	check_input(char *arg, t_stack **a, int size, int i)
{
	int		pre_size;

	while (arg[i])
	{
		pre_size = size;
		if ((arg[i] <= '9' && arg[i] >= '0')
			|| (arg[i] == '-' && ((arg[i + 1] <= '9' && arg[i + 1] >= '0')))
			|| (arg[i] == '+' && ((arg[i + 1] <= '9' && arg[i + 1] >= '0'))))
		{
			size += ft_stackadd_back(a, ft_new_node(ft_atoi(arg + i)));
			i += ft_find_len(arg + i);
			if (size == pre_size)
				return (0);
			else if (arg[i] != ' ' && arg[i] != '\0')
				return (0);
		}
		else if (arg[i] == ' ')
			i++;
		else
			return (0);
	}
	return (size);
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

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 1;
	while (i < ac)
	{
		if (!check_input(av[i], &a, 0, 0) || check_dups(a))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ac > 1 && !is_sorted(a))
		ft_sort(&a, &b, ft_stack_size(a));
	exit(0);
}
