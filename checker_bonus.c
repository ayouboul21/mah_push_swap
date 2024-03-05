/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:24:52 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/30 21:43:48 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	stock_ss(int i, char **c)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		(ft_strncmp(s, "pa\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "pb\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "sa\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "sb\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "ss\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "ra\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "rb\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "rr\n", 3) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "rra\n", 4) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "rrb\n", 4) == 0) && (i++, *c = ft_strjoin(*c, s));
		(ft_strncmp(s, "rrr\n", 4) == 0) && (i++, *c = ft_strjoin(*c, s));
		free(s);
		if (!i || !c)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		(1 == 1) && (i = 0, s = get_next_line(0));
	}
	return (1);
}

int	execute_ss(t_stack **a, t_stack **b, char *buffer)
{
	int		i;
	char	**ss;

	(1 == 1) && (ss = ft_split(buffer, '\n'), i = 0);
	if (!ss)
		return (0);
	while (ss[i])
	{
		(ft_strncmp(ss[i], "pa\0", 3) == 0) && (push(a, b));
		(ft_strncmp(ss[i], "pb\0", 3) == 0) && (push(b, a));
		(ft_strncmp(ss[i], "sa\0", 3) == 0) && (swap(a, b, 'a', 0));
		(ft_strncmp(ss[i], "sb\0", 3) == 0) && (swap(a, b, 'b', 0));
		(ft_strncmp(ss[i], "ss\0", 3) == 0) && (swap(a, b, 's', 0));
		(ft_strncmp(ss[i], "ra\0", 3) == 0) && (rotate(a, b, 'a', 0));
		(ft_strncmp(ss[i], "rb\0", 3) == 0) && (rotate(a, b, 'b', 0));
		(ft_strncmp(ss[i], "rr\0", 3) == 0) && (rotate(a, b, 'r', 0));
		(ft_strncmp(ss[i], "rra\0", 4) == 0) && (rev_r(a, b, 'a', 0));
		(ft_strncmp(ss[i], "rrb\0", 4) == 0) && (rev_r(a, b, 'b', 0));
		(ft_strncmp(ss[i], "rrr\0", 4) == 0) && (rev_r(a, b, 'r', 0));
		free(ss[i]);
		i++;
	}
	free(ss);
	return (1);
}

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	*buffer;

	(1 == 1) && (a = NULL, b = NULL, i = 1, buffer = ft_strdup(""));
	if (!buffer)
		exit(EXIT_FAILURE);
	parsing(i, ac, av, &a);
	if (ac > 1 && stock_ss(0, &buffer))
	{
		if (!execute_ss(&a, &b, buffer))
		{
			free_stack(&a);
			free_stack(&b);
			exit(EXIT_FAILURE);
		}
		(is_sorted(a) && !b) && (ft_printf("OK\n"));
		(!is_sorted(a) || b) && (ft_printf("KO\n"));
	}
	else
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
