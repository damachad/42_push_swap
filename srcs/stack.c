/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:52:55 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 16:36:16 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*last_node(t_stack *top)
{
	while (top && top->next)
		top = top->next;
	return (top);
}

t_stack *second_last_node(t_stack *top)
{
	while (top && top->next && top->next->next)
		top = top->next;
	return (top);
}
