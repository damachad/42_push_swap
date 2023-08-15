/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:35:58 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 11:01:44 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	push_new_val(t_stack **top, int val)
{
	t_stack	*new_top;

	new_top = new_node(val);
	new_top->next = *top;
	*top = new_top;
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size == 2 && !is_sorted(*stack_a))
		process_a(swap, stack_a);
	else if (size == 3 && !is_sorted(*stack_a))
		sort_3(stack_a);
	if (!stack_b)
		stack_b = NULL;
}
