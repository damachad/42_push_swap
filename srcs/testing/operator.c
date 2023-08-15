/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:32:05 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 15:59:17 by damachad         ###   ########.fr       */
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
		write(1, "rr", 1);
	write(1, &list, 1);
	write(1, "\n", 1);
}

void	do_op_2(void (*op)(t_stack**, t_stack**), t_stack **a, t_stack **b)
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
