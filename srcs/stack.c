/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:52:55 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 11:02:37 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Checks if given stack is sorted

bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Returns the last node of a linked list

t_stack	*last_node(t_stack *top)
{
	while (top && top->next)
		top = top->next;
	return (top);
}

// Returns the second last node of a linked list

t_stack	*second_last_node(t_stack *top)
{
	while (top && top->next && top->next->next)
		top = top->next;
	return (top);
}

// Returns how many nodes are present on a linked list

size_t	stack_size(t_stack *top)
{
	size_t	size;

	if (!top)
		return (0);
	size = 0;
	while (top)
	{
		top = top->next;
		size++;
	}
	return (size);
}

// Returns the node with the lowest value

t_stack	*lowest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->val < smallest->val)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
