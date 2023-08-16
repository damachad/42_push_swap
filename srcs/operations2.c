/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:15:05 by damachad          #+#    #+#             */
/*   Updated: 2023/08/16 15:52:21 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_op(void (*operation)(t_stack**), t_stack **stack_a, char list)
{
	if (!stack_a)
		return ;
	operation(stack_a);
	if (operation == swap)
		write(1, "s", 1);
	else if (operation == rotate)
		write(1, "r", 1);
	else if (operation == rev_rotate)
		write(1, "rr", 2);
	write(1, &list, 1);
	write(1, "\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
