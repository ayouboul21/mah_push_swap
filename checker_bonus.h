/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:25:20 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/19 10:46:03 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*last;
	struct s_stack	*next;
}	t_stack;

int		push(t_stack **stack_to, t_stack **stack_from);
int		swap(t_stack **stack_a, t_stack **stack_b, char name, int i);
int		rotate(t_stack **stack_a, t_stack **stack_b, char name, int i);
int		rev_r(t_stack **stack_a, t_stack **stack_b, char name, int i);
int		is_sorted(t_stack *stack);
int		ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);
t_stack	*ft_new_node(long num);
int		ft_stack_size(t_stack *a);
void	ft_set_last(t_stack **stack, t_stack *last);
t_stack	*ft_find_before_last(t_stack *stack);
void	parsing(int i, int ac, char **av, t_stack **a);

#endif