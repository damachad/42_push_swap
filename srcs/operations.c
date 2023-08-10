/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:23:33 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 15:00:33 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	push(t_stack **top, int data)
{
	t_stack	*new_top;

	new_top = new_node(data);
	new_top->next = *top;
	*top = new_top;
}

bool	is_sorted(t_stack *stack)
{
	while(stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}
