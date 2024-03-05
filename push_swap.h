/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:58 by aoulahra          #+#    #+#             */
/*   Updated: 2024/01/20 17:34:52 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/printf/ft_printf.h"
# include "libs/libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				pvl;
	int				cost;
	struct s_stack	*last;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

int		ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *a);
int		check_dups(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	push(t_stack **stack_to, t_stack **stack_from, char name);
void	swap(t_stack **stack_a, t_stack **stack_b, char name, int i);
void	ft_set_last(t_stack **stack, t_stack *last);
void	rotate(t_stack **stack_a, t_stack **stack_b, char name, int i);
void	rev_rotate(t_stack **stack_a, t_stack **stack_b, char name, int i);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_sort(t_stack **a, t_stack **b, int size);
void	index_stack(t_stack *a);
void	get_min_to_top(t_stack **a);
void	find_targets(t_stack *a, t_stack *b);
void	fix_b(t_stack **b, int median, t_stack *cheapest);
void	ft_handle_target_a(t_stack **a, t_stack **b, int mid_av);
void	ft_handle_target_b(t_stack **a, t_stack **b);
void	set_pvl_stack(t_stack *a);
t_stack	*ft_new_node(long num);
t_stack	*ft_find_before_last(t_stack *stack);
t_stack	*find_max_min(t_stack *stack, char mode);
t_stack	*find_cheapest_node(t_stack *a, int size_a, int size_b);

#endif