/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:15:05 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 17:29:51 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operation(void(*funct)(t_stack**), t_stack **stack_a, t_stack **stack_b)
{
	funct(stack_a);
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_print("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_print("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_print("ss\n");
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_print("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_print("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_print("rr\n");
}
