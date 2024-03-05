/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:18:00 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 15:34:54 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	parsing(int i, int ac, char **av, t_stack **a)
{
	while (i < ac)
	{
		if (!check_input(av[i++], a, 0, 0) || check_dups(*a))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
	}
}
