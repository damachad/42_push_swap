/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:32:05 by damachad          #+#    #+#             */
/*   Updated: 2023/08/14 12:58:15 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	process_a(void (*operation)(t_stack**), t_stack **stack_a)
{
	if (!stack_a)
		return ;
	operation(stack_a);
	if (operation == swap)
		ft_printf("sa\n");
	else if (operation == rotate)
		ft_printf("ra\n");
	else if (operation == rev_rotate)
		ft_printf("rra\n");
}

void	process_b(void (*operation)(t_stack**), t_stack **stack_b)
{
	if (!stack_b)
		return ;
	operation(stack_b);
	if (operation == swap)
		ft_printf("sb\n");
	else if (operation == rotate)
		ft_printf("rb\n");
	else if (operation == rev_rotate)
		ft_printf("rrb\n");
}

void	process_c(void (*op)(t_stack**, t_stack**), t_stack **a, t_stack **b)
{
	op(a, b);
	if (op == push_to_a)
		ft_printf("pa\n");
	else if (op == push_to_a)
		ft_printf("pb\n");
	else if (op == ss)
		ft_printf("ss\n");
	else if (op == rr)
		ft_printf("rr\n");
	else if (op == rrr)
		ft_printf("rrr\n");
}
